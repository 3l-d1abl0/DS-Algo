#include<iostream>
#include<cstring>

using namespace std;

//invoking methods of base class from object of derived class

class Person{

public:
    void introduce(){
        cout<<"Hey Person !!!"<<endl;
    }
};

class Student : public Person{

public:
    void introduce(){
        cout<<"Hey Student !!!"<<endl;
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
    s1.introduce();

    whoisthis(&s1);

    return 0;
}
