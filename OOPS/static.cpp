#include <iostream>
using namespace std;

class Base {
public:
    static  void show() {
        cout << "Base static show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived static show()" << endl;
    }
};

int main() {
    Base *b1 ;
    Derived d1;
    b1 = &d1;
    b1->show();
}
