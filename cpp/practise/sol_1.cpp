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
    cout<<"len = "<<len<<endl;
    string ans="";
    int c;
    for(int i=0; i<len; i++){
        //cout<<ch[i];
        c=(ch[i]-0)%48;
        cout<<"C= "<<c<<endl;
        if(arr[c]==ch[i]){
            cout<<"i= "<<i<<"arrc ="<<arr[c]<<endl;
            if(arr[c]=='0' && ans.empty())
                continue;
            else
                ans=ans+arr[c];
        }else{
            cout<<"i= "<<i<<"arrc ="<<arr[c]<<endl;
            if(arr[c]=='0' && ans.empty())
                continue;
            cout<<"ic "<<i<<endl;
            ans=ans+arr[c];
            for(int ii = i+1;ii<len; ii++)
                ans=ans+'7';
            i=len+1;
        }

    }
    cout<<ans;
    return 0;
}
