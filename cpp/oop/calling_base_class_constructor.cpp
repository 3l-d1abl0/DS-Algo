#include<iostream>
#include<string>

using namespace std;

class Father{

protected:
    int height;

public:
    Father(int h){
        cout<<"Costructor - Father"<<endl;
        height = h;
    }
    ~Father(){
        cout<<"Destructor Father"<<endl;
    }
    void askFather(){
            cout<<"I am Father "<<endl;
    }
};

class Mother{

protected:
    string skinColor;

public:
    Mother(string col){
        cout<<"Costructor - Mother"<<endl;
        skinColor = col;
    }
    ~Mother(){
        cout<<"Destructor Mother"<<endl;
    }

};

class Child : public Mother, public Father{

public:
    Child(int x, string col) : Father(x), Mother(col){
        cout<<"Height :: "<<height<<endl<<" Skin Color :: "<<skinColor<<endl;
        cout<<"Child Constructor "<<endl;
    }
    ~Child(){
        cout<<"Destructor Child"<<endl;
    }

    void display(){
        //cout<<"Height :: "<<height<<endl<<" Skin Color :: "<<skinColor<<endl;
    }

};

int main(){

    Child obj(7, "dark");
    return 0;
}
