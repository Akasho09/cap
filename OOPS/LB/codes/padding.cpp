#include <iostream>
#include <iomanip>
using namespace std;

// Empty class
class EmptyClass {};

// Single variable
class OneInt {
    int a;      // 4 bytes
};
class OneChar {
    char a;      // 1 bytes
};
class oneBool {
    bool a;      // 1 bytes
};

// Int + Bool
class IntBool {
    int a;      // 4 bytes
    bool b;     // 1 byte
};

// Int + Short
class IntShortInt {
    int a;      // 4 bytes
    short b;
    int c;
};

// Int + Short + Bool
class IntShortBool {
    int a;      // 4
    short b;    // 2
    bool c;     // 1
};

// Two ints + short + bool
class Int2ShortBool {
    int a;      // 4
    int b;      // 4
    short c;    // 2
    bool d;     // 1
};

// Long + int + short + bool
class LongIntShortBool {
    long a;     // 8
    int b;      // 4
    short c;    // 2
    bool d;     // 1
};

// Optimized ordering
class Example1 {
    long a;     // 8

    int b;      // 4
    int c;      // 4

    short d;    // 2
    short f;    // 2
    bool e;     // 1
    bool g;     // 1
    bool h;     // 1
    bool i;     // 1

};

class Example2 {
    short d;    // 2
    short f;    // 2
    bool e;     // 1

    int b;      // 4
    bool g;     // 1
    bool h;     // 1
    bool i;     // 1

    int c;      // 4

    long a;     // 8
};

class Example3 {
    __int128 a;  // 16
    bool b;   
};

class Example4 {
    __int128 a;  // 16
    int arr[3]; // 12
    
    __int128 geta(){
        return a;
    }
};

class Example5 {
    vector<int>v;
};

int main() {

    cout << "==== SIZE ANALYSIS (in bytes) ====\n\n";

    cout << "EmptyClass              : " << sizeof(EmptyClass) << endl;
    cout << "OneInt                  : " << sizeof(OneInt) << endl;
    cout << "OneChar                 : " << sizeof(OneChar) << endl;
    cout << "OneBool                  : " << sizeof(oneBool) << endl;
    cout << "IntBool                 : " << sizeof(IntBool) << endl;
    cout << "IntShortInt                : " << sizeof(IntShortInt) << endl;
    cout << "IntShortBool            : " << sizeof(IntShortBool) << endl;
    cout << "Int2ShortBool           : " << sizeof(Int2ShortBool) << endl;
    cout << "LongIntShortBool        : " << sizeof(LongIntShortBool) << endl;
    cout << "Example1               : " << sizeof(Example1) << endl;
    cout << "Example2               : " << sizeof(Example2) << endl;
    cout << "Example3               : " << sizeof(Example3) << endl;
    cout << "Example4               : " << sizeof(Example4) << endl;
    cout << "Example5               : " << sizeof(Example5) << endl;

    cout << "\n==== ALIGNMENT REQUIREMENTS ====\n";
    cout << "alignof(int)    = " << alignof(int) << endl;
    cout << "alignof(short)  = " << alignof(short) << endl;
    cout << "alignof(long)   = " << alignof(long) << endl;
    cout << "alignof(bool)   = " << alignof(bool) << endl;
    
    cout << "alignof(Example1)   = " << alignof(Example1) << endl;
    cout << "alignof(Example2)   = " << alignof(Example2) << endl;
    cout << "alignof(Example5)   = " << alignof(Example5) << endl;
    return 0;
}