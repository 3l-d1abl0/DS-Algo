#include<bits/stdc++.h>

using namespace std;

bool partition(int arr[], int sz, int sum){

    if(sum==0)
        return true;

    if(sz==0 && sum!=0)
        return false;

    if(arr[sz-1] >sum)
        return partition(arr, sz-1, sum);

    return partition(arr, sz-1, sum ) || partition(arr, sz-1, sum-arr[sz-1]);

}


bool check_partition(int arr[], int sz){
    int sum =0;
    for(int i=0;i <sz;i++)
        sum+=arr[i];

    if(sum&1)
        return false;

    return partition(arr, sz, sum/2);

}

int main(){

    //int arr[]={1,11,5,5};
      int arr[] = {3, 1, 5, 10, 12};
    int sz = sizeof(arr)/sizeof(arr[0]);

    if(check_partition(arr, sz)){
        printf("Can be...\n");
    }else{
        printf("Cant .. \n");
    }

        return 0;
}
