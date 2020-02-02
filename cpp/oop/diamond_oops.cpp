#include<iostream>
#include<cstring>

using namespace std;

//            A
//        B       C
//            D

class Animal{

public:
    Animal(){
        cout<<"Animal Constructor"<<endl;
    }
    int age;
    void walk(){
        cout<<"Hey Animal"<<endl;
    }

};

class Tiger : virtual public Animal{

public:
    Tiger(){
        cout<<"TIger Constructor"<<endl;
    }
    void walk(){
        cout<<"Hey Tiger"<<endl;
    }

};

class Lion : virtual public Animal{

public:
    Lion(){
            cout<<"Lion Constructor"<<endl;
    }
    void walk(){
        cout<<"Hey Lion"<<endl;
    }
};

class Liger : public Tiger , public Lion{

public:
     Liger(){
        cout<<"Liger Constructor"<<endl;
    }
    void walk(){
        cout<<"Hey Liger"<<endl;
    }
};

int main(){

    Liger li;
    li.walk();

    return 0;
}
