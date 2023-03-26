import "./Assets/Styles/App.css";
import "./Assets/Styles/Login.css";
import "./Assets/Styles/Signup.css";
import "./Assets/Styles/Profile.css"
import "./Assets/Styles/Addprojects.css"
import "./Assets/Styles/Card.css"
import "./Assets/Styles/Coin.css"
import { Routes, Route } from "react-router-dom";
import { Home, Login, Signup, Profile, Coin, Marketplace, Myinvestment, Addprojects, Myprojects} from "./Pages";

export default function App() {
  return (
    <div className="container-fluid">
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/login" element={<Login />} />
        <Route path="/signup" element={<Signup />} />
        <Route path="/profile" element={<Profile />} />
        <Route path="/coin" element={<Coin />} />
        <Route path="/marketplace" element={<Marketplace />} />
        <Route path="/myinvestment" element={<Myinvestment />} />
        <Route path="/addprojects" element={<Addprojects />} />
        <Route path="/myprojects" element={<Myprojects />} />
      </Routes>
    </div>
  );
}
