## SHORT DATA TYPE :
| Type        | Size         | Range                           |
| ----------- | ------------ | ------------------------------- |
| `short`     | 2 bytes      | −32,768 to 32,767               |
| `int`       | 4 bytes      | −2,147,483,648 to 2,147,483,647 |
| `long`      | 4 or 8 bytes | Platform dependent              |
| `long long` | 8 bytes      | Very large numbers              |

## padding and greedy alignment : 
- Padding is the extra unused memory added by the compiler to satisfy alignment requirements.
- Alignment is the rule that data must be stored at memory addresses that are multiples of its size.
ie LARGEST DATA TYPES.

=== OVERALL SIZE WILL BE MULTIPLE OF LARGEST DATA TYPES LIKE 4 OR 8.
[text](codes/padding.cpp)

## ✅ The 4 Memory Areas in a Program
| Memory Area   | Stores               | Lifetime          | Size    |
| ------------- | -------------------- | ----------------- | ------- |
| **Code/Text** | Program instructions | Entire program    | Fixed   |
| **Data**      | Global/static vars   | Entire program    | Fixed   |
| **Heap**      | Dynamic memory       | Until freed       | Large   |
| **Stack**     | Local variables      | Function lifetime | Limited |

## 🔹 What are * and & in C++?
| Symbol | Name                 | Meaning                      |
| ------ | -------------------- | ---------------------------- |
| `&`    | Address-of operator  | Gets the memory address      |
| `*`    | Dereference operator | Accesses value at an address |

> Pointer to Pointer (**)

> A reference is an alias for a variable.
int x = 10;
int &ref = x;
- ref is another name for x

## Dynamic Memory Allocation :
> Dynamic Memory Allocation (DMA) means allocating memory at runtime, not at compile time.
> 👉 Memory is taken from the heap instead of the stack.

### 🧠 Why Do We Need Dynamic Memory?
- Size is not known at compile time
- Data size changes during program execution
- We want memory to exist beyond function scope

| Feature      | Static        | Dynamic         |
| ------------ | ------------- | --------------- |
| Allocated at | Compile time  | Runtime         |
| Memory area  | Stack         | Heap            |
| Size change  | ❌ Not allowed | ✅ Allowed       |
| Deallocation | Automatic     | Manual          |
| Speed        | Faster        | Slightly slower |

### 🔹 Dynamic Memory in C++
2 ways 
1. 1️⃣ Using new and delete
```cpp
int* arr = new int[5];  // allocate array
arr[0] = 10;
arr[1] = 20;

delete[] arr;           // free memory
``` 


2. Using malloc() and free() (C-style)
```c
int* p = (int*)malloc(sizeof(int));
*p = 5;
free(p);
``` 

## 🔹 1️⃣ Stack Memory
- Stack memory is used for function calls and local variables.
- It follows LIFO (Last-In-First-Out) order.
- 🔹 Stored in Stack:
    - Function parameters
    - Local variables
    - Return addresses
    - Function call frames
- ✅ Example (C/C++)
```c
void func() {
    int x = 10;   // stored in stack
}
``` 
- 🔹 Characteristics:
    - Automatically managed
    - Very fast access
    - Limited size
    - Memory freed when function exits

## 🔹 2️⃣ Heap Memory
- Heap memory is used for dynamic memory allocation (decided at runtime).
- 🔹 Stored in Heap:
    - Objects created using new, malloc
    - Large data structures
    - Data with dynamic lifetime
```c
int* p = new int(10);   // stored in heap
```
- 🔹 Characteristics:
    - Manually managed
    - Slower than stack
    - Large size
    - Must be freed explicitly

| Feature    | Stack           | Heap            |
| ---------- | --------------- | --------------- |
| Allocation | Compile-time    | Run-time        |
| Speed      | Fast            | Slower          |
| Size       | Limited         | Large           |
| Management | Automatic       | Manual          |
| Lifetime   | Function scope  | Until freed     |
| Used for   | Local variables | Dynamic objects |
| Risk       | Stack overflow  | Memory leak     |

## How is high memory decided for stack in C/C++ programs?
1. 1️⃣ Virtual Address Space of a Process
- When a C/C++ program runs, the OS gives it a virtual address space, typically like this:


## A pointer 
- is a variable that holds the address of another variable.

### 🔹 Why Pointers Are Needed?
- ✔ Direct memory access
- ✔ Dynamic memory allocation
- ✔ Efficient parameter passing
- ✔ Data structures (linked list, tree, graph)
- ✔ Low-level system programming
```c
    int* p = &x;   // pointer storing address of x
``` 
| Operator | Meaning              |
| -------- | -------------------- |
| `&`      | Address-of operator  |
| `*`      | Dereference operator |

### 🔹 Types of Pointers
1. 1️⃣ Null Pointer
int* p = nullptr;

2. 2️⃣ Wild Pointer (Uninitialized)
int* p;   // ❌ dangerous

3. 3️⃣ Dangling Pointer
int* p = new int(10);
int* q = p;    // q points to the same memory as p
delete p;      // memory freed
> Now q is a dangling pointer

4. 4️⃣ Void Pointer
void* p;

5. 5️⃣ Pointer to Pointer
int** pp;

> A reference is an alternative name for an already existing variable.
[text](codes/refrence.cpp)


| Feature      | Reference    | Pointer       |
| ------------ | ------------ | ------------- |
| Syntax       | `int& r = x` | `int* p = &x` |
| NULL allowed | ❌            | ✅             |
| Reassignment | ❌            | ✅             |
| Dereference  | Automatic    | Manual (`*p`) |
| Safety       | Safer        | Less safe     |

> The Program Counter (PC) is a special CPU register that stores the address of the next instruction to be executed.


## Procedural Programming (POP)
- Program is written as a sequence of functions/procedures that operate on data.
- 🔹 Characteristics
    - Focus on functions
    - Data and functions are separate
    - Top-down approach
> int add(int a, int b) {
    return a + b;
}
- C is a procedural programming language, so it does not have:  

## Functional Programming (FP)
- Computation is treated as evaluation of functions, avoiding changing state.
> Functional programming offers predictable behavior, easier debugging, safer concurrency, and highly reusable code through pure functions and immutability.
- 🔹 Characteristics
    - No mutable state
    - Pure functions
    - Immutability
    - Higher-order functions
- USES :
    - POC(Proof of concept) 
> const add = (a, b) => a + b;

| Paradigm      | Focus             |
| ------------- | ----------------- |
| OOPS          | Objects & classes |
| Procedural    | Functions         |
| Functional    | Pure functions    |
| Declarative   | Desired result    |
| Logic         | Rules & facts     |
| Event-driven  | Events            |
| Data-oriented | Data layout       |


## Class vs Struct in C++
| Feature             | `class`     | `struct`   |
| ------------------- | ----------- | ---------- |
| Default access      | **private** | **public** |
| Default inheritance | private     | public     |
| OOP usage           | Yes         | Yes        |
| Methods             | Yes         | Yes        |
| Constructors        | Yes         | Yes        |

- 🔹 When to Use struct
    - ✔ For plain data structures
    - ✔ When data members should be public
    - ✔ For DTOs, configs, records
- 🔹 When to Use class
    - ✔ When enforcing encapsulation
    - ✔ When hiding implementation
    - ✔ For business logic


## using namespace std;
using namespace std; tells the compiler to use the standard library namespace (std) automatically, so you don’t have to prefix standard names with std::.
> using namespace std; allows direct access to standard library identifiers without writing std:: every time.

### What is std?
- std is a namespace
- It contains all C++ standard library components
    - cout
    - cin
    - endl
    - vector
    - string
- Namespaces prevent name conflicts.

### 🔹 Why using namespace std; is NOT recommended (Important)
- ❌ Problem 2: Large Projects
    - Pollutes global namespace
    - Hard to debug

### Best Practice (Interview Approved)
- ✔ Use std:: explicitly
    - std::cout << "Hello";

- ✔ Or import only what you need
    - using std::cout;
    - using std::endl;

## Loose coupling 
- means that components or classes depend very little on each other.
- Changes in one component have minimal or no impact on others.
- EXAMPLE -

```cpp

class sorting{
public:
    function sort() = 0;
}

class quick_sort{

};

class merge_sort{

};


int main(){
    // sorting s1 = new quick_sort();

    // Implemting merge_sort and changing only this line => whole codebase is optimized .
    sorting s1 = new merge_sort();



    ....
    s1 is at 100 times .
}
```cpp


| Aspect    | Cohesion              | Coupling              |
| --------- | --------------------- | --------------------- |
| Focus     | Inside a module       | Between modules       |
| Goal      | High                  | Low                   |
| Measures  | Responsibility focus  | Dependency            |
| Principle | Single Responsibility | Dependency management |

> 📌 Good design = High cohesion + Low coupling


