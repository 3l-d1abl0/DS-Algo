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

class Student : public Person{

public:
    string school;
    void display(){
        cout<<name<<endl<<school<<endl;
    }
};

class Employee : protected Person{

public:
    string eid ;
    void display(){
        cout<<name<<endl<<eid<<endl;
    }
    void setName(string iname){
        cout<<"Here = "<<endl;
        Person::setName(iname);
    }
    void set_name(string iname){
        setName(iname);
    }

};



int main(){

    Student s1;
    s1.setName("Prof X");
//    s1.name = "Prof X";       Error
    s1.school = "X";
    s1.display();
    cout<<"============"<<endl;
    Employee e1;
    e1.eid = "eid";
    e1.setName("EmployeeName");
    e1.set_name("EmployeeNameaaaa");
    e1.display();

    return 0;
}

/*
Protected
Protected, is the last access specifier, and it is similar to private, it makes class member inaccessible outside the class.
But they can be accessed by any subclass of that class. (If class A is inherited by class B, then class B is subclass of class A. We will learn this later.)

*/
