import React from "react";

function Benefits() {
    return (
        <section id="benefits">
            <h2 className="benefit-heading">Why us?</h2>
            <div className="benefit-container">
                <div className="col-lg-3 col-md-6 benefit-box">
                    <i className="fa-solid fa-earth-americas benefit-icon"></i>
                    <h3 className="benefit-subheading">Diverse product portfolios.</h3>
                    <p className="benefit-p">Build your investor profile by financing all categories and expertise businesses around the world.</p>
                </div>
                <div className="col-lg-3 col-md-6 benefit-box">
                    <i className="fa-solid fa-hand-holding-dollar benefit-icon"></i>
                    <h3 className="benefit-subheading">Grow<br/> Revenue</h3>
                    <p className="benefit-p">Raise capital by pitching your business models and gain control over company valuation by equity funding.</p>
                </div>
                <div className="col-lg-3 col-md-6 benefit-box">
                    <i className="fa-solid fa-users benefit-icon"></i>
                    <h3 className="benefit-subheading">Co-invest and build network.</h3>
                    <p className="benefit-p">With multiple investors, strengthen your marketing campaign and business community relationships.</p>
                </div>
                <div className="col-lg-3 col-md-6 benefit-box">
                    <i className="fa-solid fa-circle-check benefit-icon"></i>
                    <h3 className="benefit-subheading">Easy and<br/> efficient</h3>
                    <p className="benefit-p">Join us for an easy and convenient business fundraising and investing workflow.</p>
                </div>
            </div>
        </section>
    );
}

export default Benefits;