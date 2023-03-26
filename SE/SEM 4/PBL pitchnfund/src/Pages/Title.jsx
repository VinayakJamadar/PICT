import React from "react";
import Business from "../Assets/Images/Business.png";

function Title() {

    return (
        <section id="title" className="row">
            <div className="col-lg-5 col-md-6 col-sm-12 col-12" id="image-container">
                <img
                    className="title-image"
                    src={Business}
                    alt="business illustration"
                />
            </div>
            <div className="col-lg-7 col-md-6 col-sm-12 col-12 title-text">
                <h1 className="heading">Invest in startups worldwide.</h1>
                <h3 className="sub-heading">Investing for tomorrow has never been easier.</h3>
                <ul className="features-list">
                    <li>Empowering founders to raise capital and thrive</li>
                    <li>Acknowledging every business potential</li>
                    <li>Reshaping business fundraising</li>
                </ul>
                <a
                    type="button"
                    className="btn btn-dark btn-lg download-button"
                    href="https://drive.google.com/file/d/1Ep-XNppGJ9UbftToELL7ATY1NN9uYwLi/view?usp=sharing"
                    target="_blank" 
                    rel="noreferrer"
                >
                    <i className="fa-brands fa-google-play"></i> Download App
                </a>
            </div>
        </section>
    );
}

export default Title;