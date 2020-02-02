#include<bits/stdc++.h>
//Given a set of n integers where n <= 40. Each of them is at most 10^12, determine the maximum sum subset having sum less than or equal S where S <= 10^18.
using namespace std;

long long int X[1048577];  //2^20
long long int Y[1048577];


void calcHalfSum(int arr[], long long int a[], int n, int offset){

    int subSize = 1<<n;

    for(int i=0; i<subSize; i++){
        long long int sum =0;
        for(int j=0; j<n; j++){
                if(i & (1<<j) ){
                    sum+=arr[j+offset];
                }
        }
        a[i]= sum;
    }
}

long long int subsetSum(int arr[], int n, int SUM){

    //calc subset sum of both Halves
    calcHalfSum(arr, X, n/2, 0);
    calcHalfSum(arr, Y, n-n/2, n/2);
    //array, noe, offset

    int szX = 1<<n/2;
    int szY = 1<<(n-n/2);

    //sort one Half
    sort(Y, Y+szY);

    long long int maxSubSum = 0;

    for(int i=0; i<szX; i++){

        if(X[i]<=SUM){

            //returns first address which is equal or greater than S-X[i]
            int p = lower_bound(Y, Y+szY, SUM-X[i]) -Y;

            //check if not found or greater than S-X[i]
            if(p== szY || Y[p]!= (SUM-X[i]) )
                p--;

            maxSubSum = (X[i]+Y[p]>maxSubSum)?(X[i]+Y[p]):maxSubSum;
        }

    }
    return maxSubSum;
}


int main(){

    int arr[] = {3,34,4,12,5,2};
    int sz = sizeof(arr)/sizeof(arr[0]);

    int SUM = 13;


    cout<<"Largest sum subset less than or Equal to "<<SUM<<" :: "<<subsetSum(arr, sz, SUM)<<endl;
    return 0;
}
