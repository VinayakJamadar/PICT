import React from "react";

function Footer() {
    return (
        <footer>
            <p className="quote-icon">
                <i className="fa-solid fa-quote-left quote-symbol"></i>
            </p>
            <div className="quote">
                <p className="quote-heading">What do you need to start a business? </p>
                <p className="quote-line">Three simple things: know your product better than anyone,  </p>
                <p className="quote-line">know your customer, and have a burning desire to succeed.</p>
            </div>
            <h6>
                –Dave Thomas, Founder, Wendy’s
            </h6>
        </footer>
    );
}

export default Footer;