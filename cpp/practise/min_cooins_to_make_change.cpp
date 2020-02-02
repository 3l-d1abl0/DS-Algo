#include<bits/stdc++.h>

using namespace std;

void print2DArray(int *arr, int sz, int val){

    for(int i=0; i<sz; i++){
        for(int j=0; j<=val; j++){
            //cout<<arr[i][j]<<" ";
            cout<<*((arr+i*val) + j)<<" ";
        }
        cout<<endl;
    }
}

void memset2D(int *arr, int sz, int val, int init){

    for(int i=0; i<sz; i++){
        for(int j=0; j<=val; j++){
            *( (arr+i*val) + j) = init;
        }
        cout<<endl;
    }
}

int minCoinsForChange(int arr[], int sz, int val){

    int dp[sz][val+1];

    memset2D((int *)dp, sz, val, 0);

    for(int i=0; i<sz; i++){
        for(int j=0; j<=val; j++){

            if(j==0){
                dp[i][j]=0;
            }

            if(j<arr[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-arr[i]]);
            }
        }
    }

    //print2DArray(dp, sz, val);
    print2DArray((int *)dp, sz, val);

    return dp[sz-1][val];

}

int main(){

    int arr [] = {1,5,6,8};
    int sz = sizeof(arr)/sizeof(arr[0]);

    int val = 11;


    cout<<minCoinsForChange(arr, sz, val);


    return 0;
}
