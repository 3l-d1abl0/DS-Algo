#include<bits/stdc++.h>

using namespace std;

int heap[3];

void heapify(int arr[], int i, int N){

        while(2*i +1<N){

                int child = 2*i +1;

                if(arr[child] < arr[child+1] && child+1<N){
                    child++;
                }

                if(arr[i]> arr[child])  //max heap
                    break;

                swap(arr[i], arr[child]);

                i=child;
        }
}

void build_heap(int arr[], int N){

    for(int i= (N-2)/2 ; i>=0; i--){
                heapify(arr,i,N);
    }

}

void heap_sort(int arr[], int N){

        for(int i=N-1; i>=0; i--){
            swap(arr[0], arr[i]);
            heapify(arr,0,i);
        }
}

int main(){

    //int arr[]={12,45,37,29,75,843,2,8,34,789};
    int arr[]={213, 31, 12, 9429, 23, 32, 41312, 132};
    int K=3;
    int sz = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<K;i++)
        heap[i] = arr[i];

    heapify(heap, 0, K);

    for(int i=K; i<sz; i++)
        if(arr[i]<heap[0]){
            heap[0]= arr[i];
            heapify(heap, 0, K);
        }

    cout<<"Kth : "<<K<<" smallest element ::  "<<heap[0]<<endl;

    sort(arr, arr+sz);
    for(int i=0; i<sz; i++)
        cout<<arr[i]<<" ";

    return 0;
}

