#include<iostream>
#include<string>


using namespace std;

class Person{

public:
    string name;
    int age;

    void setName(string iname) { name = iname; }
    void setAge(int iage) { age= iage; }
};

class Student : private Person{

public:
    int id;
    void setId(int iid) { id = iid;}

    void setN(string iname){ setName(iname); }
    void setA(int iage) { setAge(iage); }

    void introduce(){
        cout<<"Hi, I am "<<name<<" and i am "<<age<<" years Old"<<endl;
        cout<<"Student Id :: "<<id<<endl;
    }

};


int main(){

    Student s1;
    s1.setN("estuent");
    s1.setA(29);
    s1.id = 111;


    s1.introduce();

    return 0;
}
