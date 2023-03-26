import React from "react";
import "react-vertical-timeline-component/style.min.css";

function Process() {
    return (
        <section id="process">
            <h2 className="process-heading">How it works?</h2>
            <div id="timeline-element" className="vertical-timeline vertical-timeline--animate vertical-timeline--two-columns">
                <div className="vertical-timeline-element--work vertical-timeline-element">
                    <span id="timeline-element-icon" className="vertical-timeline-element-icon bounce-in" style={{ background: '#21326b', color: 'white' }}></span>
                    <div id="timeline-element-content" className="vertical-timeline-element-content bounce-in" style={{ background: '#21326b', color: 'white' }}>
                        <div id="timeline-element-content-arrow" className="vertical-timeline-element-content-arrow" style={{ borderRight: '7px solid #21326b' }}></div>
                        <h3 id="timeline-element-title" className="vertical-timeline-element-title">As an Investor</h3>
                        <h4 id="timeline-element-subtitle" className="vertical-timeline-element-subtitle">Browse and explore numerous startups and ventures of all domains from our marketplace .</h4>
                        <span id="investor-step" className="vertical-timeline-element-date">Step 1</span>
                    </div>
                </div>
                <div id="timeline-element" className="vertical-timeline-element--work vertical-timeline-element">
                    <span id="timeline-element-icon" className="vertical-timeline-element-icon bounce-in" style={{ background: '#21326b', color: 'white' }}></span>
                    <div id="timeline-element-content" className="vertical-timeline-element-content bounce-in" style={{ background: '#21326b', color: 'white' }}>
                        <div id="timeline-element-content-arrow" className="vertical-timeline-element-content-arrow" style={{ borderRight: '7px solid #21326b' }}></div>
                        <h4 id="timeline-element-subtitle" className="vertical-timeline-element-subtitle">Loved a product and its business pitch? Sign up to join us.</h4>
                        <span id="investor-step" className="vertical-timeline-element-date">Step 2</span>
                    </div>
                </div>
                <div id="timeline-element" className="vertical-timeline-element--work vertical-timeline-element">
                    <span id="timeline-element-icon" className="vertical-timeline-element-icon bounce-in" style={{ background: '#21326b', color: 'white' }}></span>
                    <div id="timeline-element-content" className="vertical-timeline-element-content bounce-in" style={{ background: '#21326b', color: 'white' }}>
                        <div id="timeline-element-content-arrow" className="vertical-timeline-element-content-arrow" style={{ borderRight: '7px solid #21326b' }}></div>
                        <h4 id="timeline-element-subtitle" className="vertical-timeline-element-subtitle">Create your profile and start investing!</h4>
                        <span id="investor-step" className="vertical-timeline-element-date">Step 3</span>
                    </div>
                </div>
                <div id="timeline-element" className="vertical-timeline-element--work vertical-timeline-element">
                    <span id="timeline-element-icon" className="vertical-timeline-element-icon bounce-in" style={{ background: '#21326b', color: 'white' }}></span>
                    <div id="timeline-element-content" className="vertical-timeline-element-content bounce-in" style={{ background: '#21326b', color: 'white' }}>
                        <div id="timeline-element-content-arrow" className="vertical-timeline-element-content-arrow" style={{ borderRight: '7px solid #21326b' }}></div>
                        <h4 id="timeline-element-subtitle" className="vertical-timeline-element-subtitle">Buy coins and redeem them for funding interesting startups.</h4>
                        <span id="investor-step" className="vertical-timeline-element-date">Step 4</span>
                    </div>
                </div>
                <div id="timeline-element" className="vertical-timeline-element--education vertical-timeline-element">
                    <span id="timeline-element-icon" className="vertical-timeline-element-icon bounce-in" style={{ background: '#ffa900', color: 'white' }}></span>
                    <div id="timeline-element-content" className="vertical-timeline-element-content bounce-in" style={{ background: '#ffa900', color: 'white' }}>
                        <div id="timeline-element-content-arrow" className="vertical-timeline-element-content-arrow" style={{ borderRight: '7px solid #ffa900' }}></div>
                        <h3 id="timeline-element-title" className="vertical-timeline-element-title">As an Entrepreneur</h3>
                        <h4 id="timeline-element-subtitle" className="vertical-timeline-element-subtitle">Sign up to join us and build your startup portfolio.</h4>
                        <span id="entrepreneur-step" className="vertical-timeline-element-date">Step 1</span>
                    </div>
                </div>
                <div id="timeline-element" className="vertical-timeline-element--education vertical-timeline-element">
                    <span id="timeline-element-icon" className="vertical-timeline-element-icon bounce-in" style={{ background: '#ffa900', color: 'white' }}></span>
                    <div id="timeline-element-content" className="vertical-timeline-element-content bounce-in" style={{ background: '#ffa900', color: 'white' }}>
                        <div id="timeline-element-content-arrow" className="vertical-timeline-element-content-arrow" style={{ borderRight: '7px solid #ffa900' }}></div>
                        <h4 id="timeline-element-subtitle" className="vertical-timeline-element-subtitle">View the funds raised for your business pitches from investors all over the world!</h4>
                        <span id="entrepreneur-step" className="vertical-timeline-element-date">Step 2</span>
                    </div>
                </div>
            </div>
        </section>
    );
}

export default Process;