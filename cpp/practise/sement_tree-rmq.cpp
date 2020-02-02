#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int nextPowOfTwo(int sz){

    return pow(2,ceil(log(sz)/log(2)));
}

void constructTree(int arr[], int left, int right, int segTree[], int idx){

    if(left==right){
        segTree[idx]= arr[left];
        return ;
    }

    int mid = left + (right-left)/2;

    constructTree(arr, left, mid, segTree, idx*2+1);
    constructTree(arr, mid+1, right, segTree, idx*2+2);

    segTree[idx] = min(segTree[idx*2+1], segTree[idx*2+2]);
}

int createSegTree(int arr[], int sz, int segTree[], int segLen){

    for(int i=0; i<segLen; i++)
        segTree[i] = INT_MAX;

    constructTree(arr, 0 , sz-1, segTree, 0);

}

int RMQ(int left, int right, int segTree[], int idx, int qs, int qe){

    //if current range falls under the query range
    if(qs<= left && qe>=right)
        return segTree[idx];

    //if the query range does not overlap
    if(qs > right || qe <left)
        return INT_MAX;

    int mid = left +(right-left)/2;

    return min( RMQ(left, mid, segTree, 2*idx+1, qs, qe),
                RMQ(mid+1, right, segTree, 2*idx+2, qs, qe) );
}

int main(){

    int arr[] = {1, 3, 2, 7, 9, 11};
    int sz = sizeof(arr)/sizeof(arr[0]);

    int segLen = 2*nextPowOfTwo(sz)-1;
    int *segTree =  new int[segLen];

    for(int i=0; i<sz; i++)
        cout<<arr[i]<<" ";

    createSegTree(arr, sz, segTree, segLen);
    cout<<endl;
    for(int i=0; i<segLen; i++)
        cout<<segTree[i]<<" ";

    /*
    // Build segment tree from given array
    int *st = constructSegTree(arr, n);

    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range

    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQ(st, n, qs, qe));
    */

    int qs = 2, qe = 5; //[0..n-1]
    //RMQ(left, right, segTree, idx, qs, qe);
    cout<<endl<<RMQ(0, sz-1, segTree, 0, qs, qe)<<endl;

    //https://ideone.com/o4WVJj

    return 0;
}
