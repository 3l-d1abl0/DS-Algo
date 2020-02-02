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
    Human(string n){
        cout<<"Name as Parameter !"<<endl;
        name = n;
    }
    Human(int a){
        cout<<"Age Parameter"<<endl;
        age=a;
    }
    Human(string n, int a){
        cout<<"Two Parameter"<<endl;
        name = n;
        age= a;
    }

    void display(){
        cout<<name<<endl<<age<<endl;
    }
};

int main(){

    //Default
    Human homoSepian;
    homoSepian.display();

    //Name
    Human h1("Very First Human");
    h1.display();

    //Age
    Human h2(112);
    h2.display();

    //Two Parameter
    Human h3("Hendricks", 29);
    h3.display();
    return 0;
}
