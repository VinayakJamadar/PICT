import React from "react";
import Layout from "../Components/Layout";
import Title from "./Title";
import Process from "./Process";
import Benefits from "./Benefits";
import Team from "./Team";
import Footer from "./Footer";

function Home() {
    return (
        <Layout>
            <Title />
            <hr className="home_hr"/>
            <Process />
            <hr className="home_hr hr_margin"/>
            <Benefits />
            <hr className="home_hr hr_margin_top"/>
            <Team />
            <Footer />
        </Layout>
    );
}
export default Home;