#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[], int i, int N){

        while(2*i +1<N){

                int child = 2*i +1;

                if(arr[child] < arr[child+1] && child+1<N){
                    child++;
                }

                if(arr[i]> arr[child])
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

    int arr[]={12,45,37,29,75,843,2,8,34,789};

    int sz = sizeof(arr)/sizeof(arr[0]);
    cout<<"Size ... "<<sz<<endl;
    cout<<"Building Heap ... "<<endl;
    build_heap(arr,sz);
    for(int i=0; i<sz; i++)
        cout<<arr[i]<<" ";

    cout<<"Size ... "<<sz<<endl;
    cout<<"Heap Sort ...... "<<endl;
    heap_sort(arr,sz);
    cout<<"Size ... "<<sz<<endl;
    for(int i=0; i<sz; i++)
        cout<<arr[i]<<"  ";

    return 0;
}
