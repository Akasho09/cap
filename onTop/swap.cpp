#include <iostream>
using namespace std ;

int main () {
    // int a = 0;
    // int b = 10;

    int z = 10;
    int &a =z;
    int &b =z; 

    a = a^b;
    b = a^b;
    a = a^b;

    cout <<a <<" " <<b <<endl;
}