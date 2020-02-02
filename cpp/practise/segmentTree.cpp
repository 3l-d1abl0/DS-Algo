#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

//Segment Tree for Finding Max - Minn and Range Queries

int nextPowOfTwo(int sz){
    return pow(2, ceil(log(sz)/log(2)));
}
void constructSegTree(int input[], int low, int high, int segTree[], int pos){

    if(low==high){
        segTree[pos] = input[low];
        //cout<<"segTree[ "<<pos<<" ] ="<<" input[ "<<low<<" ] ="<<input[low]<<endl;
        return ;
    }
    int mid = low + (high-low)/2;
    //cout<<"Calling ( "<<low<<" , "<<mid<<" , "<<pos*2+1<<")"<<endl;
    constructSegTree(input, low, mid, segTree, pos*2+1);
    //cout<<"Calling ( "<<mid+1<<" , "<<high<<" , "<<pos*2+2<<")"<<endl;
    constructSegTree(input, mid+1, high, segTree, pos*2+2);
    segTree[pos] = min(segTree[pos*2+1], segTree[pos*2+2]);
}

void createSegTree(int input[], int sz, int segTree[], int segLen){
    //O(N)
    //memset(segTree,INT_MAX, segLen*sizeof(int));
    for(int i=0; i<segLen; i++)
        segTree[i] = INT_MAX;

    constructSegTree(input, 0, sz-1, segTree, 0);
    //constractSegTree(input,low, high, segTree, pos);
    //low -> first element of input array
    //high -> last element of input array
    //pos -> root element of segment Tree
}

int  RMQ(int segTree[], int query_left, int query_right, int l, int r, int pos){

        if (query_left<=l && query_right>=r){    cout<<"L = "<<l<<" R = "<<r<<" pos = "<<pos<<" val = "<<segTree[pos]<<endl;   return segTree[pos]; }

        if( query_right< l || query_left> r){ return INT_MAX; }

        int mid = l + (r-l)/2;

        return min(    RMQ(segTree, query_left, query_right, l, mid, pos*2+1),  RMQ(segTree, query_left, query_right, mid+1, r, pos*2+2)     );
}

void update(int input[], int low, int high, int idx, int val, int segTree[],  int pos){

    if(low==high){ cout<<"low :: "<<low<<endl;
            //if(low==idx){
                input[idx] =val; cout<<segTree[pos]<<"-->";
                segTree[pos] = val; cout<<segTree[pos]<<endl;
            //}else return ;

    }else{
                int mid = low + (high-low)/2;

                if(low<=idx && idx<=mid){
                        update(input, low, mid, idx, val, segTree, pos*2+1);
                }else{
                        update(input, mid+1, high, idx, val, segTree, pos*2+2);
                }

                segTree[pos] = min(segTree[pos*2+1], segTree[pos*2+2]);
    }
}

void print_array(int arr[], int sz){
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main(){

    int input[] = {0,3,4,2,1,6,-1};
    int sz = sizeof(input)/sizeof(input[0]);
    int segLen = nextPowOfTwo(sz)*2 -1;
    int segTree[segLen];

    createSegTree(input, sz, segTree, segLen); //O(N)

    for(int i=0; i<segLen; i++)
        cout<<"["<<i<<" ] = "<<segTree[i]<<"\n";

        print_array(input, sz); cout<<endl;
        print_array(segTree, segLen);   cout<<endl;

    int query_left = 1, query_right = 6;

    cout<<"Left :: "<<query_left<<"   Right :: "<<query_right<<endl;
    cout<<endl<<RMQ(segTree, query_left, query_right, 0, sz-1, 0)<<endl;    //O(logN)


    //Update    O(logN)
    int idx=3, val = -10;

    update(input, 0, sz-1, idx, val, segTree, 0);  cout<<"Update idx :: "<<idx<<endl;

    print_array(input, sz); cout<<endl;
    print_array(segTree, segLen);   cout<<endl;

    cout<<"Left :: "<<query_left<<"   Right :: "<<query_right<<endl;
    cout<<endl<<RMQ(segTree, query_left, query_right, 0, sz-1, 0)<<endl;    //O(logN)
    return 0;
}
