#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<vector>

#define MOD 1000000009

using namespace std;

int arr[1005][1005];

void printArr(){

    for(int i=1; i<=10; i++){

        for(int j=1; j<=10; j++)
            cout<<arr[i][j]<<" ";

        cout<<endl;
    }
}




int main(){

    int T,N,K;
    cin>>T;

    for(int i=1; i<=1000; i++)
            arr[i][i]=1;

        for(int k= 999; k>=1; k--){
            for(int n= k+1; n<=1000; n++)
                arr[k][n] = (arr[k+1][n] + arr[k][n-k] )%MOD;
        }

       // printArr();
    while(T--){

        cin>>N>>K;
        cout<<arr[K][N]<<endl;

    }

    return 0;
}
