console.log("Objects example: ")
//Objects:An object in JavaScript is a standalone data structure that stores related data and functionality as key-value pairs.
//example:
const student={
    name :'Divya',
    course : 'B.Tech COE',
    Age : 20,
    sem : '5th',
    roll_no : 2412808 
}
//Accessing
console.log("Objects example of Acessing: ")
console.log(student.name);
console.log(student["name"]);
//updating
console.log("\n");
console.log("Objects example of Updating: ")
student.name='Divya Sharma'
console.log(student.name);
//Adding 
console.log("\n");
console.log("Objects example of Adding: ")
student.city='Amritsar';
console.log(student.city);
//Deleting
console.log("\n");
console.log("Objects example of Deleting: ")
delete student.Age;
console.log(student.Age);

// loops in objects 
console.log("\n");
console.log("Objects example of loops: ")
for(let key in student){
    console.log(key , " : ", student[key]);
}