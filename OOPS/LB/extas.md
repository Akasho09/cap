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
