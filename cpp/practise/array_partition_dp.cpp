#include<bits/stdc++.h>


using namespace std;

bool check_partition(int arr[], int sz){

    int sum=0;
    for(int i=0; i<sz;i++)
        sum+= arr[i];

    if(sum &1)
        return false;

    bool dp[sum/2+1][sz+1];

    for(int i=0;i<=sz; i++)
        dp[0][i]=true;

    for(int i=1;i<=sum/2;i++)
        dp[i][0]= false;

    for(int i=1; i<=sum/2;i++){
        for(int j=1; j<=sz;j++){

            if(arr[j-1]<=i)
                dp[i][j]= dp[i-arr[j-1]][j-1] || dp[i][j-1];
            else
                dp[i][j]=dp[i][j-1];

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

//    for (int i = 1; i <= sum/2; i++)
//     {
//       for (int j = 1; j <= sz; j++)
//       {
//         dp[i][j] = dp[i][j-1];
//         if (i >= arr[j-1])
//           dp[i][j] = dp[i][j-1] || dp[i - arr[j-1]][j-1];
//           else
//            dp[i][j] = dp[i][j-1];
//       }
//     }

    return dp[sum/2][sz];
}


int main(){

   // int arr[]={1,11,5,5};
      int arr[] = {3, 1, 5, 10, 12};
    int sz = sizeof(arr)/sizeof(arr[0]);

    if(check_partition(arr, sz)){
        printf("Can be...\n");
    }else{
        printf("Cant .. \n");
    }

        return 0;
}
