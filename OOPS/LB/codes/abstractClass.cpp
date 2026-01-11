#include <iostream>
using namespace std;

class abstractClass{
public:
abstractClass(){
    cout <<"abstractClass called\n";
}
virtual void HaavNaav() = 0;
};

class derived : public abstractClass{
public :
derived(){
    cout <<"derived Class called\n";
}
void HaavNaav(){
    cout <<"derived class HaavNaav\n";
}
};


int main(){
    // abstractClass a1 ; // compile time error
    abstractClass * a; // allowed
    abstractClass & a2 = *a; // allowed , only Pointer or reference to abstract class
    // a->HaavNaav(); // RUNTIME ERROR 
    derived d1 ;
}