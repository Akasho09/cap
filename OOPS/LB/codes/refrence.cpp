#include <iostream>
using namespace std ;

int main() {

    int x = 10;
    int &ref = x;

    x=20;
    ref=40;
    cout <<x <<endl;
    cout <<ref <<endl;
}