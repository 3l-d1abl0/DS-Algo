#include<bits/stdc++.h>

using namespace std;
#define N 5

struct Node{

        int ele;
        int row;
};

void minHeapify(struct Node *minHeap, int start, int sz){

    int root= start;

    while( root*2+1 < sz){
        int child1 = (root*2)+1;

        if( child1+1< sz  && minHeap[child1].ele> minHeap[child1+1].ele )    child1++;

        if( minHeap[root].ele>minHeap[child1].ele){
            swap( minHeap[root].ele , minHeap[child1].ele);
            swap(minHeap[root].row, minHeap[child1].row);
            root = child1;
        }

    }

}

pair<int, int> findMinRange(int arr[][N], int sz){

    struct Node minHeap[sz];

    int maxEle = INT_MIN;
    int idx[N]={0};

    for(int i=0; i<sz; i++){
        if(maxEle < arr[i][0]){ maxEle = arr[i][0]; }
        minHeap[i].ele = arr[i][0];
        minHeap[i].row = i;
    }
    int range_max = INT_MAX;
    int range_min = INT_MIN;

//    cout<<"Heapify ..."<<endl;
    minHeapify(minHeap, 0, sz);

    while(true){

        long long int curr_def = double(maxEle) - double(minHeap[0].ele);
        long long int range_def = double(range_max) - double(range_min);

        if(curr_def < range_def){
            range_max = maxEle;     range_min = minHeap[0].ele;
        }

        int oldIdx = minHeap[0].row;
//        cout<<"Row ::"<<oldIdx<<endl;
        idx[oldIdx]++;
//        cout<<"Index ::"<<idx[oldIdx]<<endl;
        if(idx[oldIdx] == N){
            return make_pair(range_min, range_max);
        }

        minHeap[0].ele = arr[minHeap[0].row][idx[oldIdx]];

//        cout<<"Heapify"<<endl;
        minHeapify(minHeap, 0, sz);
    }

     return make_pair(range_min, range_max);
}

int main(){

    int arr[][N]= {   {4, 7, 9, 12, 15},
                                                {0, 8, 10, 14, 20},
                                                {6, 12, 16, 30, 50}     };

    int sz = sizeof(arr)/sizeof(arr[0]);
    cout<<"Size :: "<<sz<<endl;
    pair<int, int> res = findMinRange(arr, sz);
    cout<<res.first<<"  <==> "<<res.second<<endl;
    cout<<"---------";
    return 0;
}
