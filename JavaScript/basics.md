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

### How async functions work in JavaScript
JavaScript uses:
1. Call Stack
2. Web APIs
3. Callback Queue / Microtask Queue
4. Event Loop
- Async tasks are handled outside the call stack and pushed back when ready.

### Key points
> async → function returns a Promise
> await → pauses execution inside the function only

### ⚠️ useEffect itself cannot be async — define an async function inside.

> Asynchronous functions allow non-blocking execution by returning promises and handling results later using async/await.

## Question 1. What is the difference between a process and a thread?
- Process is an independent unit of execution with its own memory space, while a thread is a smaller unit within a process that shares the same memory and resources.
- Processes are isolated from each other and require more overhead to create and manage.
- Threads, being lightweight, are faster to create and switch but need careful synchronization due to shared memory. A crash in one process doesn’t affect others, but a faulty thread can impact the whole process.

