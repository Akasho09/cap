#include <iostream>
using namespace std;

class explicitClass{
    int x ;
public:

explicit explicitClass(int a){
    x=a;
}
explicit explicitClass(char a[]){
    x=stoi(a);
}
void display(){
    cout <<x <<endl;
}
};

void fn(explicitClass e1){
    e1.display();
}

int main(){
    explicitClass e1(10); // allowed 
    explicitClass e3({10}); // allowed
    fn(explicitClass(13)); // allowed

    explicitClass e2 = 10; // not allowed
    fn(10); // not allowed
    fn("10"); // not allowed
}