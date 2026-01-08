#include <iostream>
using namespace std ;

void swap(int& a , int& b){
    int temp = a;
    a=b; b=temp;
}
void swap2(int& a , int& b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main () {
    int a = 0;
    int b = 10;

    // int z = 10;
    // int &a =z;
    // int &b =z; 

    // a = a^b;
    // b = a^b;
    // a = a^b;

    cout <<a <<" " <<b <<endl;
    swap(a,b);
    cout <<a <<" " <<b <<endl;
    swap2(a,b);
    cout <<a <<" " <<b <<endl;
    swap2(b,b); // LOST VALUE OF b BEACUSE XOR doesnt work when both values refer to same memory.
    cout <<a <<" " <<b <<endl;

}