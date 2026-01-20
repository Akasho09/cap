#include <iostream>
using namespace std;

class B;              // forward declaration

class A {
private:
    int x = 10;
    friend void add(A, B);
};

class B {
private:
    int y = 20;
    friend void add(A, B);
};

void add(A a, B b) {  // definition
    cout << a.x + b.y;
}

int main(){
    A a;
    B b;

     add(a,b);

}



// #include <iostream>
// using namespace std;

// class Engine{
// public:
//     Engine() {
//         cout << "Engine Constructor called\n";
//     }
//     ~Engine() {
//         cout << "Engine Des called\n";
//     }
// };

// class Test {
//     static Engine e1 ;
// public:
//     Test() {
//         cout << "Test Constructor called\n";
//     }
//     ~Test() {
//         cout << "Test des called\n";
//     }
// };

// Engine Test::e1;
 
// int main() {
//     Test t;
//     Test t2;
// }