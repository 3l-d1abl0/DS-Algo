#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findMinOfLar(int A[], int l, int r, int ele){
    while(r-l>1){
        int m = l + (r-l)/2;
        if(A[m]>=ele){
            r=m;
        }else{
            l=m;
        }
    }
    return r;
}

int _lis(int A[], int n){

    int * tempList = new int[n];

    memset(tempList, 0, sizeof(tempList[0])*n);

    tempList[0]=A[0];   int len =1;


    for(int i=1; i<n;i++){

        if(A[i]<=tempList[0])
            tempList[0]=A[i];
        else if(A[i]>tempList[len-1])
            tempList[len++]=A[i];
        else
            //tempList[findMinOfLar(tempList, -1, len-1, A[i])]=A[i];
            tempList[findMinOfLar(tempList, 0, len, A[i])]=A[i];
    }
    for(int i=0;i <len; i++){
        printf("%d ", tempList[i]);
    } printf("\n");
    delete[] tempList;
    return len;
}

int main(){

    //int A[] = {2,5,3,7,11,8,10,13,6};
    //int A[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int A[] = {2,6,3,4,1,2,9,5,8};

    int n = sizeof(A)/sizeof(A[0]);

    printf("Length of Longest increasing Subsequence %d \n",_lis(A, n) );

    return 0;
}
