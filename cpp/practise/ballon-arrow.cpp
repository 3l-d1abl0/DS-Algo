/*
N number of balloons are kept at different heights. You are asked to find out number of arrows to burst them. When an arrow hits the balloon it goes one level down.
Assume that the balloons are having same size.

5,4,3,3,2,2,1,1,1 => 3
5,4,2,1 => 2
6,5,2,4,5 => 3
6,4,5
*/


#include<bits/stdc++.h>

using namespace std;

int balloonArrow(int arr[], int sz){

    if(sz==0)
        return 0;

    int arrowCount =1; //By default there will be one sequence
   
    for (int i = 1; i < sz; i++) {

        if(arr[i-1] - arr[i]==1) continue;

        arrowCount++;
    }

    return arrowCount;
}

int main(){

    int arr[] = {5,4,3,3,2,2,1,1,1};
    int arr1[] = {5,4,2,1};
    int arr2[] = {6,5,2,4,5};
    int arr3[] = {6,4,5};
    int arr4[] = {5,4,3,3,6,7,6,2,2,1};
    int arr5[] = {5,4,3,3,6,7,6,4,4,1};

    int sz = sizeof(arr4)/sizeof(arr4[0]);

    cout<<balloonArrow(arr5, sz);

    return 0;
}