## 1.What is an array?
- An array is a collection of similar elements that are stored together in a single contagious memory location. In an array all the elements are of the same or similar data type.
> We cannot store elements of different datatype in an array.

## An Armstrong number 
- (or narcissistic number) is a number that equals the sum of its own digits, each raised to the power of the total number of digits in the number
> like 153 (1³ + 5³ + 3³ = 1 + 125 + 27 = 153) or 1634 (1⁴ + 6⁴ + 3⁴ + 4⁴ = 1 + 1296 + 81 + 256 = 1634).
```c
#include <cmath>
cout << pow(5, 3);
```

## 🆚 DDL vs DML (Quick Comparison)
| Feature             | DDL                        | DML                        |
| ------------------- | -------------------------- | -------------------------- |
| Full Form           | Data Definition Language   | Data Manipulation Language |
| Purpose             | Defines database structure | Manipulates data           |
| Affects             | Schema                     | Table records              |
| Transaction Control | ❌ No rollback              | ✅ Rollback possible        |
| Auto Commit         | Yes                        | No                         |
| Examples            | CREATE, DROP               | INSERT, UPDATE             |


## What are Pointers?
- A pointer is a variable that stores the memory address of another variable instead of storing the value directly.
> A pointer points to the location in memory where a variable is stored.
> A null pointer is a pointer that does not point to any valid memory location.

### ⚠️ Why Use a Null Pointer?
- To avoid garbage addresses
- To check if a pointer is valid before use
- To indicate no object is assigned

### ❓ Why isn’t nullptr the default value of pointers?
- Because C++ does not automatically initialize local variables (including pointers) for performance and control reasons.

