#include<bits/stdc++.h>

using namespace std;

void multiply(int F[2][2], int M[2][2]){

  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void pow(int F[2][2], int n){

    int M[2][2] = {{1,1},{1,0}};

    for(int i=1;i<=n-1;i++)
        multiply(F, M);
}

int fib(int n){

    int F[2][2] = { {1,1}, {1, 0} };
    if(n==0) return 0;

    pow(F, n);
    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++)
            cout<<F[i][j]<<" ";
        cout<<endl;
    }
    return F[1][0];
}

void power(int F[2][2], int n){

    if(n==0 || n==1)
        return ;

    int M[2][2] = { {1,1}, {1, 0} };
    power(F, n/2);

    multiply(F, F);

    if(n%2 != 0)
        multiply(F,M);

}

int fibo(int n){

    int F[2][2] = {{1,1}, {1,0} };

    if(n==0)
        return 0;

    power(F,n);

    return F[1][0];
}


int main(){

    int n=9;

    cout<<"F :: "<<fib(n)<<endl;

    cout<<"Fibo :: "<<fibo(n)<<endl;

    return 0;
}
