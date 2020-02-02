#include<bits/stdc++.h>


using namespace std;

void productArray1(int arr[], int n){

    int left[n];
    int right[n];

    left[0]= 1;
    for(int i=1;i<n;i++)
        left[i]= arr[i-1]*left[i-1];

    right[n-1] = 1;
    for(int i=n-2; i>=0;i--)
        right[i] = arr[i+1]* right[i+1];


    for(int j=0; j<n; j++){
        cout<<left[j]*right[j]<<"  ";
    }


}


int main(){

        int arr[] = {10, 3, 5, 6, 2};
        int n = sizeof(arr)/sizeof(arr[0]);
        printf("The product array is: \n");
        productArray(arr, n);

    return 0;
}
