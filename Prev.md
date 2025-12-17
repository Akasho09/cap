## React

"React" is a JavaScript library for building user interfaces.

React is used to build single-page applications.

React allows us to create reusable UI components.

- Basically , it calulates diff between initial & final , then updates.

  
# commands
npm create vite@latest

npm install --> installs all dependencies in p.json

cd frontend

npm run dev

npm run build

# state 
"State" is an object that holds data that can change over the lifetime of a component.

React tracks this data internally, and when the state changes, it triggers a re-render of the component.

- The state is local to the component and can only be updated by that component (although state can be passed down as props to child components).

setCount (count + 1)
setCount (c => c + 1)
setCount (function(c) { return c +1 })
  

# Re-rendering in react

It happens when

A state variable that is being used inside a component changes

A parent component re-render triggers all children re-rendering.

  
  

# React Memo

"Components in React are designed to re-render whenever the state or props value changes."

Also, when a parent component re-renders, so do all of its child components. This can impact our application performance because,

even if the change is only intended to affect the parent component, all child components attached to the parent component will be re-rendered.

Ideally, child components should only re-render if their state or the props passed to them change.

- React.memo() is a `higher-order component` (HOC) provided by React that memoizes functional components. 
> It means that it caches the result of the component’s rendering based on its `props`, and re-renders only when the props have changed.


# Warning: Each child in a list should have a unique “key” prop.

Keys tell React which array item each component corresponds to, so that it can match them up later.

This becomes important if your array items can move (e.g. due to sorting), get inserted, or get deleted.

A well-chosen key helps React infer what exactly has happened, and make the correct updates to the DOM tree.

JSX elements directly inside a map() call always need keys!.

  
#  useMemo
The React "useMemo" Hook returns a memoized value.

- useMemo() is a React Hook used to memoize the result of `expensive computations` within functional components.

> It memorizes the value returned by a provided `function` and re-calculates it only when the dependencies change.
```javascript
import { useState, useMemo } from "react";

function App() {
  const [count, setCount] = useState(0);
  const [number, setNumber] = useState(10);

  // Use useMemo to memoize the result
  const expensiveResult = useMemo(() => {
    console.log("Running expensive calculation...");
    return number * 2; // Simulated expensive operation
  }, [number]); // Recomputes only when 'number' changes

  return (
    <div>
      <h2>Expensive Computation: {expensiveResult}</h2>
      <button onClick={() => setCount(count + 1)}>Re-render {count}</button>
      <button onClick={() => setNumber(number + 1)}>Change Number</button>
    </div>
  );
}
```
> Prevents unnecessary expensive function calls 🔥
> ✔ Only re-runs when number changes (not count)
  
  
# useCallback : 
useCallback is a React Hook that memoizes a function, preventing it from being re-created unnecessarily during re-renders. 
- It is useful when passing `functions as props` to child components to avoid unnecessary re-renders.

- The React "useCallback" Hook returns a memoized callback function.

because f1==f2 is false even if both functions are same.

```javascript
import { useState, useCallback } from "react";
import ChildComponent from "./ChildComponent";

function App() {
  const [count, setCount] = useState(0);

  // Memoized function: re-created only when count changes
  const handleClick = useCallback(() => {
    console.log("Button clicked!");
  }, []); // Empty dependency array means it never changes

  return (
    <div>
      <h2>Count: {count}</h2>
      <button onClick={() => setCount(count + 1)}>Increment</button>
      <ChildComponent handleClick={handleClick} />
    </div>
  );
}
export default App;
```
> Even if only count changes, handleClick is re-created on every render, causing ChildComponent to re-render unnecessarily.
  now handleClick remains the same across renders 🔥


# Reconciliation
React "Reconciliation" is the process through which React updates the Browser DOM.

It makes the DOM updates faster in React. It updates the virtual DOM first and then uses the diffing algorithm to make efficient and optimized updates in the Real DOM.

- Render: React creates a Virtual DOM representation of the UI.
- Diffing: React compares (diffs) the new Virtual DOM with the previous one.
- Reconciliation: React updates only the changed parts in the real DOM instead of re-rendering the whole page.
  
  
# useRef
The "useRef" Hook allows you to persist values between renders.

It can be used to store a mutable value that does not cause a re-render when updated.

It can be used to access a DOM element directly

const divref = useRef();
re={divref}

- eg :  timer 
✔ useRef stores a timer ID
✔ Prevents unnecessary re-renders when starting/stopping the timer


# Suspense and Lazy 
> eg: diff Section loading at diff times.
 is a React component used to suspend the rendering process to perform some asynchronous tasks like getting data from API or loading any other component lazily. 
 In simple words, Suspense is like waiting for something to happen, where we are not sure when it will happen. Suspense is beneficial in code splitting and data fetching processes.
- warp in Suspense 
- const Dashboard = lazy (() => import('./components/dashboard'))
<Route path="/dashboard" element =  <Suspense fallback={"LOADINGGG ......"}> <Dashboard/> </Suspense>
- lazy() dynamically imports LazyComponent.
- Suspense provides a fallback UI (Loading...) while loading.
- The component loads only when required, improving performance.

# Context API
Context API is used to pass global variables anywhere in the code. It helps when there is a need for sharing state between a lot of nested components. It is light in weight and easier to use, to create a context just need to call React.createContext(). No need to install other dependencies or third-party libraries like redux for state management.
1. import {createContext, useContext } from 'react';
2. const CountContext = createContext (0);
3. Wrap the part of your component tree where you want to share the context. 
<CountContext.Provider value={count} >
<Counter count={count}></Counter>
</CountContext.Provider>
4. now we can teleport & use it anywhere .
const c= usecontext(CountContext)
- CountContext.Provider makes the count value available to all child components via context (instead of passing it as props).
- it basically reduces DRY or Pop Drilling but doesnt optimize code ie re-rendering happens more.


## State Management
A cleaner way to store the state of your app.
Until now, the cleanest thing you can do is use the Context API ,It lets you teleport state.
But there are better solutions that get rid of the problems that Context Api has (unnecessary re-renders).

# Redux
Redux is a state managing library used in JavaScript apps. It simply manages the state of your application or in other words, it is used to manage the data of the application. It is used with a library like React. It makes easier to manage state and data. As the complexity of our application increases.
Building Blocks of redux:  
- Action
- Reducer
- Store

# Recoil
npm install recoil
A state management library for React
Written by some ex React folks
Other popular ones -
1. Zustand
2. Redux
Recoil
- Has a concept of an "atom" to store the state
- An atom can be defined outside the component
- Can be teleported to any component. 
3 things
- useRecoilState only state 
- useRecoilValue only value based on atom
- useSetRecoilState ===useState()

# Recoil selectors 
> Selectors are functions that compute derived state based on atoms.
- A selector represents a piece of derived state. 
You can think of derived state as the output of passing state to a pure function that derives a new value from the said state.

# Asynchronous Queries with Recoil Selectors
-- to get a atom remotely we use selector as a async fn in get fn of the atom
import { selector, useRecoilValue } from 'recoil';
import axios from 'axios';

const userSelector = selector({
    key: 'userSelector',
    // get is a async function to fetch notifications
    get: async () => {
        const response = await axios.get('https://jsonplaceholder.typicode.com/users');
        return response.data;
    },
});

# atom family

an atomFamily allows you to create `parameterized atoms`

import { atomFamily } from "recoil";
import { TODOS } from "./todos";

export const todosAtomFamily = atomFamily({
  key: 'todosAtomFamily',
  default: id => {
    return TODOS.find(x => x.id === id)
  },
});

## React Hooks
Hooks allow function components to have access to state and other React features. Because of this, class components are generally no longer needed.

Hooks let you use different React features from your components. You can either use the built-in Hooks or combine them to build your own.
![alt text](<Screenshot 2024-11-05 at 8.37.21 PM.png>)

# useEffect

The "useEffect" Hook allows you to perform side effects in your components. --> stops infinite rerendering

Some examples of side effects are: fetching data, directly updating the DOM, and timers.

useEffect accepts two arguments. The second argument is optional.

useEffect(<function>, <dependency>)

> useEffect(() => {  //Runs on every render });

> useEffect(() => {  //Runs only on the first render   }, []);

> useEffect(() => {  //Runs on the first render  //And any time any dependency value changes }, [prop, state]);

# React Custom Hooks
- uses internally another hook eg useState etc
- Custom Hooks start with "use". Example: useFetch.



## Lifecycle of Components
Each component in React has a lifecycle which you can monitor and manipulate during its three main phases.

The three phases are: Mounting, Updating, and Unmounting.

# Mounting
Mounting means putting elements into the DOM.

React has four built-in methods that gets called, in this order, when mounting a component:

constructor()
getDerivedStateFromProps()
render()
componentDidMount()
The render() method is required and will always be called, the others are optional and will be called if you define them.



## RESTFUL APIs
![alt text](image-1.png)

- Stateless: Each request from a client to a server must contain all the information the server needs to fulfill the request. No session state is stored on the server.
- Client-Server Architecture: RESTful APIs are based on a client-server model, where the client and server operate independently, allowing scalability.
- Cacheable: Responses from the server can be explicitly marked as cacheable or non-cacheable to improve performance.
- Uniform Interface: REST APIs follow a set of conventions and constraints, such as consistent URL paths, standardized HTTP methods, and status codes, to ensure smooth communication.
- Layered System: REST APIs can be deployed on multiple layers, which helps with scalability and security.

