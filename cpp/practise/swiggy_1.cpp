#include <iostream>
#include<cstring>
using namespace std;

char ch[100000];
char prm[]={'0','0','2','3','3','5','5','7','7','7'};
int main(){
    cin>>ch;
    int len =strlen(ch);
    //cout<<"len = "<<len<<endl;
    //string ans="";
    char ans[len];

    int c;
    int last_pos =-1;
    for(int i=0; i<len; i++){

        if(ch[i]=='2' || ch[i]=='3' || ch[i]=='5' || ch[i]=='7' ){  //prm
            ans[i]=ch[i];
            if(ch[i]>'2')
              last_pos=i;
        }else{ //nt prm
            int idx = (ch[i]-0)%48;
	//cout<<"idx = "<<idx<<endl;
            if(prm[idx]=='0'){

              if(last_pos==-1){
                //cout<<"No last_prime"<<endl;
                ans[i]=prm[idx];
                for(int j=i+1; j<len; j++)
                    ans[j] = '7';
                i=len+2;
              }else{
                int last_prime = (ch[last_pos]-0)%48;
                //cout<<"last prime = "<<last_prime<<endl;
                ans[last_pos]=prm[last_prime-1];
                for(int j=last_pos+1; j<len; j++)
                    ans[j] = '7';
                i=len+2;
              }

            }else{//nt o
              ans[i]=prm[idx];
              for(int ii=i+1; ii<len; ii++)
                ans[ii]='7';
              i=len+2;
            }

        }//else


    }//fori
    int i=0;
    while(ans[i]==0)
	i++;
    for(int j=i; j<len; j++)
	cout<<ans[j];
    return 0;
}
