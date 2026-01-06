## Asynchronous functions 
- are functions that don’t block program execution while waiting for a task to finish (like API calls, file I/O, timers).
- Instead of stopping everything, they let other code run and handle the result later.
> An asynchronous function executes independently of the main program flow and returns its result in the future.

### Why do we need async functions?
- Some operations take time:
- Fetching data from an API 🌐
    1. Reading files 📁
    2. Database queries 🗄️
    3. Timers (setTimeout)
- If JavaScript waited for them synchronously, the app would freeze.

### How async functions work in JavaScript : Event Loop in JavaScript
JavaScript uses:
1. Call Stack
2. Web APIs
3. Callback Queue / Microtask Queue
4. Event Loop
- Async tasks are handled outside the call stack and pushed back when ready.
```js 
console.log("A");

setTimeout(() => {
  console.log("B");
}, 0);

Promise.resolve().then(() => {
  console.log("C");
});

console.log("D");
```
A
D
C
B

### Key points
> async → function returns a Promise
> await → pauses execution inside the function only

### ⚠️ useEffect itself cannot be async — define an async function inside.

> Asynchronous functions allow non-blocking execution by returning promises and handling results later using async/await.

## Synchronous JavaScript (Sync)
- Synchronous code executes line-by-line.
- Each operation blocks the next one until it finishes

| Feature     | Synchronous | Asynchronous               |
| ----------- | ----------- | -------------------------- |
| Execution   | Blocking    | Non-blocking               |
| Flow        | Sequential  | Event-based                |
| Performance | Slower      | Faster                     |
| UI impact   | Freezes UI  | Responsive UI              |
| Examples    | Loops, math | setTimeout, fetch, Promise |

## Event Loop in JavaScript :: ?????
- The event loop is an important concept in JavaScript that enables asynchronous programming by handling tasks efficiently. Since JavaScript is single-threaded, it uses the event loop to manage the execution of multiple tasks without blocking the main thread.


## VAR , LET , CONST 

| Keyword | Scope             |
| ------- | ----------------- |
| `var`   | Function / Global |
| `let`   | Block             |
| `const` | Block             |

| Feature    | var   | let   | const |
| ---------- | ----- | ----- | ----- |
| Re-declare | ✅ Yes | ❌ No  | ❌ No  |
| Re-assign  | ✅ Yes | ✅ Yes | ❌ No  |


| Feature       | var           | let | const |
| ------------- | ------------- | --- | ----- |
| Hoisted       | ✅             | ✅   | ✅     |
| Initialized   | ✅ (undefined) | ❌   | ❌     |
| TDZ           | ❌             | ✅   | ✅     |
| Block Scope   | ❌             | ✅   | ✅     |
| Global object | ✅             | ❌   | ❌     |

## JS VS TS 

| Aspect          | JavaScript | TypeScript    |
| --------------- | ---------- | ------------- |
| Error detection | Runtime    | Compile-time  |
| Refactoring     | Risky      | Safe          |
| Team scaling    | Hard       | Easy          |
| Documentation   | Manual     | Types as docs |
| Maintenance     | Costly     | Predictable   |

## JavaScript Destructuring 
- is a feature that allows you to extract values from arrays or objects and store them into separate variables in a clean and readable way.
```js
const arr = [10, 20, 30];
const a = arr[0];
const b = arr[1];
- ✅ With Destructuring
const [a, b, c] = [10, 20, 30];

function greet({ name, age }) {}
function greet(user) {
  cons [name, age ] = user;
}

```



## Question 1. What is the difference between a process and a thread?
- Process is an independent unit of execution with its own memory space, while a thread is a smaller unit within a process that shares the same memory and resources.
- Processes are isolated from each other and require more overhead to create and manage.
- Threads, being lightweight, are faster to create and switch but need careful synchronization due to shared memory. A crash in one process doesn’t affect others, but a faulty thread can impact the whole process.

