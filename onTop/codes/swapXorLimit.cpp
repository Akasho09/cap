#include <iostream>
using namespace std;

void reverse(vector<int>&v){
    int n = v.size();
    for(int i=0;i<(n+1)/2;i++){
        v[i]^=v[n-i-1];
        v[n-i-1]^=v[i];
        v[i]^=v[n-i-1];
    }
}

int main() {
    vector<int>v({1,2,3,4,5});
    reverse(v);
    for(int i : v){
        cout <<i <<" ";
    }
}