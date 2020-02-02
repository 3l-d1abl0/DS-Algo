#include<bits/stdc++.h>

using namespace std;

int lis(int arr[], int n){

    int L[n];

    for(int i=0; i<n;i++)
        L[i]=1;

    for(int i=1; i<n;i++){

        for(int j=0; j<n;j++){

            if( arr[i]>arr[j] && L[i]<L[j]+1)
                L[i] = L[j]+1;
        }   //
    }   //

    int maxx=0;
    for(int i=0; i<n;i++)
        maxx = maxx>L[i]?maxx:L[i];

    return maxx;
}


int main(){

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Length of lis is %d\n", lis( arr, n ) );

    return 0;
}
