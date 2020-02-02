#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    char ch[100000];
    char arr[]={'0','0','2','3','3','5','5','7','7','7'};
    cin>>ch;
    int len =strlen(ch);
    string ans="";
    int c;
    for(int i=0; i<len; i++){
        //cout<<ch[i];
        c=(ch[i]-0)%48;
        if(c==0)
            c=9;
        //cout<<arr[c]<<"::"<<c<<endl;
        if(arr[c]=='0' && ans.empty()){
            continue;
        }else{
            //char cc=(char)arr[c];
            //cout<<arr[c]<<endl;
            ans=ans+arr[c];
        }
    }
    cout<<ans;
    return 0;
}
