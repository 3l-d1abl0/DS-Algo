#include<bits/stdc++.h>

using namespace std;

void SWAP(int * a, int *b){
    int temp = *a;
    *a =* b;
    *b = temp;
}

void sort012(int arr[], int sz){
    int low=0, mid=0,hi=sz-1;


    while(mid<=hi){

        switch(arr[mid]){
        case 0:
            SWAP(&arr[low++], &arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            SWAP(&arr[mid], &arr[hi--]);
            break;
        }
    }
}
void printArray(int arr[], int arr_size){

    for(int i=0;i<arr_size; i++){
        printf("%d", arr[i]);
    printf("\n");
    }
}

int main(){

    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;

    sort012(arr, arr_size);

    printf("array after segregation \n");
    printArray(arr, arr_size);

    getchar();
    return 0;
}
