#include<bits/stdc++.h>

using namespace std;

char dig[1000000];

void just_next(char num[], int n){
    int i=n;
    for(i=n-1; i>0; i--)
        if(num[i-1]<num[i])
            break;

    if(i==0){
        cout<<"-1"<<endl;
        return;
    }

    int small_i = i-1;
    int great_i = i;
    for(int j=great_i+1; j<n ; j++){
        if(num[j]>num[small_i] && num[j]<num[great_i])
            great_i = j;
    }

    swap(num[small_i], num[great_i]);

    sort(num+i, num+n);

    cout<<num<<endl;
}

int main(){

    int T,N;
    cin>>T;

    while(T--){
        cin>>N;
        int xx;
        for(int i=0; i<N;i++){
            cin>>xx;
            dig[i]= xx+'0';
        }
        //int len= strlen(dig);
        just_next(dig, N);
    }

    return 0;
}
