#include<bits/stdc++.h>

using namespace std;

bool findMin(int arr[], int sz){

    int sum =0;

    for(int i=0; i<sz;i++)
        sum+=arr[i];

    bool dp[sum/2+1][sz+1];

    for(int i=0;i<=sz; i++)
        dp[0][i]=true;

    for(int i=1;i<=sum/2;i++)
        dp[i][0]= false;

    for(int i=1; i<=sum/2; i++){
        for(int j=1; j<=sz; j++){

                if(i>= arr[j-1]){
                    dp[i][j] = dp[i][j-1] | dp[i-arr[j-1]][j-1];
                }else{
                        dp[i][j] = dp[i][j-1];
                }

        }
    }

    int diff =INT_MAX;
    for(int i=sum/2; i>=0; i--){
        if(dp[i][sz] == true){
            diff = sum -(2*i);  break;
        }
    }

    return diff;
}

int main(){

    int arr[] = {3, 1, 4, 2, 2, 1};
    //int arr[] = {3, 1, 17, 7, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << findMin(arr, n);
    return 0;

}
