import React, { useState } from "react";
import axios from "axios";
import Layout from "../Components/Layout";

function Addprojects() {

    const [data, setData] = useState({
        name: "", askingPrice: "", equity: "", description: ""
    });

    let name, value;

    const onChangehandle = (e) => {
        name = e.target.name;
        value = e.target.value;

        setData({ ...data, [name]: value });
    }

    const submitData = async (e) => {
        e.preventDefault();
        const user = JSON.parse(localStorage.getItem("user"));
        let token = user.token;
        const body = {
            name: data.name,
            askingPrice: parseInt(data.askingPrice),
            equity: parseInt(data.equity)/100,
            description: data.description
        }
        await axios.post('https://pbl2022-project-backend.herokuapp.com/projects', body, {
            headers: {
                'Content-Type': 'application/json',
                Authorization: `Bearer ${token}`
            }
        });

        setData({});
        const list = document.getElementsByTagName("input");
        for (let i = 0; i < list.length; i++) {
            list[i].value = null;
        }
        document.getElementsByTagName("textarea")[0].value = null;
    }

    return (
        <Layout>
            <div id="Addprojects-container">
                <form id="Addprojects-form">
                    <h1 className="Addprojects-form-heading">Business Pitch</h1>
                    <label className="Addprojects-form-labels" htmlFor="name">Pitch Title </label><br />
                    <input className="Addprojects-title-input" id="name" name="name" type="text" placeholder="Enter Title" onChange={onChangehandle}></input><br />
                    <label className="Addprojects-form-labels" htmlFor="askingPrice">Ask</label><br />
                    <input className="Addprojects-input" id="askingPrice" name="askingPrice" type="number" placeholder="Enter Ask in Rs." onChange={onChangehandle}></input><br />
                    <label className="Addprojects-form-labels" htmlFor="equity">Equity</label><br />
                    <input className="Addprojects-input" id="equity" name="equity" type="number" placeholder="Enter Equity in %" onChange={onChangehandle} min="0" max="100"></input><br />
                    <label className="Addprojects-form-labels" htmlFor="description">Description</label><br />
                    <textarea className="Addprojects-description" id="description" name="description" form="Addprojects-form" placeholder="Enter Description of your startup" onChange={onChangehandle}></textarea><br />
                    <button type="button" className="btn Addprojects-btn" onClick={submitData}>Launch pitch to marketplace</button>
                </form>
            </div>
        </Layout>
    );
}

export default Addprojects;