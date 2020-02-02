#include<bits/stdc++.h>

#define SIZE 5  //size of our grid area ,can also be more than 5X5
#define NO_OF_DIRECTIONS 4

using namespace std;

int M,N;
int arr[105][105];

int dd[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x, int y, int pathIdx){

    if(x==M-1 && y==N-1){
        printPath(pathIdx);
       //return;
        break;
    }

    int minn= INT_MAX;
    for(int i=0;i<4;i++){
                int nextX=x+dd[i][0];
                int nextY=y+dd[i][1];
    }
}

int main(){

    cin>>M>>N;

    for(int i =0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }

    dfs(0,0);

    return 0;
}
