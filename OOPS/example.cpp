#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
    void draw(){
        cout <<"Drawing Circle";
    }
};

int main() {
    Shape* s;
    Circle c;
    s = &c;
    s->draw();   // Drawing Circle
}
