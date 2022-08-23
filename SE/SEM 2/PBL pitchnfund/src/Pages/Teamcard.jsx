import React from "react";

function Teamcard(props) {

    return (
        <div className="card">
            <div className="card-image">
                <img src={props.image} alt="Profile" />
            </div>
            <p className="name">{props.name}</p>
            <p>{props.role}</p>
            <div className="socials">
                <a href={props.git} target="_blank" rel="noreferrer" className="github"><i className="fab fa-github"></i></a>
                <a href={props.linkedin} target="_blank" rel="noreferrer" className="twitter"><i className="fab fa-linkedin"></i></a>
                <a href={props.email} target="_blank" rel="noreferrer" className="pinterest"><i className="fa-solid fa-envelope"></i></a>
            </div>
        </div>
    );
}

export default Teamcard;