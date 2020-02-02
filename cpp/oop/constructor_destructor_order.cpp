#include<iostream>

using namespace std;

class Base{

public:
    Base(){
        cout<<"Constructor Base Class "<<endl;
    }
    virtual ~Base(){    /*virtual*/
        cout<<"Destructor Base Class"<<endl;
    }
};

class Derived : public Base{

public:
    Derived(){
        cout<<"Constructor Derived Class"<<endl;
    }
    ~Derived(){
        cout<<"Destructor Derived "<<endl;
    }
};

int main(){

    //Derived obj;

    Base *b1 = new Base();
    delete b1;
    cout<<"========================"<<endl;

    Base *b2 = new Derived();
    delete b2;

    cout<<"========================"<<endl;

    Derived *d2 = new Derived();
    delete d2;

    return 0;
}
