#include<bits/stdc++.h>

using namespace std;

bool partition(int arr[], int sz, int currentSum, int sum){

    if(sz==0)
        return abs( (sum-currentSum)- currentSum);

    return min( partition(arr, sz-1, currentSum, sum), partition(arr, sz-1, currentSum+arr[sz-1], sum));
}

bool findMin(int arr[], int sz){

    int sum =0;

    for(int i=0; i<sz;i++)
        sum+=arr[i];

    return partition(arr, sz, 0, sum);
}

int main(){

    //int arr[] = {3, 1, 4, 2, 2, 1};
    int arr[] = {3, 1, 17, 7, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << findMin(arr, n);
    return 0;

}
