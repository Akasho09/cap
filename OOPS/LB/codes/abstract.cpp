#include <iostream>
using namespace std;

class Shape {
public:
    Shape(){
        cout << "Abstract class ctor \n";
    }
    virtual void draw() = 0;  // pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

int main() {
    Shape* s = new Circle();  // ✅ allowed
    s->draw();

    // Shape obj; ❌ ERROR (cannot instantiate)
}
