#include <iostream>
using namespace std;

class Test {
public:
     Test() { cout << "Constructor called\n"; }
     virtual ~ Test() { cout << "Destructor called\n"; }
};

class Derived : public Test {
public:
     Derived() { cout << "Derived Constructor called\n"; }
    ~Derived() { cout << "Derived Destructor called\n"; }
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
    // func();
    // func();

    Test *t1 = new Derived();
    delete t1;
}