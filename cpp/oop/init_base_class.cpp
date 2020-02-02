#include<iostream>
using namespace std;

class Base_{
    public:
        Base_( int x )
        {
        cout<<"Base Class Constructor value is"<<x<<endl;
        }
};



class InitilizerList_ : public Base_{
    public:
      InitilizerList_(): Base_( 10 ){
            cout << "InitilizerList_'s constructor" << endl;
      }

     /*
     InitilizerList_(){
        Base_(10);
        cout << "InitilizerList_'s constructor" << endl;
     }*/

};
int main()
{
InitilizerList_ il;
return 0;
}
