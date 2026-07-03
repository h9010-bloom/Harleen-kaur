const fs = require('fs');

fs.writeFileSync('test.txt', 'Hello, this is a test file created using Node.js!');

let data = fs.readFileSync('test.txt', 'utf8');
console.log(data);

const http = require('http');
const server = http.createServer(() => {
  console.log('Server is running...');
});
server.listen(5000);