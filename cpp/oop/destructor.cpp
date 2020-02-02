#include<iostream>
#include<string>

using namespace std;

class Human{

private:
    string *name;
    int *age;

public:

    Human(string iname, int iage){
        name = new string;
        age = new int;

        *name = iname;
        *age = iage;
    }

    void display(){
        cout<<"Hi I am "<<*name<<" and i am "<<*age<<" Years OLd "<<endl;
    }

    ~Human(){
        delete name;
        delete age;
        cout<<"Destructor Called !"<<endl;
    }


};

int main(){

    Human *h1;
    //h1 = new Human;
    h1 = new Human("Batman", 34);
    h1->display();
    cout<<"Middle Line"<<endl;

    delete h1;

    return 0;
}
