// const express = require ('express');
import express from 'express';

const app = express(); //keyword normally app hi use hota.

app.get("/", (req, res) => {
    res.send("Hello World");
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