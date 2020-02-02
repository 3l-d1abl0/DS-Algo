#include<iostream>
#include<string>

using namespace std;

class Person{

public:
    void intro(){
        cout<<"Its a Person"<<endl;
    }
};

class Student : public Person{

public:
    void intro(){
        cout<<"Its a Student"<<endl;
    }
};

int main(){

    Student s1;
    s1.intro(); //will overide the function in the Base Class

    s1.Person::intro(); //Explicitly calling the base class function

    return 0;
}
