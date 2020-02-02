#include<bits/stdc++.h>

using namespace std;

int CountPS(string str){

    int ans=0;
    for(int i=0; i<str.length(); i++){

        for(int j=0; j<str.length() && i-j>=0; j++){

                if( (i-j) == (i+j) )
                    continue;
                if(str[i-j]!= str[i+j])
                    break;
                else{
                  // cout<<"i  ::"<<i-j<<" j ::"<<i+j<<endl;
                    ans++;
                }


        }

    }

    for(int i=0; i<str.length(); i++){

        for(int j=0; j<str.length() && i-j>=0; j++){

                if( i+j+1 == i-j)
                    continue;

                if( str[i-j]!= str[i+j+1])
                    break;
                else{
                   //cout<<"i  ="<<i-j<<" j = "<<i+j+1<<endl;
                    ans++;
                }
        }
    }
    return ans;
}

int main(){

    //char str[] = "abaab";
   // char str[] = "abbaeae";
    char str[] = "abaab";
    int n = strlen(str);
    cout << CountPS(str) << endl;
    return 0;

    return 0;
}
