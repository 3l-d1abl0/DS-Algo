#include<bits/stdc++.h>

using namespace std;

void heapify(int parent, int arr[], int N){

    while( ((parent*2)+1) < N ){
        int child = parent*2 +1;

        if(child+1 <N && arr[child]< arr[child+1])
            child++;
        if(arr[parent]< arr[child]){
            swap(arr[parent], arr[child]);
            parent= child;
        }else{
            return ;
        }
    }
}


void build_heap(int arr[], int N){
    for(int start= (N-2)/2; start>=0; start--)
    heapify(start, arr, N);
}

void heap_sort(int arr[], int N){
        for(int endd = N-1; endd>0; endd--){
            swap(arr[0], arr[endd]);
            heapify(0, arr, endd);
        }
}

int main(){

    int arr[]={23, 13, 34, 546, 34, 45, 34, 78, 65, 6, 78,5, 1};

    int N= sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;

    build_heap(arr, N);
    heap_sort(arr, N);

    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
