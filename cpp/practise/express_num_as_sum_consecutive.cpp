#include<bits/stdc++.h>

using namespace std;

//Count ways to express a number as sum of consecutive numbers

long int countNum(long int N){

    long int ctr=0;
    for(long int L =1; (L*(L+1))/2 <2*N; L++){

    float a = (1.0*N-(L*(L+1))/2) /(L+1);

    if(a-int(a)==0.0)
        ctr++;
    }

    return ctr;
}

int main(){

    long int N =15;

    cout<<countNum(N)<<endl;
    N=10;
    cout<<countNum(N)<<endl;
    return 0;
}
