#include<iostream>
#include<cstring>

using namespace std;

//invoking methods of base class from object of derived class

class Person{

public:
    virtual void introduce(){
    //void introduce(){
        cout<<"Hey Person !!!"<<endl;
    }
};

class Student : public Person{

public:
    void introduce(){
        cout<<"Hey Student !!!"<<endl;
    }
};

class Farmer : public Person{

public:
    void introduce(){
        cout<<"Hey Farmer ! "<<endl;
    }
};

void whoisthis(Person *p){

    //Person *p   p->introduce
    //Person &p   p.introduce
    //Person p   p.introduce

    p->introduce();
}

int main(){

    Student s1;
    //s1.introduce();
    Farmer f1;
    whoisthis(&s1);
    whoisthis(&f1);

    return 0;
}

