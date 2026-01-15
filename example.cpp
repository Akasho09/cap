#include <iostream>
using namespace std;

class Base {
public:
    inline virtual void f() {
        cout << "Base\n";
    }
};

class Derived : public Base {
public:
    void f() override {
        cout << "Derived\n";
    }
};
void reverse(vector<int>&v){
    int n = v.size();
    for(int i=0;i<(n+1)/2;i++){
        v[i]^=v[n-i-1];
        v[n-i-1]^=v[i];
        v[i]^=v[n-i-1];
    }
}

void print(int n){
    char p = 'a';
    for(int i=0;i<n;i++){
        cout <<p++ <<" ";
    }
    p--;
    for(int i=1;i<n;i++){
        cout <<--p <<" ";
    }
    cout <<endl;
}


int main() {

    for(int i=1;i<=5;i++){
        print(i);
    }


    // Derived d;
    // d.f();   // ❌ cannot inline

    // vector<int>v({1,2,3,4,5});
    // reverse(v);
    // for(int i : v){
    //     cout <<i <<" ";
    // }

}