#include <iostream>
using namespace std;

class Car{
public:
    int weight ;
     Car(int x) {
        weight=x;
        cout <<weight <<" \n";
    }

    virtual ~Car(){} ;
};

class Maruti : public Car{
    string color;
public:
    Maruti(int x , string c){
        color=c;
    }

    void carDetails(){
        cout <<color <<" \n";
    }
};

int main(){
    Car *m1 = new Maruti(230 , "Blue");
}