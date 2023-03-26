import React from "react";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import Graph from './Graph'

function Card(props) {

    const navigate = useNavigate();
    
    const handleClick = async () => {
        console.log(props.id);
        if(localStorage.getItem("user"))
        {   
            const user = await JSON.parse(localStorage.getItem("user"));
            let token = user.token;
            let response = await axios.get('https://pbl2022-project-backend.herokuapp.com/investor/me', {
                headers : {
                    Authorization: `Bearer ${token}`
                }
            })
            let presentCoins = response.data.coins;
            let enteredCoins = prompt("Enter Coins for Investment : ", 0);
            if(enteredCoins > props.askprice){
                alert("Entered Coins are greater than Asking Price.")
            }
            else if(enteredCoins > presentCoins){
                alert("Insufficient Balance")
            }
            else if(0 >= enteredCoins){
                alert("Enter a valid number of coins.")
            }
            else {
                let body = {
                    project_id: props.id,
                    amount: parseInt(enteredCoins)
                }
                response = await axios.post('https://pbl2022-project-backend.herokuapp.com/investor/invest', body, {
                    headers: {
                        "Content-Type": "application/json",
                        Authorization: `Bearer ${token}`,
                    }
                });
                console.log(response);
                if(response.status === 200){
                    alert("Invested Sucessfully.");
                }
                else{
                    alert("Error while performing transaction.");
                }
            }
        }
        else{
            alert("Please Login as Investor")
            navigate('/login');
        }
    }

    return (
        <div className="card">
            <h4 className="card-title">{props.name}</h4>
            <p className="card-text">{props.description}</p>
            <div className="card-body">
                <div className="card-details">
                    <p className="card-text">Ask : {props.askprice}</p>
                    <p className="card-text">Equity : {props.equity.toFixed(2)}%</p>
                    <p className="card-text">Sector : {props.sector}</p>
                    {props.investorsNostatus ? (<p className="card-text">Investors : {props.investorNo}</p>) : (<></>)}
                    {props.buttonstatus ? (<div className="button-container">
                        <button className="btn btn-primary button" onClick={handleClick}>Invest</button>
                    </div>) : (<div></div>)}
                </div>
                <div className="chart-container">
                    <Graph equity={props.equity}/>
                    {props.ownernamestatus ? (<p className="card-text"> ~ {props.ownername}</p>) : (<></>)}
                </div>
            </div>
        </div>
    );
}

export default Card;