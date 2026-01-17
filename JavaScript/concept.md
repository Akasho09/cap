## Hoisting 
- is a JavaScript behavior where variable and function declarations are moved to the top of their scope during the compilation phase, before the code is executed.
> Important: Only declarations are hoisted, not initializations.
[text](codes/hoisting.js)

| Keyword | Hoisted | Initialized | Accessible before declaration |
| ------- | ------- | ----------- | ----------------------------- |
| `var`   | ✅       | `undefined` | ✅                             |
| `let`   | ✅       | ❌           | ❌                             |
| `const` | ✅       | ❌           | ❌                             |

### Function Declaration 
| Type                         | Hoisted | Callable before definition |
| ---------------------------- | ------- | -------------------------- |
| Function Declaration         | ✅       | ✅                          |
| Function Expression (`var`)  | ⚠️      | ❌                          |
| Arrow Function (`let/const`) | ❌       | ❌                          |


## TDZ (Temporal Dead Zone) in JavaScript
- TDZ (Temporal Dead Zone) is the time between entering a scope and initializing a let or const variable, during which accessing that variable throws a ReferenceError.
```js
console.log(a); // ❌ ReferenceError (TDZ)
let a = 10;
```
- 2️⃣ Why TDZ Exists? 🤔
    - TDZ was introduced to:
    - Prevent bugs caused by hoisting
    - Force clean and predictable code
    - Avoid accidental usage of uninitialized variables
```js
function test(x = y, y = 10) {
  console.log(x);
}
test(); // ❌ ReferenceError
```
> y is in TDZ when x = y runs

## 