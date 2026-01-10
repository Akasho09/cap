#include <iostream>
using namespace std;

class Car{
public:
    int weight ;
    Car(int x){
    weight=x;
    }
    // Why virtual function is needed
    // Base-class pointer calling derived function requires runtime polymorphism
    virtual void carDetails(){
        cout <<weight  <<"kg ";
    }
    virtual ~Car(){} ;
};

class Maruti : public Car{
    string color;
public:
    Maruti(int x , string c): Car(x){
        color=c;
    }

    void carDetails(){
        Car::carDetails();
        cout <<color <<" \n";
    }
};

int main(){
    Car *m1 = new Maruti(230 , "Blue");
    m1->carDetails();
}