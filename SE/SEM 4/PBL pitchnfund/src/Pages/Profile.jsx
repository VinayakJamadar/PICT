import React, {useState, useEffect} from "react";
import axios from "axios";
import Layout from "../Components/Layout";

function Profile() {

    const [data , setData] = useState([]);
    useEffect(()=>{
        const user = JSON.parse(localStorage.getItem("user"));
        let usertype = user.usertype;
        let token = user.token;
        axios.get(`https://pbl2022-project-backend.herokuapp.com/${usertype}/me`, {
            headers: {
                "Content-Type": "application/json",
                Authorization: `Bearer ${token}`
            }
        })
        .then(response => {
            response.data.usertype = usertype.toUpperCase();
            setData(response.data)
        })
        .catch(error=>console(error));
    } , []);

    console.log(data);

    return (
        <Layout>
            <div id="profile">
                <div className="profile-container">
                    <h1 className="profile-heading">
                        &nbsp;
                        <i className="fa-solid fa-user"> &nbsp;</i> {data.usertype} PROFILE
                    </h1>
                    <hr className="profile-rule" />
                    <h5 className="profile-label"> Name</h5>
                    <h4 className="profile-displaylabel"> {data.name}</h4>
                    <h5 className="profile-label"> Email Address</h5>
                    <h4 className="profile-displaylabel"> {data.email}</h4>
                    <h5 className="profile-label"> Contact Number</h5>
                    <h4 className="profile-displaylabel"> {data.phone}</h4>
                    <h5 className="profile-label"> Coin Balance</h5>
                    <h4 className="profile-displaylabel"> {data.coins}</h4>
                </div>
            </div>
        </Layout>
    )
}

export default Profile;
