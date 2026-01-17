## Default parameters 
allow a function to use default values when no argument (or undefined) is passed.
```js
function greet(name = "Guest") {
  return `Hello, ${name}`;
}

greet("Akash");   // Hello, Akash
greet();          // Hello, Guest
```

##  IIFE  : Immediate Invoked Function Execution
- is a function that is defined and executed immediately after it’s created.

## ## Arrow functions
- Arrow functions are a shorter, cleaner syntax for writing functions in JavaScript, introduced in ES6.
- 👉 Arrow functions don’t have their own this, arguments, or prototype, and they provide concise syntax.
```js
const add = (a, b) => {
  return a + b;
};
```
- shorter 
```js
const add = (a, b) => a + b;
```
- 
| Feature             | Arrow Function                     | Normal Function                     |
| ------------------- | ---------------------------------- | ----------------------------------- |
| `this`              | ❌ Does **not** have its own `this` | ✅ Has its own `this`                |
| `arguments`         | ❌ Not available                    | ✅ Available                         |
| Constructor (`new`) | ❌ Cannot be used                   | ✅ Can be used                       |
| Syntax              | Short & clean                      | Longer                              |
| Hoisting            | ❌ Not hoisted                      | ✅ Function declarations are hoisted |
