import Home from "./Components/Home";
import UserContext from "./context/UserContext";

function App() {
  // const user = "John Tribbiani";
  let obj = {id: 1, name: "John Tribbiani", age: 30, email: "abc@gmail.com"};
  return (
    <UserContext.Provider value={obj}>
      <Home />
    </UserContext.Provider>
  );
}

export default App;