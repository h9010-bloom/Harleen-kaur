import { useRef } from "react";
function Form(){
    const nameRef = useRef(null);
    const emailRef = useRef(null);
    const passwordRef = useRef(null);

    function handleSubmit(e){
        e.preventDefault();
        alert(`Name: ${nameRef.current.value} 
            \nEmail: ${emailRef.current.value} 
            \nPassword: ${passwordRef.current.value}`)

            nameRef.current.value = "";
            emailRef.current.value = "";
            passwordRef.current.value = "";
    }
    return(
        <>
        <form onSubmit={handleSubmit}>
            <h1>Name: </h1>
            <input type="text" placeholder="Enter your name" ref={nameRef} ></input><br/>
            <h1>Email: </h1>
            <input type="email" placeholder="Enter your email" ref={emailRef} ></input><br/>
            <h1>Password: </h1>
            <input type="password" placeholder="Enter your password" ref={passwordRef} ></input><br/><br/>
            <button type="submit">Submit</button>
        </form>
        </>
    );
}
export default Form;