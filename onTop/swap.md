1. using temp var 

2. 🔹 3️⃣ Using Addition & Subtraction (No extra variable)

int a = 5, b = 10;
a = a + b;
b = a - b;
a = a - b;

⚠️ Risk of integer overflow
❌ Not safe for large values


3. 🔹 5️⃣ Using XOR Bitwise Operator (Classic Interview Trick)
int a = 5, b = 10;
a = a ^ b;
b = a ^ b;
a = a ^ b;
- ❌ Fails if both variables refer to same memory
    - First XOR zeros the value
    - No backup exists
    - Data is destroyed
4. 🔹 9️⃣ Using Arithmetic + Reference Trick (Rare)

>   a = a + b - (b = a);

> a = a^b^(b=a)