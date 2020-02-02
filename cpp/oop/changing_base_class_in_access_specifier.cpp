#include<iostream>
#include<string>

using namespace std;

class Person{
protected:
    string name;

public:
    void setName(string iname){
        name = iname;
    }
};

class Student : private Person{

public:

    Person::name;   //Changing Scope from private top public

    string school;
    void display(){
        cout<<name<<endl<<school<<endl;
    }
};


int main(){

    Student s1;
    //s1.setName("Prof X");     Error
    s1.name = "Prof X";
    s1.school = "X";
    s1.display();

    return 0;
}
