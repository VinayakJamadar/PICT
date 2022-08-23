import axios from 'axios'
import React, { useState, useEffect } from 'react'
import Layout from "../Components/Layout";
import Card from "./Card";

const Myinvestment = () => {

    const [data, setData] = useState([]);

    const fetchData = async () => {
        try {
            const user = await JSON.parse(localStorage.getItem("user"));
            const token = user.token;
            const res = await axios.get("https://pbl2022-project-backend.herokuapp.com/investor/investments", {
                headers: {
                    "Content-Type": "application/json",
                    Authorization: `Bearer ${token}`
                }
            })
            setData(res.data)
        } catch (error) {
            alert("Error while fetching data from backend.")
        }
    }
    useEffect(() => {
        fetchData()
    }, [])
    return (
        <Layout>
            <section id="cardsSection">
                {data ? data.map((element, key) => <Card key={key} id={element.project._id} name={element.project.name} description={element.project.description} askprice={element.amount} equity={(element.equity) * 100} sector={element.project.sector} ownername={element.project.ownerName} ownernamestatus={1}/>) : alert("No Project")}
            </section>
        </Layout>
    )
}

export default Myinvestment;