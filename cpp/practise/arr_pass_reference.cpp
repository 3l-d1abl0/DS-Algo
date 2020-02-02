#include<bits/stdc++.h>

using namespace std;

void passF(int arr[], int sz){

    //int sz= sizeof(arr)/sizeof(arr[0]);


    for(int i=0;i<sz;i++)
        printf("%d ", arr[i]);
    arr[5]=1;
    printf("\n");
}

int main(){

    int arr[]={0,1,2,3,4,5,6,7,8,9};
int sz= sizeof(arr)/sizeof(arr[0]);

    arr[5] = 0;
    passF(arr, sz);

    for(int i=0;i<sz;i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
