import React from "react";
import { Link, useNavigate } from "react-router-dom";
import Hamburger from "../Assets/Images/Hamburger.svg";
import Logo from "../Assets/Images/Logo.png";

function Header() {

    let usertype = undefined;
    if(localStorage.getItem("user"))
    {   
        const user= JSON.parse(localStorage.getItem("user"));
        // console.log(user);
        usertype = user.usertype;
        // console.log(usertype);
    }

    const navigate = useNavigate();
    const handleLogout = () => {
        localStorage.clear();
        navigate('/');
    }

    return (
        <header id="homepage-header">
            <nav className="navbar navbar-expand-lg">
                <div id="homepage-container">
                    <div id="homepage_brand">
                        <img src={Logo} alt="" id="homepage_logo"/>
                        <Link to="/" className="navbar-brand">pitch&amp;fund</Link>
                    </div>
                    <button className="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                        <img src={Hamburger} alt="" />
                    </button>
                    <div className="collapse navbar-collapse" id="navbarNav">
                        <div id="hamburger" className="navbar-nav">
                            {usertype ? ((usertype === "entrepreneur") ? <>
                                    <Link to="/profile">Profile</Link>
                                    <Link to="/addprojects">Add Project</Link>
                                    <Link to="/myprojects">My Projects</Link>
                                    <Link to="/coin">Coin</Link>
                                    <Link to="/" onClick={handleLogout}>Logout</Link>
                                </> : <>
                                    <Link to="/profile">Profile</Link>
                                    <Link to="/marketplace">Marketplace</Link>
                                    <Link to="/myinvestment">My Investments</Link>
                                    <Link to="/coin">Coin</Link>
                                    <Link to="/" onClick={handleLogout}>Logout</Link>
                                </>) : <>
                                    <Link to="/marketplace">Explore Marketplace</Link>
                                    <Link to="/login">Login</Link>
                                    <Link to="/signup">Sign Up</Link>
                                </>
                            }
                        </div>
                    </div>
                </div>
            </nav>
        </header>
    );
}

export default Header;