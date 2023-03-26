import React, { useState, useEffect } from "react";
import axios from "axios";
import Layout from "../Components/Layout";

function Coin() {

    const [data, setData] = useState({});
    const [input, setInput] = useState({buy: 0, sell: 0});

    const onChangehandle = (e) => {
        const name = e.target.name;
        const value = e.target.value;

        setInput({...input, [name]:parseInt(value)})
    }

    const handleClick = (e) => {
        let buttonName = e.target.name;
        if(input[buttonName] === 0){
            alert(`Enter Coins greater than 0.`);
        }
        else{
            const body = {
                coins: parseInt(input[buttonName])
            }
            axios.post(`https://pbl2022-project-backend.herokuapp.com/coins/${data.usertype}/${buttonName}`, body, {
                headers: {
                    "Content-Type": "application/json",
                    Authorization: `Bearer ${data.token}`
                }
            });
            
            if(buttonName === "buy"){
                setData({...data, coins: (data.coins+parseInt(input[buttonName]))})
                alert("Coins Credited Successfully");
                document.getElementById("buyInput").value = null;
                setInput({...input, buy: 0});
            }
            else{
                setData({...data, coins: (data.coins-parseInt(input[buttonName]))})
                alert("Coins Debited Successfully");
                document.getElementById("sellInput").value = null;
                setInput({...input, sell: 0});
            }
        }
    }

    useEffect(() => {
        const user = JSON.parse(localStorage.getItem("user"));
        let usertype = user.usertype;
        let token = user.token;
        axios.get(`https://pbl2022-project-backend.herokuapp.com/coins/${usertype}/balance`, {
            headers: {
                "Content-Type": "application/json",
                Authorization: `Bearer ${token}`
            }
        })
            .then(response => {
                response.data.usertype = usertype;
                response.data.token = token;
                setData(response.data)
            })
            .catch(error => alert("There is Some Error."));
    }, []);

    return (
        <Layout>
            <div id="Coins-container">
                <div id="Coins-portal">
                    <h2 className="Coins-form-heading">Coins portal      <i className="fa-solid fa-coins coin-icon"></i> </h2>
                    <hr className="Coins-hr" />

                    <br />
                    <label className="Coins-form-labels"> Coin Balance</label>
                    <h5 className="Coins-balance">{data.coins}</h5>
                    <br />
                    <input id="buyInput" className="Coins-form-input" name="buy" type="number" onChange={onChangehandle} placeholder={0}></input>
                    <button className="btn btn-primary" name="buy" onClick={handleClick}>Buy</button>
                    <br />
                    <input id="sellInput" className="Coins-form-input" name="sell" type="number" onChange={onChangehandle} placeholder={0}></input>
                    <button className="btn btn-primary" name="sell" onClick={handleClick}>Sell</button>
                </div>
            </div>
        </Layout>
    )
}

export default Coin;
