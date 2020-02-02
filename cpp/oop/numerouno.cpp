#include<iostream>
#include<string>

using namespace std;

class Human{

private:
    string name;
    int age;

public:
    Human(){
        name = "no_name";
        age = 0;
        cout<<"Default Constructor"<<endl;;
    }

    void display(){
        cout<<name<<endl<<age<<endl;
    }
};

int main(){

    Human homoSepian;

    homoSepian.display();

    return 0;
}
