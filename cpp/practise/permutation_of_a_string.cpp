#include<bits/stdc++.h>

using namespace std;


void permute(string str, int l, int len){

    if(l==len){
        cout<<str<<endl;
    }else{

        for(int i=l; i<len; i++){
            swap(str[l], str[i]);
            permute(str, l+1, len);
            swap(str[l], str[i]);
        }

    }
}

int main(){

    string str = "ABCD";

    int len = str.length();

    permute(str, 0, len);

    return 0;
}
