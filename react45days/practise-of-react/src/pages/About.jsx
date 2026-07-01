import { useNavigate } from "react-router-dom";
function About(){
    const navigate = useNavigate();
    return(
        <>
        <h1>This is About Page</h1>
        <button onClick={() => navigate ("/contact")}>Go to Contact Page</button><br></br><br></br>
        <button onClick={() => navigate(-1)}>Back</button><br></br><br></br>
        </>
    );
} 

export default About;