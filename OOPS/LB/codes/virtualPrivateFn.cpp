#include <iostream>
using namespace std;

class Base {
private:
    virtual void show() {
        cout << "Base show";
    }

public:
    void display() {
        show();   // ✔ allowed: inside the class
    }
};

class Derived : public Base {
private:
    void show() {
        cout << "Derived show";
    }
public:
    void display() {
        show(); 
    }
};

int main() {
    Base* b = new Derived();
    b->display();   // ✔ Calls Derived's show()
}
