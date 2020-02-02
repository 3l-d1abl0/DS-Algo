#include<iostream>
#include<string>

using namespace std;

class Father{

public:
    int height;
    void askFather(){
            cout<<"I am Father "<<endl;
    }
};


class Mother{

public:
    int intel;
    void askMother(){
        cout<<"I am Mother"<<endl;
    }
};

class Child : public Father, public Mother{

public:
    void skParents(){
        cout<<"asking Parents"<<endl;
    }
    void display(){
        cout<<"Height :: "<<height<<" Intel :: "<<intel<<endl;
    }
    void setHeiandIntel(int hei, int intell){
        height = hei;
        intel = intell;
    }
};

int main(){

    Child obj;
    obj.setHeiandIntel(6, 1);
    obj.display();
    obj.askFather();
    obj.askMother();
    return 0;
}
