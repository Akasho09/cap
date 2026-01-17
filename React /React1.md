## React
- "React" is a JavaScript library for building user interfaces.
- React is used to build single-page applications.
> A Single Page Application is a web application that loads a single HTML page once, and then dynamically updates the content without reloading the entire page.
- React is used for building dynamic, interactive, and reusable user interfaces (UIs) for web and mobile apps,  
 
> React current version : 19.
  - New React Features in 19.2
    - <Activity />
    - useEffectEvent
    - cacheSignal
    - Performance Tracks
> 16+ is same hie.

- React creates a Virtual DOM (lightweight copy of real DOM)
  - Compares changes (diffing)
  - Updates only what changed (reconciliation)
> ✔ Faster than direct DOM manipulation
### 🔹 What is Vite?
- Vite is a frontend tooling system that:
  - Starts a development server
  - Transpiles JSX
  - Bundles code for production
> React builds the UI
Vite builds the app

### JSX (JavaScript XML)
- It is called JSX, and it is a syntax extension to JavaScript. We recommend using it with React to describe what the UI should look like. JSX may remind you of a template language, but it comes with the full power of JavaScript.
> JavaScript XML (JSX) is a syntax extension for JavaScript that allows you to write HTML-like code inside JavaScript.
- The build tool (Vite / Webpack / Babel):
  1. Converts JSX → JavaScript
  2. Removes JSX syntax
  3. Outputs browser-understandable JS
- The browser never sees JSX.
#### Babel?
Babel is a JavaScript compiler (transpiler) that converts modern JavaScript (ES6+) and JSX into backward-compatible JavaScript that browsers can understand.

### How React Works as an SPA
1. Single HTML File
- When a React app loads, the browser downloads one main HTML file (usually index.html).
- This file contains a root <div> where the entire app runs.

2. JavaScript Takes Control
- React loads JavaScript bundles that handle rendering.
- All page changes happen inside the browser, not from the server.

3. Client-Side Routing
- React uses libraries like **React Router.**
- Navigation between pages (e.g., /login, /dashboard) happens without reloading the page.
- Only components change, not the whole page.

4. Virtual DOM
- React updates only the parts of the UI that change.
- This makes the application fast and smooth.

5. API-based Data Fetching
- React fetches data from APIs (REST or GraphQL).
- Server sends data, not HTML pages.

> Basically , it calulates diff between initial & final , then updates.

## Props :
-Props (short for Properties) are read-only inputs passed from a parent component to a child component.
### ✅ Key Characteristics
- Passed from parent to child
- Immutable (cannot be changed by the child)
- Used to configure or customize components
- Similar to function arguments

```jsx
function Greeting(props) {
  return <h1>Hello, {props.name}!</h1>;
}

// Parent component
<Greeting name="Akash" />
```
### Props Destructuring
1. Directly using props.name.
```js
function Greeting(props) {
  return <h1>Hello, {props.name}</h1>;
}
```
2. Destructuring inside .
```js
function Greeting(props) {
  const {name , email} = props
  return <h1>Hello, {name}</h1>;
}
```
3. Destructuring in function para,eter itsslf.
```js
function Greeting({name , email}) {
  return <h1>Hello, {name}</h1>;
}
```
## 🔹 What is State?
- State is a built-in object that stores data that can change over time inside a component.
- ✅ Key Characteristics
  - Managed within the component
  - Mutable
  - Triggers re-render when updated
- Used for dynamic data (counters, form inputs, API responses)
- 
| Feature            | Props            | State            |
| ------------------ | ---------------- | ---------------- |
| Who owns it?       | Parent component | Component itself |
| Can be modified?   | ❌ No             | ✅ Yes            |
| Purpose            | Pass data        | Manage data      |
| Triggers re-render | ❌ (if unchanged)| ✅                |
| Mutability         | Immutable        | Mutable          |
| Scope              | External         | Internal         |

### 🔹 Types of State in React
1. 1️⃣ Local (Component) State
- Managed inside a single component
- Created using useState
- Example:
const [isOpen, setIsOpen] = useState(false);
- Used for:
  - Form inputs
  - Toggles
  - UI states

2. 2️⃣ Global (Shared) State
- Used when multiple components need access to the same data.
- Examples:
  - Logged-in user
  - Theme (dark/light)
  - Cart items
- Tools used:
  - Context API
  - Redux / Zustand / Recoil

3. 3️⃣ Server State
- Data fetched from an external source (API).
- Examples:
  - User data
  - Product lists
  - Dashboard data
- Handled using:
  - useEffect + fetch
  - React Query / TanStack Query
  - SWR

### 🔹 Common State Management Techniques
1. 1️⃣ useState
- Best for simple, local component state.

2. 2️⃣ useContext
- Used to share global data without prop drilling.

3. 3️⃣ useReducer
- Used for complex state logic with multiple actions.

4. 4️⃣ Redux / Zustand
- Used for large-scale apps with complex global state.
#### Redux : 
  - Redux is a centralized place to store and manage application data so that every component can access it easily and consistently.
##### why?
- In small apps, props + useState + Context are enough.
- But in large apps:
  - State is shared across many components
  - Props become deeply nested (prop drilling)
  - State becomes hard to track and debug

5. 5️⃣ Server State Libraries
- React Query
- SWR

- Handle caching, refetching, and synchronization automatically.

## State Flow in React
- React follows one-way data flow:
1. Parent → Child (via props)
2. Child → Parent (via callbacks)

## Lifecycle of Components
Each component in React has a lifecycle which you can monitor and manipulate during its three main phases.
- The three phases are: Mounting, Updating, and Unmounting.

# Mounting
Mounting means putting elements into the DOM.
- This phase happens when a component is created and rendered for the first time.
- React has four built-in methods that gets called, in this order, when mounting a component:
### Lifecycle Methods (Class Components):
1. Mounting Phase (Birth of Component)
    1. constructor()
      - Initializes state
      - Binds methods
    2. render()
      - Returns JSX
      - Must be pure (no side effects)
    3. componentDidMount()
      - Called after component is rendered
      - Best place for:
        - API calls
        - Subscriptions
        - DOM operations

    > The render() method is required and will always be called, the others are optional and will be called if you define them.
2. 🔹 2. Updating Phase
3. 🔹 3. Unmounting Phase

### 🔹 React Lifecycle in Functional Components (Hooks)
- Modern React uses Hooks instead of class lifecycle methods.
- useEffect() = All lifecycle methods combined
```js
useEffect(() => {
  console.log("Mounted or Updated");

  return () => {
    console.log("Cleanup / Unmount");
  };
}, [dependency]);
```
| Hook Pattern                               | Equivalent Lifecycle |
| ------------------------------------------ | -------------------- |
| `useEffect(() => {}, [])`                  | componentDidMount    |
| `useEffect(() => {}, [x])`                 | componentDidUpdate   |
| `useEffect(() => { return () => {} }, [])` | componentWillUnmount |


# commands
npm create vite@latest
npm install --> installs all dependencies in p.json
cd frontend
npm run dev
npm run build

# Re-rendering in react
- It happens when
- A state variable that is being used inside a component changes
- A parent component re-render triggers all children re-rendering.
  
  

# React Memo

"Components in React are designed to re-render whenever the state or props value changes."

Also, when a parent component re-renders, so do all of its child components. This can impact our application performance because,

even if the change is only intended to affect the parent component, all child components attached to the parent component will be re-rendered.

Ideally, child components should only re-render if their state or the props passed to them change.

- React.memo() is a `higher-order component` (HOC) provided by React that memoizes functional components. 
> It means that it caches the result of the component’s rendering based on its `props`, and re-renders only when the props have changed.


# Warning: Each child in a list should have a unique “key” prop.
- Keys tell React which array item each component corresponds to, so that it can match them up later.
- This becomes important if your array items can move (e.g. due to sorting), get inserted, or get deleted.
- A well-chosen key helps React infer what exactly has happened, and make the correct updates to the DOM tree.
- JSX elements directly inside a map() call always need keys!.
  
#  useMemo
The React "useMemo" Hook returns a memoized value.

- useMemo() is a React Hook used to memoize the result of `expensive computations` within functional components.

> It memorizes the value returned by a provided `function` and re-calculates it only when the dependencies change.
```js
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



## RESTFUL APIs
![alt text](image-1.png)

- Stateless: Each request from a client to a server must contain all the information the server needs to fulfill the request. No session state is stored on the server.
- Client-Server Architecture: RESTful APIs are based on a client-server model, where the client and server operate independently, allowing scalability.
- Cacheable: Responses from the server can be explicitly marked as cacheable or non-cacheable to improve performance.
- Uniform Interface: REST APIs follow a set of conventions and constraints, such as consistent URL paths, standardized HTTP methods, and status codes, to ensure smooth communication.
- Layered System: REST APIs can be deployed on multiple layers, which helps with scalability and security.

