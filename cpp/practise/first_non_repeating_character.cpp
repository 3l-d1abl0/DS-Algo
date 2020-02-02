#include<bits/stdc++.h>

using namespace std;

char firstRep(string s){

    int len = s.length();

    int cnt[26];
    memset(cnt, -1, sizeof(cnt));

    for(int i=0;i<26;i++){
            cout<<s[i]<<" :"<<cnt[i]<<"  ";
    }
    cout<<endl<<endl;


    for(int i=0; i<len;i++){

        if(cnt[s[i]-'A']== -1){
            cnt[s[i]-'A'] = i;
        }else{
            cout<<"double ::"<<s[i]<<s[i]-'A'<<endl;
            cnt[s[i]-'A']= -2;
        }

    }

    for(int i=0;i<26;i++){
            cout<<s[i]<<" :"<<cnt[i]<<"  ";
        if(cnt[i]>=0){
            cout<<endl;
            return s[i];
        }
    }

}

int main(){

    string s ="ADBCGHIEFKJLADTVDERFSWVGHQWCNOPENSMSJWIERTFB";

    cout<<firstRep(s)<<endl;

    return 0;
}


//A(65)-Z(90)
//a(90)-z(122)
