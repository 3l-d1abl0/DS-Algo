#include<bits/stdc++.h>

using namespace std;

struct Node{

    int num;
    int row;
    int col;

};

void swap(Node *n1, Node *n2){

    Node tmp = *n1;
    *n1= *n2;
    *n2 = tmp;
}

void heapify(Node arr[], int i, int N){

    int root = i;

    while(2*i+1<N){

        int child = 2*i+1;

        if( child+1<N && arr[child+1].num < arr[child].num ) //min-heap
            child= child+1;

        if(&arr[i] < &arr[child])
            break;

        swap(arr[child], arr[i]);

        i=child;
    }

}

void buildHeap(Node arr[], int N){

    for(int i= (N-2)/2; i>=0; i--){

            heapify(arr, i, N);
    }
}


int kthSmallest(int mat[4][4], int N, int K){

    if(K<0 || K>N*N)
        return INT_MAX;

    Node arr[N];
    for(int i=0; i<N; i++){
        arr[i] = {mat[0][i], 0, i};
    }

    buildHeap(arr,N);   //build a min Heap


        for(int i=0; i<N; i++)
    cout<<arr[i].num<<" ";

    cout<<endl;

    for(int i=0; i<K; i++){

        int nextVal = (arr[0].row < N-1)? mat[arr[0].row+1][arr[0].col]:INT_MAX;
        cout<<arr[0].num<<endl;

        arr[0] = {nextVal, arr[0].row+1, arr[0].col};


        heapify(arr, 0, N);
    }

    return arr[0].num;

}

int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
  return 0;
}

