// const express = require ('express');
import express from 'express';

const app = express(); //keyword normally app hi use hota hai.

app.use((req, res, next) => {
    console.log("Middleware function executed");
    next();
});

app.get("/", (req, res) => {
    res.send("<h1>Hello World</h1>");
});

app.get("/student", (req, res) => {
    res.json({ name: "John Doe" });
});

app.get("/profile", (req, res) => {
    res.send("This is profile page");
});

app.listen(5000,()=>{
    console.log("Server is running on port 5000");
});