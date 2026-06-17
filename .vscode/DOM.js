// Document.getElementById("head")
// Document.getElementByClassname("btn")
// Document.getElementBytagname("h1")

// Document.querySelector("#head")
// Document.querySelector(".btn")
// Document.querySelector("h1")

// Document.querySelectorAll("h1")

function Changetext(){
    let heading = document.querySelector("#head");
    heading.innerText = "WELCOME";
}

let count = 0;
    function increement(){
        count++;
        let text = document.querySelector("#count");
        text.innerText = count;
    }
    function decreement(){
        count--;
        let text = document.querySelector("#count");
        text.innerText = count;
    }
    function reset(){
        count = 0;
        let text = document.querySelector("#count");
        text.innerText = count;
    }

let color = true;
function ChangeTheme(){
    let text = document.getElementById("change");
    if(color == true){
        document.body.style.backgroundColor = "white";
        text.style.color = "black";
        color = false;
    }
    else{
        document.body.style.backgroundColor = "black";
        text.style.color = "white";
        color = true;
    }
}

function toggle(){
    let pass = document.querySelector("#pass");
    if (pass.type == 'text'){
        pass.type = "password";
    }
    else{
        pass.type = "text";
    }
}

function submitt(){
    let input = document.getElementById("username").value;
    let heading = document.getElementById("greet");
    heading.innerText ="WElCOME " + input ;
}

function submitt1(){
    let age = document.getElementById("age").value;
    let result = document.getElementById("result");
    result.innerText = "Your age is: " + age ;
}
