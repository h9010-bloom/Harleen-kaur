import { useContext } from "react";
import UserContext from "../context/UserContext";
function Home(){
    const { name, age, email } = useContext(UserContext);
    return(
        <>
        <h1>Name is {name}</h1>
        <h1>Age is {age}</h1>
        <h1>Email is {email}</h1>
        </>
    );
}

export default  Home;