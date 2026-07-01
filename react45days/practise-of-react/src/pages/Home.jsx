import { useNavigate } from "react-router-dom";
function Home(){
    const navigate = useNavigate();
    return(
        <>
        <h1>This is Home Page</h1>
        <button onClick={() => navigate ("/about")}>Go to About Page</button><br></br><br></br>
        <button onClick={() => navigate ("/contact")}>Go to Contact Page</button><br></br><br></br>
        <button onClick={() => navigate(-1)}>Back</button>
        </>
    );
} 

export default Home;