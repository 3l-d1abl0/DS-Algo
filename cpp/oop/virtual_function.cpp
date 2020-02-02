#include<iostream>
#include<cstring>

using namespace std;

class Person{

public:
    virtual void intro(){
        cout<<"Hey Person"<<endl;
    }
};

class Student : public Person{

public:
    void intro(){
        cout<<"Hey Student"<<endl;
    }
};

class Gstudent : public Student{

public:
    void intro(){
        cout<<"Hey Gstudent "<<endl;
    }
};

void whoisthis(Person &p){
    p.intro();
}

int main(){

    Person *p1 =new Student();
    p1->intro();

    Person *p2 = new Gstudent();
    p2->intro();

//   Person P1;
//   Student S1;
   Gstudent G1;
//
//   whoisthis(*p1);
//   whoisthis(*p2);
   whoisthis(G1);

    return 0;
}
