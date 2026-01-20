#include <iostream>
using namespace std;

class A;

class B {
    public:
    // int getprivateDatafromB(A a){
    //     return a.privateData;
    // }
};


class A {
    int privateData;
public:
    A(){};
    A(int d){
        privateData=d;
    }
    // makes whole class friend
    friend class B ; // friend class 
    friend int globalFriendFunction(A a);
    friend int C::inMemberFriendFunction(A a); // makes only this fn friend
};

int globalFriendFunction(A a){
    return a.privateData;
}
int C::inMemberFriendFunction(A a){
    return a.privateData;
}

int main() {
    A a1(42);
    B b1;
    // cout <<"b1.getprivateDatafromB(a1) : " <<b1.getprivateDatafromB(a1) <<endl;
    C c1;
    cout <<"c1.inMemberFriendFunction(a1): " <<c1.inMemberFriendFunction(a1) <<endl;
    cout <<"globalFriendFunction(): " <<globalFriendFunction(a1) <<endl;
    return 0;
}
