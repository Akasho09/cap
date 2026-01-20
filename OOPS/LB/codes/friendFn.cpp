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