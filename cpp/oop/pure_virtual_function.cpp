#include<iostream>

using namespace std;

class Person{

public:
    virtual void intro()=0;
};

//Defining pure virtual function outside class
//void Person:: intro(){
//    cout<<"Hey Person !"<<endl;
//}

class Student : public Person{

public:
    void intro(){
        cout<<"Hey Student !! "<<endl;
    }
};

int main(){

    Student s1;
    s1.intro();

    //Person p1; can't declare as its an abstract class
    return 0;
}
