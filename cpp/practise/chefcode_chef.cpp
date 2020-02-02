#include<bits/stdc++.h>

using namespace std;

int X[32769];   //2^15
int Y[32769];

void calcProd(int arr[], int N, int a[], int sz, int offset){

    int set = 1<<sz;

    for(int i=0; i<sz; i++){
        long long int prod=1;
        for(int j=0; j<sz; j++)
            if(i & (1<<j) )
                prod*=arr[j+offset];

        a[i]= prod;
    }

}

long long int subSProd(int arr[], int N, int K){

    //cal subsetprod for half
    calcProd(arr,N, X, N/2, 0);     int szX = 1<< N/2;
    calcProd(arr,N, Y, N-N/2, N/2);     int szY = 1<< (N-N/2);

    sort(X, X+szX);
    cout<<"szX = "<<szX<<"szY = "<<szY<<endl;

    for(int i=0; i<szX; i++)
        cout<<X[i]<<" ";
    cout<<endl;

    for(int i=0; i<szY; i++)
        cout<<Y[i]<<" ";
    cout<<endl;

    int ans =0;
    for(int i=0; i<szY; i++){

            cout<<"Y "<<Y[i]<<" Search .. "<<K/Y[i]<<endl;
            int idx = lower_bound(X, X+szX, K/Y[i]) - X;
            cout<<"idx = "<<idx<<endl;
            if(idx == szX && X[idx]!=K/Y[i])
                ans+=idx;
            else
                ans+=(idx+1);

            cout<<"ans = "<<ans<<endl;
    }

    return ans;
}


int main(){

    int arr[35];
    int N;
    long long int K;
    cin>>N>>K;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    cout<<subSProd(arr, N,K)<<endl;
    return 0;
}
