## Odd , Even
if (n & 1) cout << "Odd";
else cout << "Even";

## 2️⃣ Multiply / Divide by 2
n << 1   // n * 2
n >> 1   // n / 2

## 3️⃣ Check if a number is power of 2
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

## 🔹 Bit Operations on Positions

### 4️⃣ Set the i-th bit
n = n | (1 << i);

### 5️⃣ Clear the i-th bit
n = n & ~(1 << i);

### 6️⃣ Toggle the i-th bit
n = n ^ (1 << i);

### 7️⃣ Check if i-th bit is set
bool set = (n & (1 << i)) != 0;

## 🔹 Powerful Tricks

### 8️⃣ Remove the lowest set bit
n = n & (n - 1);

### 9️⃣ Get the lowest set bit
int lowestBit = n & (-n);

## 🔟 Count set bits (Brian Kernighan’s Algorithm)
int count = 0;
while (n) {
    n = n & (n - 1);
    count++;
}
> ⏱ Faster than checking all 32 bits

## 🔹 XOR Tricks (Very Important)

### 1️⃣1️⃣ Find the unique element (others appear twice)
int ans = 0;
for (int x : arr) ans ^= x;

### 1️⃣2️⃣ Swap two numbers (without temp)
a = a ^ b;
b = a ^ b;
a = a ^ b;

### 1️⃣3️⃣ Find two unique numbers (others twice)
int xr = 0;
for (int x : arr) xr ^= x;

int diffBit = xr & -xr;

int a = 0, b = 0;
for (int x : arr) {
    if (x & diffBit) a ^= x;
    else b ^= x;
}

## 🔹 Range / Mask Tricks

### 1️⃣4️⃣ Create a mask with last k bits set
int mask = (1 << k) - 1;

### 1️⃣5️⃣ Clear all bits from LSB to i-th bit
n = n & (~((1 << (i + 1)) - 1));

### 1️⃣6️⃣ Clear all bits from MSB to i-th bit
n = n & ((1 << i) - 1);

## 🔹 Math + Bit Hacks

### 1️⃣7️⃣ Check if numbers have opposite signs
if ((x ^ y) < 0)

### 1️⃣8️⃣ Absolute value (without branching)
int mask = n >> 31;
abs = (n + mask) ^ mask;

### 1️⃣9️⃣ Fast modulo for power of 2
n % (2^k) == n & ((1 << k) - 1)

## 🔹 Subset Generation (Very Popular)

### 2️⃣0️⃣ Generate all subsets of a set
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // include element i
        }
    }
}
