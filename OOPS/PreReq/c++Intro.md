## Data Types in C++
1. Primitive → basic values
| Data Type | Size (typical) | Description                      |
| --------- | -------------- | -------------------------------- |
| `int`     | 4 bytes        | Stores integers                  |
| `float`   | 4 bytes        | Decimal numbers (low precision)  |
| `double`  | 8 bytes        | Decimal numbers (high precision) |
| `char`    | 1 byte         | Single character                 |
| `bool`    | 1 byte         | `true` or `false`                |
| `void`    | —              | No value                         |

2. Derived → arrays, pointers, references
    - Array , Pointer , Refrence .

3. User-defined → struct, class, enum
    - union

4. Modified → signed, unsigned, long
| Modifier   | Example           |
| ---------- | ----------------- |
| `short`    | `short int x;`    |
| `long`     | `long int y;`     |
| `signed`   | `signed int a;`   |
| `unsigned` | `unsigned int b;` |

5. Modern → auto, nullptr

## C++ Vars:
- A variable is a named memory location used to store data that can change during program execution.

## A keyword 
- is a word reserved by the C++ language to perform a specific function or represent a built-in feature.
- examples:
```c
int, float, double, char
if, else, switch
for, while, do
class, struct, union
public, private, protected
static, const, virtual
new, delete
return, sizeof
```

| Keyword              | Identifier                    |
| -------------------- | ----------------------------- |
| Reserved by language | User-defined                  |
| Has fixed meaning    | Name given by programmer      |
| Cannot be changed    | Can be anything (rules apply) |

### 🔹 How many keywords in C++?
- C++ has ~95 keywords (varies by standard)
    - Examples added over time:
    - C++11: nullptr, constexpr
    - C++20: concept, requires
   

## list , array and tuple

### list
- A list in C++ is a sequence container that allows you to store elements one after another.
> Implemented as a **doubly linked list** and maintains both front and back for fast operations on both the ends.
- Data is stored in **non-contiguous memory**, allowing fast insertion and deletion anywhere in the list (beginning, middle, or end).
```c
    list<int> myList;

    myList.push_back(10);
    myList.push_front(5);
```


### A tuple
-  is an object that can hold a number of elements. 
- The elements can be of different data types. The elements of tuples are initialized as arguments in order in which they will be accessed.  
- Tuples are a versatile data structure for grouping values. 
```c
    tuple<char, int, float> geek;
    // Assigning values to tuple using make_tuple()
    geek = make_tuple('a', 10, 15.5);
```

### Array
- A fixed-size collection of same-type elements stored contiguously.
> array has fixed size decided at compile time, while vector is dynamic and can grow or shrink at runtime.

| Feature      | Array                  | List                     | Tuple                |
| ------------ | ---------------------- | ------------------------ | -------------------- |
| Size         | Fixed                  | Dynamic                  | Fixed                |
| Mutability   | Mutable                | Mutable                  | ❌ Immutable          |
| Data type    | Same type              | Can be mixed             | Can be mixed         |
| Memory       | Contiguous             | Non-contiguous (usually) | Contiguous (logical) |
| Performance  | Fast access            | Slower than array        | Faster than list     |
| Modification | Limited                | Easy                     | ❌ Not allowed        |
| Use case     | Low-level, performance | General-purpose          | Fixed records        |

| Feature              | `array`              | `vector`               |
| -------------------- | -------------------- | ---------------------- |
| Header               | `<array>` / built-in | `<vector>`             |
| Size                 | Fixed                | Dynamic                |
| Resize               | ❌ Not possible       | ✅ Possible             |
| Memory               | Stack (usually)      | Heap                   |
| Contiguous memory    | ✅ Yes                | ✅ Yes                  |
| Performance          | Faster               | Slightly slower        |
| Bounds checking      | ❌ No                 | `.at()` provides check |
| Insertion / Deletion | ❌ Hard               | ✅ Easy                 |
| STL support          | Limited              | Full STL support       |

