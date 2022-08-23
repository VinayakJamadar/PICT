import axios from 'axios'
import React, { useState, useEffect } from 'react'
import Layout from "../Components/Layout";
import Card from "./Card";

const Myprojects = () => {

    const [data, setData] = useState([]);

    const fetchData = async () => {
        try {
            const user = await JSON.parse(localStorage.getItem("user"));
            const token = user.token;
            const res = await axios.get("https://pbl2022-project-backend.herokuapp.com/entrepreneur/invested_details", {
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

    console.log(data);

    return (
        <Layout>
            <section id="cardsSection">
                {data ? data.map((element, key) => <Card key={key} id={element._id} name={element.name} description={element.description} askprice={element.askingPrice} equity={(element.equity) * 100} sector={element.sector} investorNo={element.investorDetails.length} investorsNostatus={1}/>) : alert("No Project")}
            </section>
        </Layout>
    )
}

export default Myprojects;