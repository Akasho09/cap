#include <iostream>
using namespace std ;

class example {
public:
    int *a;

    example(int c){
        a=new int(c);
    }

};

class example2 {
public:
    int *a;

    example2(int c){
        a=new int(c);
    }

    // DEEP COPY DEFINED MANUALLY.
    example2(example2 & temp){
        this->a = new int(*temp.a);
    }

};

int main () {
    // example *e1 = new example(5);
    // example ee1(55);

    // example *e2(e1);
    // example *e3 = e1;
    // example e4 = *e1;
    // example e5(*e1);

    // example ee2 = ee1;
    // example ee3(ee1);

    // *e1->a=6;
    // *ee1.a=66;
    // cout <<*e2->a <<endl; // shallow copy
    // cout <<*e3->a <<endl;  // shallow copy
    // cout <<*e4.a <<endl;  // shallow copy
    // cout <<*e5.a <<endl;  // shallow copy

    // cout <<*ee2.a <<endl;  // shallow copy
    // cout <<*ee3.a <<endl;  // shallow copy

    example2 *e21 = new example2(5); // POINTER TO A OBJECT  
    example2 ee21(55); // NEW OBJECT 

    example2 *e2(e21); // POINTER TO POINTER => SHALLOW COPY 
    example2 *e3 = e21; // same 
    example2 e4 = *e21; // NEW OBJECT AND DEEP COPY DEFINED IN CLASS => DEEP COPY .
    example2 e5(*e21); // same.

    example2 ee2 = ee21;
    example2 ee3(ee21);

    *e21->a=6;
    *ee21.a=66;
    cout <<*e2->a <<endl; // shallow  copy
    cout <<*e3->a <<endl;  // shallow copy
    cout <<*e4.a <<endl;  // deep copy
    cout <<*e5.a <<endl;  // deep copy

    cout <<*ee2.a <<endl;  // deep copy
    cout <<*ee3.a <<endl;  // deep copy

    cout <<endl <<endl ;

}

