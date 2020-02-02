#include<bits/stdc++.h>

using namespace std;

/*
Shell sort is a variation of insertion sort.
We usually compare elements between gap/interval and gradually decrease the gap.
For insertion sort the gap is 1.
The performance of the shell sort depends on the type of sequence used for a given input array. 
*/

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int arr[], int n){

    for(int gap= n/2; gap>0; gap/=2){

        for(int j= gap; j <n; j++){

            for(int i=j-gap; i>=0; i-=gap){

                if(arr[i]<arr[i+gap]){

                }else{
                    swap(arr[i], arr[i+gap]);
                }
                
            }
        }
    }
}

void printArray(int arr[], int size){

  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";

  cout << endl;

}

int main(){

    //int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
    //int data[] = {12, 34, 54, 2, 3};
    int data[] = {23, 29, 15, 19, 31, 7, 9, 5, 2};
    int size = sizeof(data) / sizeof(data[0]);
    shellSort(data, size);
    cout << "Sorted array: \n";
    printArray(data, size);

    return 0;
}