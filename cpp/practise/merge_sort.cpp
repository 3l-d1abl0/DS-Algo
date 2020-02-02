#include<bits/stdc++.h>

using namespace std;

int idx=0;

void _merge(int arr[], int l, int m, int r){

    int sz1 = m-l+1;
    int sz2 = r-m;

    int L[sz1]; int R[sz2];

    for(int i=0; i<sz1; i++)
        L[i] = arr[l+i];
    for(int j=0; j<sz2; j++)
        R[j] = arr[m+j+1];


    int i=0, j=0, k=l;
    while(i<sz1 && j<sz2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<sz1){
        arr[k] = L[i];
        i++; k++;
    }
    while(j<sz2){
        arr[k] = R[j];
        j++; k++;
    }
    cout<<"L="<<l<<endl;
}

void merge_sort(int arr[], int l, int r){

    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        _merge(arr, l, m, r);
    }

}

int main(){

    int arr[]={23, 13, 34, 546, 34, 45, 34, 78, 65, 6, 78,5, 1};

    int N= sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<N; i++)
    cout<<arr[i]<<" ";
    cout<<endl<<endl;

    int sz = N-1;
    merge_sort(arr, 0,sz);

    for(int i=0; i<N; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
