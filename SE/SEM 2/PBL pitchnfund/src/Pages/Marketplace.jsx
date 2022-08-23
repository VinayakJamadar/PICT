import React , {useState , useEffect} from "react";
import axios from "axios";
import Layout from "../Components/Layout";
import Card from "./Card";

function Marketplace() {

    const [data , setData] = useState([]);

    useEffect(()=>{
        axios.get("https://pbl2022-project-backend.herokuapp.com/projects")
        .then(response => setData(response.data))
        .catch(error=>console(error));
    } , []);

    return (
        <Layout>
            <section id="cardsSection">
                {data ? data.map((element, key) => <Card key={key} id={element._id} name={element.name} description={element.description} askprice={element.askingPrice} equity={(element.equity)*100} sector={element.sector} ownername={element.ownerName} buttonstatus={1} ownernamestatus={1}/>): alert("No Projects")}
            </section>
        </Layout>
    );
}

export default Marketplace;