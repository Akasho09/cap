#include <iostream>
using namespace std;

class eg {
public:

    eg(){
        cout <<"Obj created\n";
    }
    static int a;

    static int f1 (){
        return a;
    }

    ~eg(){
        cout <<"Obj Destroyed\n";
    }
};

void func(){
    // Local Static Object
    static eg t1; // Static object
}

// Global Static Object
// static eg obj;

int eg::a = 0;

int main () {
    // cout << eg::a <<endl;
    // cout << eg::f1() <<endl;

    cout <<"Non-Static  1 \n";
    {
        eg t1;        // Non-Static object
    }

    cout <<"After this \n\n";

    cout <<"static 2\n";
    {
        static eg t1;        // Static object
    }

    cout <<"After this \n";


}