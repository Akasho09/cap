#include <iostream>
using namespace std ;

class example {
    int b;
public:
    int *a;

    example(int c){
        *a=c;
    }

};


int main () {
    example *e1 = new example(5);
    example ee1(55);

    example *e2(e1);
    example *e3 = e1;
    example e4 = *e1;
    example e5(*e1);

    example ee2 = ee1;
    example ee3(ee1);

    *e1->a=6;
    *ee1.a=66;
    cout <<e1->a <<endl;  
    cout <<e2->a <<endl;
    cout <<e3->a <<endl;
    cout <<e4.a <<endl;
    cout <<e5.a <<endl;

    cout <<ee1.a <<endl;
    cout <<ee2.a <<endl;
    cout <<ee3.a <<endl;
}

