## ✅ 1. React Component Lifecycle (Functional Components)
- In class components, lifecycle had 3 phases:
1. Mounting – component appears
2. Updating – state/props change
3. Unmounting – component removed
> In functional components, lifecycle is handled using [useEffect].

| Class Lifecycle      | Functional Equivalent                |
| -------------------- | ------------------------------------ |
| componentDidMount    | `useEffect(() => {}, [])`            |
| componentDidUpdate   | `useEffect(() => {}, [dep])`         |
| componentWillUnmount | `return () => {}` inside `useEffect` |

```js
useEffect(() => {
  console.log("Mounted");

  return () => {
    console.log("Unmounted");
  };
}, []);
```

## ✅ 2. Difference Between useState vs useEffect

| Feature          | `useState`              | `useEffect`                 |
| ---------------- | ----------------------- | --------------------------- |
| Purpose          | Store data              | Run side effects            |
| Runs on          | User action / re-render | After render                |
| Used for         | UI state, form values   | API calls, timers           |
| Causes re-render | ✅ Yes                   | ❌ No (unless state updated) |

> useState → Stores data
> useEffect → Runs logic after render (side effects like API calls, timers )

## ✅ 3. What is Virtual DOM?
- The Virtual DOM is a lightweight copy of the real DOM stored in memory.
- ✅ How It Works:
1. React creates a Virtual DOM snapshot
- When state changes → new Virtual DOM created
- React diffs old vs new (Reconciliation)
- Only changed nodes update in the real DOM

- ✅ Why It’s Fast:
    - No full page reload
    - Only minimal updates
    - Efficient UI rendering

## ✅ 4. Controlled vs Uncontrolled Components
1. ✅ Controlled Component
- Form data is controlled by React state.
```js
<input value={name} onChange={e => setName(e.target.value)} />
```
- ✅ Fully predictable
- ✅ Easy validation
- ❌ More re-renders

2. ✅ Uncontrolled Component
- Form uses DOM directly via ref.
```js
<input ref={inputRef} />
```
- ✅ Less re-renders
- ❌ Hard validation
- ❌ No real-time control

| Feature        | Controlled  | Uncontrolled |
| -------------- | ----------- | ------------ |
| Data stored in | React State | DOM          |
| Validation     | Easy        | Hard         |
| Best for       | Forms       | Quick input  |


## Flexbox vs Grid (CSS Layout)
| Feature     | Flexbox            | Grid              |
| ----------- | ------------------ | ----------------- |
| Layout Type | 1D (row OR column) | 2D (row & column) |
| Best for    | Navbar, cards      | Full page layout  |
| Alignment   | Easy               | Powerful          |
| Control     | Less               | More              |


## ✅ 9. What is Prop Drilling? How Do You Avoid It?  
- Passing data through unnecessary levels.
- Problems:
  - Messy code
  - Hard debugging
  - Poor scalability

- ✅ Solutions:
1. Context API
2. Global State Management (Redux, Zustand, MobX)
3. Component composition

## ✅ 10. Lazy Loading & Code Splitting
1. ✅ Lazy Loading
- Loading components only when needed.
- const Dashboard = React.lazy(() => import('./Dashboard'));

2. ✅ Code Splitting
- Breaking app bundle into smaller chunks.
- Faster load time
- Less JS blocking
- Better performance
- ✅ Used with:
- 
<Suspense fallback={<Loader />}>
  <Dashboard />
</Suspense>


| Concept                  | Key Purpose           |
| ------------------------ | --------------------- |
| Virtual DOM              | Fast UI updates       |
| useState vs useEffect    | State vs Side Effects |
| Controlled Components    | Form control          |
| Tailwind CSS             | Utility-first CSS     |
| Flex vs Grid             | Layout system         |
| Form Validation          | Data integrity        |
| Performance Optimization | Faster React apps     |
| Prop Drilling            | Poor data flow        |
| Lazy Loading             | Faster initial load   |
| Code Splitting           | Smaller JS bundles    |


## Virtual DOM : 
![alt text](image.png)

## Props :
- Props (short for properties) are inputs passed to a component in React.
```jsx
function Greeting(props) {
  return <h1>Hello, {props.name}!</h1>;
}

// Parent component
<Greeting name="Akash" />
```

## React Lifecycle
- The React lifecycle describes the stages a component goes through from creation → update → removal.
- In modern React, this is handled mostly with Hooks (not class methods).

![alt text](image-1.png)


3. Unmounting:
```jsx
useEffect(() => {
  return () => {
    console.log("Component unmounted");
  };
}, []);
```
- Used for:
  - Cleanup
  - Removing event listeners
  - Clearing intervals
  - Cancelling API requests
