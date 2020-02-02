#include<bits/stdc++.h>

using namespace std;

int main(){

    int T, len;
    char st[100002];
    int cnt[26];
    cin>>T;

    while(T--){


        cin>>st;

        len = strlen(st);

        for(int i=0; i<len; i++){

            int idx = st[i]-'a';
            cnt[idx]++;

        }

    }


    return 0;
}
