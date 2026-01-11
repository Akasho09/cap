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
   