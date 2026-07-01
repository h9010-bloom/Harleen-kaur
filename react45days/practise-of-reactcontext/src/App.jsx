import Home from "./Components/Home";
import UserContext from "./context/UserContext";

function App() {
  // const user = "John Tribbiani";

  return (
    <UserContext.Provider value={{
      name :"John Tribbiani", age: 30, email: "abc@gmail.com"
    }}>
      <Home />
    </UserContext.Provider>
  );
}

export default App;