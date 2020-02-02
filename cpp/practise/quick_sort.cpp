#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int r){

    cout<<"partition : "<<l<<" :: "<<r<<endl;

    int part_pos = l;
    int part_val = arr[part_pos];

    int i = l; int j = r;

    while(i<j){
        while(i<=r && arr[i]<part_val){
            i++;
        }

        while(j>=l && arr[j]>=part_val){
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }

    arr[part_pos] = arr[j];
    arr[j] = part_val;

    cout<<"return = "<<j<<endl;


        for(int i=0; i<7;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    return j;


}

void quickSort(int arr[], int start, int end){

    if(start < end){
        int part = partition(arr, start, end);
        quickSort(arr, start, part-1);
        quickSort(arr, part+1, end);
    }

}

int main(){

    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<i<<" ";
    }

    return 0;
}
