#include <iostream>
using namespace std;

class Engine{
public:
    Engine() {
        cout << "Engine Constructor called\n";
    }
    ~Engine() {
        cout << "Engine Des called\n";
    }
};

class Test {
    static Engine e1 ;
public:
    Test() {
        cout << "Test Constructor called\n";
    }
    ~Test() {
        cout << "Test des called\n";
    }
};

Engine Test::e1;
 
int main() {
    Test t;
    Test t2;
}