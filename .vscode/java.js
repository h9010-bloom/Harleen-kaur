//Javascript is intrepreter language not compliler language.
// Intreperter execute the program in line by line.

// example of external javascript
console.log("\n")
console.log("welcome to external javascript");


//variables of javacript
console.log("\n")
let name1="Divya";   // mostly use for strings
console.log(name);
console.log("\n")
const pi=3.14;   //value can't change after access
console.log(pi);
console.log("\n")
var age=19;   //mostly use for numbers
console.log(age);

//datatypes of javascript, This is a Primitive datatypes
//1. string: we can use let, const, var to declare any datatype.
//but var is an older way so we mostly use let and const is used when value shouldn't change.
console.log("\n")
let city="Mohali";
let state='PUNJAB';
console.log(typeof city);
console.log(typeof state);

//2. number:
var num=65;
console.log(typeof num);

//3. boolean:
console.log("\n")
let boolean=true;
console.log(typeof boolean);

//4. undefined:
console.log("\n")
let country;
console.log(typeof country); 

//5. null:
console.log("\n")
let school=null;
console.log(school);

//examples:
console.log("\n")
console.log('Hi I am ' , name , '. ' , '\n' ,'I am Computer Engineering student. ')

//OPERATORS: It is used to perform the mathematical calculations.
//Types of operators:
//1. Airthmetic operators:
console.log("\n")
console.log("Airthmetic operators:")
let a=12;
let b=15;
console.log("Addition:",a+b);
console.log("Subtraction:",a-b);
console.log("Multiplication:",a*b);
console.log("Division:",a/b);
console.log("Modulus:",a%b);

//2. Assignment Operators:
console.log("\n")
console.log("Assignment Operators:")
let c =+ 10;
let d =- 20;
console.log("Assignment Addition operator: ", c);
console.log("Assignment Subtraction operator:", d)

//3. Comparison Operator:
console.log("\n")
console.log("Comparison Operator:")
let e = 5;
let f ='5';
console.log("Double equalto: ", e == f); // gives output without check values datatyoe so the output will be: True
console.log("Triple equalto: ", e === f); //gives output with check values iof datatypes so the output will be: False
console.log("less than operator: ", e < f);
console.log("greator than operator:", e > f);
console.log("less than equalto operator: ", e <= f);
console.log("greator than equalto operator:", e >= f);
console.log("Not equalto operator: ",e != f);

//4. Logical operators:
console.log("\n")
console.log("Logical operators:")
let age1 = 20;
console.log("AND Logical operator: ",age1 > 5 && age1 > 30);
console.log("OR logical operator: ",age1 > 5 || age1 > 30);

//5. Increement and Decreement operator:
console.log("\n")
console.log("Increement and Decreement operator:")
a ++;
console.log("Increement operator: ", a);
a --;
console.log("Decreement operator: ", a);

//6. Ternary operator:
console.log("\n")
console.log("Teranary Operators:")
let boyage = 50;
console.log(boyage > 18 ? 'eligible to vote' : 'not eligible');

//Conditional statements: These statements are programming constructs that evaluate whether a specific condition is true or false.
//Types of conditional statements:
//1. if statement:
console.log("\n")
console.log("only if example")
console.log("If statement:");
let AGE = 15;
if(AGE==15){
    console.log("True");
}

//2. if-else statement:
console.log("\n")
console.log("positive, negative example with if else")
console.log("if-else statement:");
let h = -5;
if(h == 5){
    console.log("positive number")
}
else{
    console.log("Negative number")
}

//3.nested if else statement:
//first example:
console.log("\n")
console.log("grade example with if else")
let marks = 75;
if (marks > 90){
    console.log("Grade: A+");
}
else if(marks >= 80 && marks < 90){
    console.log("Grade: A");
}
else if(marks >= 70 && marks < 80){
    console.log("Grade: B"); 
}
else if(marks >= 60 && marks < 70){
    console.log("Grade: B+")
}
else if(marks >= 50 && marks < 60){
    console.log("Grade: C");
}
else if(marks >= 40 && marks < 50){
    console.log("Grade: C+")
}
else{
    console.log("Fail")
}

//second example:
console.log("\n")
console.log("even odd example with if else")
let number = 5;
if ( number %2 == 0){
    console.log("Even number")
}
else{
    console.log("Odd number")
}

//Third example with teranary opertor:
console.log("\n")
console.log("teranary operator if else example ")
console.log(number %2 == 0 ? 'Even number' : 'Odd number');

//Fourth example of if else statement 
console.log("\n")
console.log("Fourth example of if else statement:")
let shopammount = 75000;
if(shopammount >= 90000){
    console.log("you will contain 50% Discount");
}
else if(shopammount >= 80000 && shopammount < 90000){
    console,log("you will contain 40% Discount")
}
else if(shopammount >= 70000 && shopammount <80000){
    console.log("you will contain 30% Discount");
}
else if(shopammount >= 60000 && shopammount < 70000){
    console.log("you will contain 20% Discount");
}
else if(shopammount >= 50000 && shopammount <60000){
    console.log("you will contain 10% Discount");
}
else{
    console.log("you will not contain any Discount");
}
//Fifth example of if else statement 
console.log("\n")
console.log("Fifth example of if else statement:")
let x = 7;
let y = 11;
let z = 40;
if(x > y || x > z){
    console.log("x is Largest than y and z")
}
else if(y > z ){
    console.log("y is Largest than z");
}
else{
    console.log("x and y is Smallest than z");
}
//Sixth example of if else statement 'leap year'
console.log("\n");
console.log("sixth example of if else statement:");


//4. switch statement: A switch statement is a control flow mechanism that routes program execution to different blocks of code based on the exact value of a single expression. 
// It serves as a cleaner, more readable alternative to a long chain of if-else if statements
// first example:
console.log("\n");
console.log("Switch satement 1st example: ");
let day=4;
switch (day){
    case 1: console.log('Day is Monday');
    break;
    case 2: console.log('Day is Tuesday');
    break;
    case 3: console.log('Day is Wednesday');
    break;
    case 4: console.log('Day is Thursday');
    break;
    case 5: console.log('Day is Friday');
    break;
    case 6: console.log('Day is Saturday');
    break;
    default: console.log('Day is Sunday');
    
}
//second example:
console.log("\n");
console.log("Switch satement 2nd example: ");
let am = 75000;
let discount;
switch(true){
    case (am >= 90000):
    discount = am * 0.50;
    console.log("you contain 50% discount , then your ammount should be: ", discount);
    break;

    case (am >= 80000 && am < 90000):
    discount = am * 0.40;
    console.log("you contain 40% discount , then your ammount should be: ", am - discount);
    break;

    case (am >= 70000 && am < 80000):
    discount = am * 0.30;
    console.log("you contain 30% discount , then your ammount should be: ", am - discount);
    break;

    case (am >= 60000 && am < 70000):
    discount = am * 0.20;
    console.log("you contain 20% discount , then your ammount should be: ", am - discount);
    break;

    case (am >= 50000 && am < 60000):
    discount = am * 0.10;
    console.log("you contain 10% discount , then your ammount should be: ", am - discount);
    break;

    default: console.log("you are not contain any ammount, shop upto 50000 ", am );
}

//Loops:JavaScript loops are control structures used to repeat a block of code multiple times until a specific condition evaluates to false.
//Types of loops:
//1. FOR Loop:
//1st example of dor loop:
console.log("\n");
console.log("For loop 1st example: "); 
let n1 = 20;
for(let i =0; i <= n1; i+=2){ // for loop another method of print even numbers 
        console.log('even number is: ', i);
}
//2nd example of for loop:
console.log("\n");
console.log("For loop 2nd example: ");
let v = 0;
for(let i = 20; i >= v; i--){
    console.log(i);
}
//3rd example of for loop:
console.log("\n");
console.log("For loop 3rd example: ");
let p = 20;
for(let i = 0; i <= p; i++){
    let sq = i*i;
    console.log('The square of ',i,' is: ', sq)
}
//2. WHILE Loop:
//1st example of while loop:
console.log("\n");
console.log("while loop 1st example: "); 
let n2=5;
let i=0;
while(i <= n2){
    console.log(i);
    i++;
}
//3. DO...WHILE Loop:
console.log("\n");
console.log("do..while loop 1st example: ");
let x1= 0;
do{
    console.log(x1);
    x1++;
}
while(x1 <= 3);
//4. FOR...OF Loop:The for...of loop is modern JavaScript syntax (introduced in ES6)
//  specifically designed to read through the values inside iterable data structures like Arrays, Strings, Maps, and Sets.
//syntax of for of loop:
// for (variable of iterable) {
//   // Code block to be executed for each element
// }
// 1st example of for of loop:
console.log("\n");
console.log("for...of loop 1st example: ");
let colors = ['Red','Green','Pink','Blue','Purple'];
for(let color of colors){
    console.log(color);
}
//5. FOR...IN Loop: The for...in loop is used in JavaScript to iterate over the property keys (or names) of an object.
//While the for...of loop we just looked at gets the values from a collection, the for...in loop gets the labels/keys.
//Syntax of for..,in loop:
// for (variable in object) {
//   // Code block to execute for each property key
// }
console.log("\n");
console.log("for...in loop 1st example: ")


//Functions of JAVASCRIPT:
//first example of functions:
console.log("\n");
console.log("functions 1st example: ")
function greet() //function declare
{ 
    console.log("GOOD MORNING");
}
console.log("Hi");
greet();//function calling 
console.log("How are you?");

//2nd example of functions 
console.log("\n");
console.log("functions 2nd example: ")
//function with prameters:
function ADD(a,b){
    let sum=a+b;
    console.log("Addition of ",a," + ",b, " is: ", sum)
}
ADD(2,4); // function calling

//3rdexample of functions 
console.log("\n");
console.log("functions 3rd example: ")
function mul(a,b){
    let multiplication=a*b;
    console.log("Multiplication of ",a," * ",b, " is: ", multiplication)
}
mul(2,4); // function calling

//4th example of functions 
console.log("\n");
console.log("functions 4th example: ")
function Div(a,b){
    let division=a/b;
    console.log("Division of ",a," / ",b, " is: ", division)
}
Div(2,4); // function calling

//5th example of functions 
console.log("\n");
console.log("functions 5th example: ")
function even(j){
    if(j %2 === 0){
        console.log("Number is even")
    }
    else{
        console.log("number is odd")
    }
}
even(7);

//6th example of functions 
console.log("\n");
console.log("functions 6th example: ")
function square(jj){
    let sqr = jj*jj;
    console.log("Square of ",jj, " is: ", sqr)
}
square(8);


// The return statement in Java is a jump statement used to explicitly terminate the execution of a 
// method and pass control back to the caller.Depending on the method definition, it serves two main purposes:
// 1.Returning a calculated value back to the calling method.
// 2.Exiting a void method early without passing a value.

//1st example of return statement:
console.log("\n");
console.log("functions return statement 1st example: ")
function add(ff,gg){
    return ff+gg;
}
let result=add(6,8);
console.log("sum: ",result);

//Creating function with Arrow method , it's a new method only in java
console.log("\n");
console.log("Arrow method functions 1st example: ");
const multi=(v,k) => {console.log("Mutiplication: ", v*k)}
multi(7,9);


//Scope of functions:In Java, functions are called methods, and their scope—alongside the scope of the 
// variables declared inside them—defines where code elements can be legally accessed and modified. 
// Java uses lexical (static) scoping, meaning visibility is determined entirely at compile time by the placement of curly braces.
// Scope of the Methods Themselves (Visibility): 
// The accessibility of a method across different classes and packages is controlled by Access Modifiers:
// 1.private: The method can only be called within the same class.
// 2.default (No modifier): Accessible by any class within the same package.
// 3.protected: Accessible within the same package and by subclasses in other packages.
// 4.public: Accessible from any class across the entire application.

//STRING INTERPOLATION METHOD
console.log("\n");
console.log("string interpolation method 1st example: ");
let naam = "Divya Aggarwal";
let umar = 20;
console.log(`My name is: ${naam}. I'm a Enginnering student. My age is: ${umar}.`);// use tab ke upper tick(`) button insted of "",''.

//ARRAY: array store hetrogeous elements in the memory. means any type of datatype elements can stored at single variable name array.
console.log("\n");
console.log("Array 1st example: ");
let arr= [2,7,'A',2.6,true];
console.log(arr);
//updating an element in array
console.log("\n");
console.log("Array updating example: ");
arr[0] = 8;
console.log(arr);
// Adding an element in array : we can add at beg so use unshift method  or end use push method  too
//add an elememt at end
console.log("\n");
console.log("Array add at end example: ");
arr.push(67); // add at end of the array
console.log(arr)
//adding an elemnt at beg
console.log("\n");
console.log("Array add at beg example: ");
arr.unshift(4); //add at the beg of the array
console.log(arr[0]);
console.log(arr);
//delete an element in array
console.log("\n");
console.log("Array delete at end example: ");
arr.pop();//delete at end 
console.log("\n");
console.log("Array delete at beg example: ");
arr.shift();//delete at beg
console.log(arr);

//traverse or print 
console.log("\n");
console.log("Array traversing example with for loop: ");
for(let i=0; i < arr.length; i++){
    console.log(arr[i]);
}
//modern method of javascript with forEach loop
console.log("\n");
console.log("Array traversing example with forEach loop: ");
arr. forEach(i =>{console.log(i)});

//includes checks the element is present or not, gives output: true or false 
console.log("\n");
console.log("Array example to check the element in array: ");
console.log(arr.includes(7));

//to check the index of an element:
console.log("\n");
console.log("Array example to check the index of element: ");
console.log(arr.indexOf(7));

//function of array
console.log("\n");
console.log("function of array example: ");
function printelements(arr){
    for( let i=0; i < arr.length; i++)
    console.log(arr[i])
}
const students = ["john","pheobe","chandler","monica","rachel","ross"];
printelements(students);

printelements(arr);

// example 
let array = [3,5,2,6,1,9];
function evenoddelements(array){
    for(let i =0; i < array.length; i++){
        if(i %2 === 0){
            console.log("e")
        }
    }
}
