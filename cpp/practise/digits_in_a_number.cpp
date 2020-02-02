#include<bits/stdc++.h>>

using namespace std;

int main(){

    int T;
    long long int N;

    scanf("%d", &T);

    while(T--){

     scanf("%lld", &N);

     cout<<N<<" :: "<<floor(log(N*(2)+1)/log(3))<<endl;

    }

    return 0;
}
