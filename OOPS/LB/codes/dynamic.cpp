#include <iostream>
using namespace std ;

class Vers{
    string name;
    int marks ;

public: 
    Vers() = delete;
    Vers(string naav){
        name = naav;
    }    
    string getName(){
        return name ;
    }
    int getMarks(){
       return marks ;
    }
};

class Student {
    int id;
public:

    Student() = delete; // Prevents object creation.
    // Student() { 
    //     cout <<"Default Constructor" ;
    //  }
    Student(int x) { 
        cout <<"Parametrized Constructor" ;
        id = x; 
    }
    Student(const Student &s) {
        cout <<"Copy Constructor" ;
        id = s.id;
    }
    Student(Student& s) {
        cout <<"Move Constructor" ;
        id = s.id;
        // s.id = NULL;
    }


};

int main () {
    // Static Initliztion
    Vers v1("Akash");
    cout <<v1.getMarks() <<endl; // Static => Garbage value for marks initially

    Vers *v2 = new Vers("Ahmad");
    cout <<v2->getMarks() <<endl; // Dynameic => 0 initoally. 
    cout <<(*v2).getMarks() <<endl; // Derefrencing of pointer then using . to acesses


    Student s1(12);
}