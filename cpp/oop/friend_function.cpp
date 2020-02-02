#include<iostream>
#include<string>

using namespace std;

class Human{

private:
    string name;
    int age;

public:
    Human(string iname, int iage){
        name = iname;
        age = iage;
    }

    void tellMe(){
        cout<<name<<endl<<age<<endl;
    }

    friend void display(Human man); //Non member function of the Class having access to the private data
};

void display(Human man){
    cout<<man.name<<endl<<man.age<<endl;
}

int main(){

    Human anil("anil", 24);
    display(anil);

    return 0;
}

//https://www.geeksforgeeks.org/friend-class-function-cpp/
