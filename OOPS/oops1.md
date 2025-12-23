## Question 2. Explain the concept of Object Oriented Programming (OOP).
- OOP is a way of designing and writing programs using objects.
- An object is like a real world thing that has properties (called attributes) and can do things (called methods). These objects are created from classes, which are like blueprints or templates.

## The main ideas in OOP are:
1. ***Encapsulation***: 
- Encapsulation is the OOP principle of wrapping data (variables) and methods (functions) together into a single unit (class) and restricting direct access to the data.
> In simple words: data hiding + controlled access.
### How Encapsulation Works in C++
- Use classes
- Make data members private
- Access them using public methods (getters/setters)
### Example 
- getters and setters.
- 
| Without Encapsulation | With Encapsulation  |
| --------------------- | ------------------- |
| Data is public        | Data is private     |
| No validation         | Validation possible |
| Less secure           | More secure         |
| Hard to maintain      | Easy to maintain    |

### 🧠 Real-Life Example
1. ATM Machine
- You cannot directly access balance
- You use methods like withdraw() or checkBalance()
- Balance is protected → Encapsulation
> using access specifiers.

2. ***Abstraction***: 
- Hiding complex details and only showing what’s needed. For example, you don’t need to know how a car works inside to drive it, just how to use the steering wheel.
- Abstraction is the OOP principle of showing only essential features of an object and hiding internal implementation details.
> In simple words: what an object does, not how it does it
### 🔹 Why Abstraction is Needed
- Reduces complexity
- Improves code readability
- Allows focusing on high-level logic
- Makes systems easy to modify and scale
- 🔹 6️⃣ Enables Polymorphism
    - Base class pointer can point to different objects
    - Behavior decided at runtime.

### 🔹 How Abstraction is Achieved in C++
1. 1️⃣ Abstract Class
- An abstract class is a class that cannot be instantiated (you cannot create its object) and is used to define a common interface for derived classes.
- 👉 A class becomes abstract if it has at least one pure virtual function.
```c
class Shape {
public:
    virtual void draw() = 0;  // pure virtual function
};
```
- Shape is an abstract class
- It represents what a shape can do (draw)
- It does NOT define how to draw

### 📌 What is a Pure Virtual Function?
- A pure virtual function is a function that:
- Has no implementation in the base class
- Is declared using = 0
- Must be overridden by derived classes

### 3️⃣ Derived Class Implements Abstraction
```cpp
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle";
    }
};
```
### 4️⃣ Using Base Class Pointer (Key to Abstraction)
```c
int main() {
    Shape* s;
    Circle c;
    s = &c;
    s->draw();   // Drawing Circle
}
```
### 🔍 What’s happening?
- User uses Shape interface
- Actual object is Circle
- User doesn’t care how draw() works internally
- 👉 This is abstraction in action

- EXAMPLE :
    1. Example: Abstraction in Header files
    > pow() method present in math.h header file. 

    2. Abstraction using Abstract keyword
    > Note: C++ does not have any abstract keyword like Java or C#.  Instead, abstraction is implemented using pure virtual functions in base classes.

    | Abstraction                     | Encapsulation                    |
    | ------------------------------- | -------------------------------- |
    | Hides implementation            | Hides data                       |
    | Focuses on **what**             | Focuses on **how**               |
    | Achieved using abstract classes | Achieved using access specifiers |
    | 'Design-level concept'          | 'Implementation-level concept'   |


3. ***Inheritance***: A way to create new objects based on existing ones. It’s like how a child inherits traits from their parents.
- Inheritance is an OOP concept where a new class (derived/child) acquires the properties and behaviors of an existing class (base/parent).
> In simple words: reusing existing code by creating a new class from another class
### 🔹 Why Inheritance is Used
- Code reusability
- Reduces duplication
- Makes programs easier to maintain
- Supports polymorphism
![alt text](image.png)

### 🔹 Access Specifiers in Inheritance
| Base Member | Public Inheritance | Protected Inheritance | Private Inheritance |
| ----------- | ------------------ | --------------------- | ------------------- |
| Public      | Public             | Protected             | Private             |
| Protected   | Protected          | Protected             | Private             |
| Private     | ❌ Not accessible   | ❌                     | ❌                   |
> Inheritance is an OOP concept in which a derived class acquires the properties and methods of a base class, enabling code reuse and supporting polymorphism.
> The default inheritance type of a class in C++ is private, while for a struct it is public.


4. Polymorphism: 
- It means using the same name for actions, but the action works differently depending on the object. For example, a dog and a cat both have a “speak” method, but they say different things.
- In OOP, it allows the same function or method name to behave differently based on the object or context.
> In simple words: one interface, many implementations

### 🔹 Why Polymorphism is Needed
- Improves flexibility
- Supports code reusability
- Enables dynamic behavior
- Makes code easier to extend and maintain

### 🔹 Types of Polymorphism in C++
1. 1️⃣ Compile-Time Polymorphism
(Also called Static Polymorphism)
- Achieved using:
1. **Function Overloading** : 
- Function overloading allows us to define multiple functions with the same name but different parameters. It is a form of compile time polymorphism in which different functions with same name can perform different jobs based on the different parameters passed.
```c
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
    double add(double a, double b){
        return a + b;
    }
    int add(int a, double b) { 
    return a + (double)b;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;
    cout << m.add(2, 3, 4);
}
```
### Different Ways of Function Overloading
- By having different number of parameters.
- By having different types of parameters.
- By having both different number and types of parameters

### Functions that Cannot be Overloaded :
1. Member function declarations with different access specifier but same name and same parameter-type-list cannot be overloaded.
2. Functions with parameter declarations that differ only in a pointer * versus an array [].
3. Functions with same parameter but different passing method (i.e. passed by value and passed by reference).
4. Function with same parameter but different volatile type specifier.
5. 3️⃣ Functions Differing Only by Default Arguments
- Default arguments are not part of function signature.
```c++
void show(int x);
void show(int x, int y = 10);  // ❌ Error
```

### Why functions cannot be overloaded based on return type?
> C++ doesn't allow function overloading by changing the return type. It is because the return type is not included in the function call, due to which the compiler won't be able to distinguish between them resulting in ambiguity issue. Therefore, we cannot achieve function overloading by changing the return type only.

2. **Operator Overloading** : 
Operator overloading means giving a new meaning to an operator (like +, -, *, []) when it is used with objects.
- With operator overloading, we can make operators work for user defined classes structures.
- It is an example of compile-time polymorphism.
### Why use Operator Overloading?
- Allows objects to behave like basic data types.
- Useful for mathematical objects like Complex numbers and Vectors.
- Reduces the need for extra function calls.

