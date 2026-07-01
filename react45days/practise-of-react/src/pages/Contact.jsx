import { useNavigate } from "react-router-dom";
function Contact(){
    const navigate = useNavigate();
    return(
        <>
        <h1>This is Contact Page</h1>
        <button onClick={() => navigate(-1)}>Back</button><br></br><br></br>
        </>
    );
} 

export default Contact;