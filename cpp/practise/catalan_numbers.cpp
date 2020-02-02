#include<bits/stdc++.h>


using namespace std;

unsigned long int DP[11];

unsigned long int catalan(int n){

    if(n<=1)    return 1;

        unsigned long int res =0;
        for(int i=0; i<n;i++)
            res += catalan(i)* catalan(n-1-i);

    return res;
}



void catalanDP(int n){

    DP[0] = DP[1] =1;

    for(int i=2; i<=n;i++){
            DP[i]=0;

            for(int j=0; j<i; j++)
                DP[i]+= DP[j] * DP[i-1-j];
    }
}

unsigned long int comb(int n, int k){

    if(k > n-k)
        k = n-k;

    unsigned long int res =1;

    for(int i=0; i<k; i++){
        res  *= (n-i);
        res  /= (i+1);
    }

    return res;
}

unsigned long int Catalan(int n){

    if(n==0 ) return 1;

    unsigned long int c =comb(2*n, n);
    //cout<<"C ::"<<c<<endl;
    return c/(n+1);

}

int main(){

    //catalanDP(10);
    //for(int i=0;i<=10;i++)
        //cout<<"For i="<<i<<" :: "<<DP[i]<<endl;

    for(int i=0;i<=10;i++)
        cout<<"For i= "<<i<<" :: "<<Catalan(i)<<endl;

    return 0;
}
