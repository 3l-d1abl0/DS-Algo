#include<bits/stdc++.h>

using namespace std;


int rotatedBS(int arr[], int _start, int _end, int data ){

    if(_start > _end)
        return -1;

    int mid = _start + (_end - _start)/2;

    if(data == arr[mid])
        return mid;

    if(arr[_start] <= arr[mid] ){

        if(data >= arr[_start] && data< arr[mid])
            rotatedBS(arr, _start, mid-1, data);
        else
            rotatedBS(arr, mid+1, _end, data);

    }else{  //arr[_start] > arr[mid]

        if(data > arr[mid] && data<= arr[_end])
            rotatedBS(arr, mid+1, _end, data);
        else
            rotatedBS(arr, _start, mid-1, data);

    }

}


int main(){

    int arr [] = {69, 72, 74, 79,84, 86, 89,99, 5, 12, 32, 34, 56, 67};

    int N = sizeof(arr)/sizeof(arr[0]);

    //cout<<"N = "<<N<<endl;

    int search_term = 12;

    cout<<"Position = "<<rotatedBS(arr, 0, N-1, search_term)<<endl;

    return 0;
}
