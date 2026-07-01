import {Link} from "react-router-dom";
function Navbar(){
    return(
        <>
        <h1>This is an navbar page</h1>
        <Link to ="/">Home</Link><br></br>
        <Link to ="/about">About</Link><br></br>
        <Link to ="/contact">Contact</Link>
        </>
    );
}

export default Navbar;