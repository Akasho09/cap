## 

| **Type of Component**            | **Description**                       | **Uses State?** | **Common Use Case**         |
| -------------------------------- | ------------------------------------- | --------------- | --------------------------- |
| **Functional Component**         | JavaScript function that returns JSX  | ✅ (with Hooks)  | Modern React apps           |
| **Class Component**              | ES6 class extending `React.Component` | ✅               | Legacy projects             |
| **Presentational Component**     | Focuses only on UI                    | ❌               | Buttons, cards, UI layouts  |
| **Container Component**          | Handles logic & data                  | ✅               | API calls, state management |
| **Controlled Component**         | Form data controlled by React state   | ✅               | Forms with validation       |
| **Uncontrolled Component**       | Form data handled by DOM using refs   | ❌               | Simple forms                |
| **Higher-Order Component (HOC)** | Function that wraps another component | Depends         | Code reuse, auth            |
| **Pure Component**               | Prevents unnecessary re-renders       | Depends         | Performance optimization    |
| **Stateless Component**          | No state (usually functional)         | ❌               | Static UI                   |
| **Stateful Component**           | Manages its own state                 | ✅               | Dynamic UI                  |

1. Functional Components (Most Common ✅)
- Written as JavaScript functions
- Can use Hooks (useState, useEffect, etc.)
- Preferred in modern React (with React 16.8+)

```js
function Welcome() {
  return <h1>Hello, Akash!</h1>;
}

// Arrow function
const Welcome = () => <h1>Hello, Akash!</h1>;
```
### Key points
- Simple and clean
- Better performance & readability
- Easy state and lifecycle handling using hooks

### When not to use ??!!
- Stateful components: Functional components cannot hold state on their own. Therefore, if you need to maintain state within your component, you may need to use a class component.
- Lifecycle methods: If you need to use lifecycle methods such as componentDidMount, componentDidUpdate, or componentWillUnmount, you will need to use a class component.

2. Class Components (Legacy ⚠️)
- Written using ES6 classes
- Use this.state and lifecycle methods
- Less common in new projects
```jsx
import React, { Component } from "react";
class Welcome extends Component {
  render() {
    return <h1>Hello, Akash!</h1>;
  }
}
```
- Key points
  - More boilerplate
  - Harder to maintain
  - Mostly seen in older codebases.


3. Controlled Components
- Form data is controlled by React state
```jsx
function Form() {
  const [name, setName] = React.useState("");

  return (
    <input
      value={name}
      onChange={(e) => setName(e.target.value)}
    />
  );
}
```

4. Uncontrolled Components
Form data is handled by the DOM using ref
```jsx
function Form() {
  const inputRef = React.useRef();

  return <input ref={inputRef} />;
}
```
