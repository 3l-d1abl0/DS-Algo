#include<bits/stdc++.h>

using namespace std;

int arr[105][105];
int dist[105][105];

void btrack(int i,int j, int new_val){

        if(new_val < arr[i][j] )

        //top
        if(i-1 >=0)
            btrack(i-1, j, new_val);
        //right
        if(j+1 <M)
            btrack(i, j+1, new_val);
        //bottom
        if(i+1<N)
            btrack(i+1, j, new_val);
        //left
        if(j-1>=0)
            btrack(i, j-1, new_val);
}

int main(){

    int M,N;

    cin>>N,M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
                cin>>arr[i][j];
        }
    }

    btrack(0,0, arr[0][0]);


    return 0;
}
