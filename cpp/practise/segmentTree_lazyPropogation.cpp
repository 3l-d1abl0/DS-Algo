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

int  RMQ(int lazy[], int segTree[], int query_left, int query_right, int l, int r, int pos){

        if(l>r){  return INT_MAX;  }

        if(lazy[pos]!=0){
            segTree[pos] = lazy[pos];
            if(l!=r){   //leaf Node
                lazy[pos*2+1] = lazy[pos];
                lazy[pos*2+2] = lazy[pos];
            }
            lazy[pos] = 0;
        }

        if( query_right< l || query_left> r){ return INT_MAX; }

        if (query_left<=l && query_right>=r){    cout<<"L = "<<l<<" R = "<<r<<" pos = "<<pos<<" val = "<<segTree[pos]<<endl;   return segTree[pos]; }

        int mid = l + (r-l)/2;

        return min(    RMQ(lazy, segTree, query_left, query_right, l, mid, pos*2+1),  RMQ(lazy, segTree, query_left, query_right, mid+1, r, pos*2+2)     );
}

void update(int input[], int low, int high, int idx, int val, int segTree[],  int pos){

    if(low==high){ cout<<"low :: "<<low<<endl;
            //if(low==idx){
                input[idx] =val; cout<<segTree[pos]<<"-->"; segTree[pos] = val; cout<<segTree[pos]<<endl;
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

void rangeUpdate(int lazy[], int low, int high, int range_left, int range_right, int val, int segTree[],  int pos){

    if(low>high){ return ; }

    if(lazy[pos]!=0){
        segTree[pos] = lazy[pos];
        if(low!=high){
            lazy[pos*2+1] = lazy[pos];
            lazy[pos*2+2] = lazy[pos];
        }
        lazy[pos] =0;
    }

    if(range_left>high || range_right <low){ return; }

    if(range_left<=low && range_right>=high){
            cout<<"low :: "<<low<<"  right :: "<<high<<endl;
            segTree[pos] = val;
            if(low!=high){
                lazy[pos*2+1] = val;
                lazy[pos*2+2] = val;
                cout<<lazy[pos*2+1]<< "<==>"<<lazy[pos*2+2]<<endl;
            }
            cout<<"["<<pos<<"] ="<<segTree[pos]<<endl;
            return;
    }

    int mid = low + (high-low)/2;
    rangeUpdate(lazy, low, mid, range_left, range_right, val, segTree, pos*2+1);
    rangeUpdate(lazy, mid+1, high, range_left, range_right, val, segTree, pos*2+2);

    segTree[pos] = min(segTree[pos*2+1], segTree[pos*2+2]);

}

void print_array(int arr[], int sz){
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main(){

    //int input[] = {2,3,-1,4};
    int input[] = {0,3,4,2,1,6,-1};
    int sz = sizeof(input)/sizeof(input[0]);
    int segLen = nextPowOfTwo(sz)*2 -1;
    int segTree[segLen];
    int lazy[segLen];

    createSegTree(input, sz, segTree, segLen); //O(N)

    cout<<"Input :: "<<endl;
    print_array(input, sz); cout<<endl;
    cout<<"Segement Tree :: "<<endl;
    print_array(segTree, segLen);   cout<<endl;

    for(int i=0;i<segLen;i++)
        lazy[i]=0;

    int query_left = 3, query_right = 5;

    cout<<"QUERY ::      ::    Left :: "<<query_left<<"   Right :: "<<query_right<<endl;
    cout<<endl<<RMQ(lazy, segTree, query_left, query_right, 0, sz-1, 0)<<endl;

    cout<<"RANGE UPDATE :: :: "<<endl;
    int range_left=3, range_right=5, val = -10;
    cout<<"Left :: "<<range_left<<"     Right :: "<<range_right<<" value :: "<<val<<endl;
    rangeUpdate(lazy, 0, sz-1,range_left, range_right, val, segTree, 0);


    cout<<"Input :: "<<endl;
    print_array(input, sz); cout<<endl;
    cout<<"Segement Tree :: "<<endl;
    print_array(segTree, segLen);   cout<<endl;
    cout<<" Lazy Tree :: "<<endl;
    print_array(lazy, segLen);  cout<<endl;

    cout<<"Left :: "<<query_left<<"   Right :: "<<query_right<<endl;
    cout<<endl<<RMQ(lazy, segTree, query_left, query_right, 0, sz-1, 0)<<endl;
    return 0;
}
