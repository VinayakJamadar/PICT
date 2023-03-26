import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import Layout from "../Components/Layout";
import axios from "axios";

function Login() {

    const navigate = useNavigate();

    const [credentials, setCredentials] = useState({
        email: "", password: "", usertype: "entrepreneur"
    });

    const [isValid, setisValid] = useState(true);

    const onChangehandle = (e) => {
        const name = e.target.name;
        const value = e.target.value;

        setCredentials({ ...credentials, [name]: value });
    }

    function Invalid() {
        if (!isValid) {
            return (
                <p id="invalid-user">
                    Incorrect Username or Password.
                </p>
            );
        }
    }

    const submitData = async (e) => {
        e.preventDefault();
        const body = {
            email: credentials.email,
            password: credentials.password
        }
        const result = await axios.post(`https://pbl2022-project-backend.herokuapp.com/${credentials.usertype}/login`, body);

        if(result.status === 200){
            let user = {
                token: result.data.token, 
                usertype: credentials.usertype
            };
            console.log(user);
            localStorage.setItem("user", JSON.stringify(user));
            navigate("/");
        }
        else{
            setisValid(false);
        }
    }

    return (
        <Layout>
            <div id="login_container" className="container">
                <form id="login_form">
                    <h3 id="login_heading">Login</h3>
                    <hr className="login_hr" />

                    <label className="login_label" htmlFor="email">
                        Email Address
                    </label>
                    <input
                        className="login_input"
                        type="email"
                        name="email"
                        id="email"
                        placeholder="Enter Email"
                        onChange={onChangehandle}
                    />

                    <label className="login_label" htmlFor="password">
                        Password
                    </label>
                    <input
                        className="login_input"
                        type="password"
                        name="password"
                        id="password"
                        minLength="7"
                        placeholder="Enter Password"
                        onChange={onChangehandle}
                    />

                    <div className="login_user" onChange={onChangehandle}>
                        <input
                            className="login_user_choice"
                            type="radio"
                            id="entrepreneur"
                            name="usertype"
                            defaultChecked="checked"
                            value="entrepreneur"
                        />
                        <label className="login_label" htmlFor="entrepreneur">
                            Entrepreneur
                        </label>

                        <input
                            className="login_user_choice"
                            type="radio"
                            id="investor"
                            name="usertype"
                            value="investor"
                        />
                        <label className="login_label" htmlFor="investor">
                            Investor
                        </label>
                    </div>

                    <Invalid />
                    <button type="submit" className="btn btn-primary btn-block login_buttons" onClick={submitData}>Login</button>
                </form>
            </div>
        </Layout>
    );
}
export default Login;
