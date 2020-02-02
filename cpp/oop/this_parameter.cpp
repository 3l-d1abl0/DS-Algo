#include<iostream>

using namespace std;


class Person{
private:
    int age;
    int height;

public:
    void setAge(int iage){
        age = iage;
    }
    void setHeight(int height){
        this->height = height;
    }
    void display(){
        cout<<"Age :: "<<this->age<<" Height :: "<<this->height<<endl;
    }
};

int main(){

    Person p1;
    p1.setAge(90);

    p1.setHeight(7);

    p1.display();

    return 0;
}
