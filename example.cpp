#include<iostream>
using namespace std;

class Test {
public:
   Test(Test &t) { }
   Test()        { }
};

Test fun()
{
    cout << "fun() Called \n";
    Test t;
    return t;
}

int main()
{
    Test t1;
    Test t2 = fun();
    // Test t2 (fun());
    return 0;
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