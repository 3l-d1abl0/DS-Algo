#include<iostream>

using namespace std;


// https://www.geeksforgeeks.org/static-keyword-cpp/

class Human{

public:
    static int human_count; //Only one instance shared by all objects

    Human(){
        human_count++;
    }

    void humanTotal(){
        cout<<"There are "<<human_count<<" peoples in this Prog "<<endl;
    }

    static void humanCount(){   //can use only static variables
        cout<<"There are "<<human_count<<" people in this Prog. "<<endl;
    }

};

int Human::human_count =0;

int main(){

    cout<<"Count = "<<Human::human_count<<endl;

    Human h1;
    h1.humanTotal();

    Human h2;
    h2.humanTotal();

    Human h3;
    h3.humanTotal();

    Human::humanCount();    //calling static method via referencing

    return 0;
}
