#include <iostream>
using namespace std;

int factorial(int n){
     if(n<=2) return n;
     return n*factorial(n-1);
}

bool IsVowel(char a){
    return string("aeiouAEIOU").find(a)!=string::npos;
}

int main(){
    cout <<factorial(5) <<"\n" <<IsVowel('a') <<" " <<IsVowel('b') <<" " <<IsVowel('d') <<" " <<IsVowel('O') <<" ";
}