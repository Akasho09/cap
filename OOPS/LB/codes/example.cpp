#include <iostream>
using namespace std;

class Test {
public:
    Test() { cout << "Constructor called\n"; }
    ~Test() { cout << "Destructor called\n"; }
};

// STATIC OBJECT CREATED ONLY ONCE 
void func() {
    static Test obj;  // static object
    cout << "Function called\n";
}

// NORMAL OBJECT CREATED AND DESTROYED WHENEVER NEW FUNCTION IS CALLED . 
void func2() {
    cout << "Function called\n";
}

int main() {
    func();
    func();
}
