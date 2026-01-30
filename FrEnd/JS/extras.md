##  NaN stands for “Not a Number” 🤯
- It’s a special value in JavaScript that represents a result which is supposed to be a number, but isn’t mathematically valid.
> You usually get NaN when you try to do invalid numeric operations.
```js
console.log(0 / 0);        // NaN
console.log("hello" * 2); // NaN
console.log(Math.sqrt(-1)); // NaN
```

> typeof NaN; // "number"

### 🔹 NaN is NOT equal to itself ❌
- This is very important for interviews 👇
```js
NaN === NaN; // false
NaN == NaN;  // false
```

### 🔹 How to check for NaN correctly ✅
```js
1️⃣ Number.isNaN() (BEST way)
Number.isNaN(NaN);       // true
Number.isNaN("hello");  // false
```

```js
2️⃣ isNaN() (older, tricky)
isNaN("hello"); // true ❌ (because it tries to convert)
isNaN(NaN);     // true
```

> 👉 Interview tip: Prefer Number.isNaN()

## 🔹 Truthy and Falsy Values
- In JavaScript, every value is either truthy or falsy when used in a boolean context (like if, while, &&, ||).

1. ❌ Falsy values (ONLY these 7)
```js
false
0
-0
0n
""
null
undefined
NaN
```
- 👉 Anything NOT in this list is truthy.

2. ✅ Truthy examples
```js
true
1
"0"
"false"
[]
{}
function(){}
```

## Function Declaration VS Function Expression
| Feature                    | Function Declaration | Function Expression |
| -------------------------- | -------------------- | ------------------- |
| Hoisting                   | ✅ Fully hoisted      | ❌ Not hoisted       |
| Can call before definition | ✅ Yes                | ❌ No                |
| Name required              | ✅ Yes                | ❌ No                |
| Anonymous                  | ❌ No                 | ✅ Yes               |
| Used in callbacks          | ❌ Rare               | ✅ Common            |


## ES6 stands for ECMAScript 2015.
- It’s a major update to JavaScript that made the language cleaner, more powerful, and easier to write—especially for modern web apps and backend (Node.js).
- The firs ECMAScript versions was abbreviated by numbers. (ES1, ES2, ES3, ES5, ES6).
- From 2016, versions are named by year (ECMAScript 2016, 2017, 2018, ..., 2025).

## 🔹 Rest Operator (...) – Collects values
- Rest operator packs multiple values into a single array.
```js
const [first, ...rest] = [10, 20, 30, 40];

console.log(first); // 10
console.log(rest);  // [20, 30, 40]
```

> ❌ Rest must be last parameter
function test(a, ...rest, b) {} // ❌ Error


## 🔹 Spread Operator (...) – Expands values
```js
const a = [1, 2];
const b = [3, 4];

const merged = [...a, ...b]; // [1,2,3,4]
```
- ✔ Shallow copy
- ✔ No mutation

| Feature   | Rest                      | Spread                          |
| --------- | ------------------------- | ------------------------------- |
| Purpose   | Collect values            | Expand values                   |
| Direction | Many → One                | One → Many                      |
| Used in   | Parameters, destructuring | Function calls, arrays, objects |
| Output    | Array / Object            | Individual values               |


## What is shallow copy vs deep copy?
Ways to create a shallow copy
```js
Object.assign({}, obj)
{ ...obj }
array.slice()
[...array]
```

1. Deep Copy :
Example (Correct)
```js
const original = {
  name: "Akash",
  address: { city: "Delhi" }
};

const deep = JSON.parse(JSON.stringify(original));

deep.address.city = "Mumbai";

console.log(original.address.city); // Delhi ✅
```
- Better Deep Copy (Modern JS)
> const deep = structuredClone(original);
- ✔ Handles nested objects
- ✔ Recommended

| Feature        | Shallow Copy     | Deep Copy    |
| -------------- | ---------------- | ------------ |
| Nested objects | Shared reference | Fully copied |
| Memory usage   | Less             | More         |
| Performance    | Faster           | Slower       |
| Safe to modify | ❌ No             | ✅ Yes        |

## What is a Promise?
- A Promise is an object that represents the eventual completion (or failure) of an asynchronous operation and its resulting value.

### 🔹 Promise States (VERY IMPORTANT)
- A Promise can be in one of three states:
1. 1️⃣ Pending – initial state
2. 2️⃣ Fulfilled – operation completed successfully
3. 3️⃣ Rejected – operation failed

## 
| Feature   | `setTimeout`  | `setInterval`      |
| --------- | ------------- | ------------------ |
| Execution | Once          | Repeated           |
| Control   | Manual repeat | Automatic repeat   |
| Use case  | Delayed task  | Periodic task      |
| Risk      | Low           | Can cause overlaps |



## Modules 
- are self-contained pieces of code that encapsulate variables, functions, or classes and expose only what is needed.

### 🔹 Types of Modules in JavaScript
1. 1️⃣ ES Modules (ESM) – import / export
2. 2️⃣ CommonJS (CJS) – require / module.exports

| Feature         | `import`        | `require`                |
| --------------- | --------------- | ------------------------ |
| Module system   | ES Modules      | CommonJS                 |
| Syntax          | `import/export` | `require/module.exports` |
| Loading         | Asynchronous    | Synchronous              |
| Static analysis | ✅ Yes           | ❌ No                     |
| Tree shaking    | ✅ Yes           | ❌ No                     |
| Usage location  | Top-level only  | Anywhere                 |
| Browser support | ✅ Yes           | ❌ No (Node only)         |

## 🔹 Optional Chaining (?.)
- user.profile.address.city; // ❌ Error if profile is undefined
- user.profile?.address?.city;
- ✔ Returns undefined instead of crashing
- ✔ Cleaner code

## 🔹 Nullish Coalescing (??)
- Nullish coalescing returns a fallback value ONLY when the left side is null or undefined.
```js
let name = null;
console.log(name ?? "Guest"); // Guest
```

## 🔹 Symbols
- A Symbol is a unique and immutable primitive data type introduced in ES6.
- Example
```js
const id = Symbol("id");
const id2 = Symbol("id");

console.log(id === id2); // false
```
- ✔ Always unique
- ✔ Even with same description

## 🔹 Iterators
- An iterator is an object that provides a way to access values one at a time using a next() method.

## 🔹 Generators
- A generator is a special function that can pause and resume execution using yield.

## 2️⃣ console.log(0.1 + 0.2 === 0.3);
- false
> This is due to floating-point precision in JavaScript.
- 0.1 + 0.2 = 0.30000000000000004
- 📌 JavaScript uses IEEE 754 binary floating-point, which cannot represent some decimals exactly.
- ✅ Correct way to compare
> Math.abs((0.1 + 0.2) - 0.3) < Number.EPSILON;

