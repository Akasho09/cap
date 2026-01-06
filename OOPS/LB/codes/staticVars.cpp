#include <iostream>
using namespace std;

// using static Var
int counter (){
    static int count = 0;
    count++;
    return count;
}

int countVar = 0; // using global Var

int counter2 (){
    countVar++;
    countVar2++;
    return countVar;
}

int main(){

    cout <<counter() <<" ";

    cout <<counter();

}