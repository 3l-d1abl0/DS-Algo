#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>


using namespace std;

int nextPowOfTwo(int sz){
    return pow(2, ceil(log(sz)/log(2)));
}

void constructSegTree(int input[], int low, int high, int segTree[], int pos){

    if(low==high){
        segTree[pos] = input[low];
        return ;
    }

    int mid = low + (high-low)/2;
    constructSegTree(input, low, mid, segTree, pos*2+1);
    constructSegTree(input, mid+1, high, segTree, pos*2+2);
    segTree[pos] = max(segTree[pos*2+1], segTree[pos*2+2]);
}

void createSegTree(int input[], int sz, int segTree[], int segLen){

    memset(segTree, INT_MAX-1, segLen*sizeof(int));
    for(int i=0; i<segLen; i++)
        cout<<segTree[i]<<" ";

    constructSegTree(input, 0, sz-1, segTree, 0);
    //constractSegTree(input,low, high, segTree, pos);
    //low -> first element of input array
    //high -> last element of input array
    //pos -> root element of segment Tree
}

int main(){

    int input[] = {0,3,4,2,1,6,-1};
    int sz = sizeof(input)/sizeof(input[0]);
    int segLen = nextPowOfTwo(sz)*2 -1;
    int segTree[segLen];

    createSegTree(input, sz, segTree, segLen);

    for(int i=0; i<segLen; i++)
        cout<<segTree[i]<<"<->";

    return 0;
}
