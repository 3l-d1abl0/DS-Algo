#include<bits/stdc++.h>

using namespace std;

int getSum(int Fenwick[], int idx){

    int sm =0;

    idx = idx+1;

    while(idx>0){

        sm +=Fenwick[idx];

        //parent idx
        idx -= idx & (-idx);
    }

    return sm;
}

void updateBIT(int Fenwick[], int n, int idx, int val){
    idx = idx+1;

    while(idx<=n){
        Fenwick[idx] +=val;

        //get Next Idx
        idx += idx & (-idx);
    }
}

void buildFenwickTree(int FenwickTree[], int n, int freq[]){

    for(int i=0; i<=n; i++){
        FenwickTree[i] =0;
    }

    for(int i=0; i<n; i++){
        updateBIT(FenwickTree, n, i, freq[i]);
    }
}

int main()
{
    //int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int freq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(freq)/sizeof(freq[0]);

    int *FenwickTree = new int[n+1];

    //Construct Fenwick Tree
    buildFenwickTree(FenwickTree, n, freq);

    /*for(int i=0; i<n; i++){
        cout<<FenwickTree[i]<<endl<<" ";
    }*/

    //Sum of [0...5]
    cout<<"0...5 :: "<<getSum(FenwickTree, 4)<<endl;

    //Sum of [2...5]
    cout<<"2...5 :: "<<getSum(FenwickTree, 4) - getSum(FenwickTree, 1)<<endl;



    return 0;
}
