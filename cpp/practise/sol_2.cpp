#include<bits/stdc++.h>
#include<climits>

using namespace std;

int arr[1000][1000];
int dup[1000][1000];
int N,M;

void dfs(int i, int j, int base){

    dup[i][j]=min(dup[i][j], base+1);
    if(i-1>=0 && i<N && arr[i-1][j]==1)
            dfs(i-1,j,dup[i][j]+1);
    if(j+1>=0 && j<N && arr[i][j+1]==1)
            dfs(i,j+1,dup[i][j]+1);
    if(i+1>=0 && i<N && arr[i+1][j]==1)
        dfs(i+1,j,dup[i][j]+1);
    if(j-1>=0 && j<M && arr[i][j-1]==1)
        dfs(i,j-1,dup[i][j]+1);
}

int main(){

    cin>>N>>M;
    for(int i=0; i<N;i++)
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            dup[i][j]=INT_MAX;
        }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==2){
                dup[i][j]=0;

                if(i-1>=0 && i<N && arr[i-1][j]==1)
                    dfs(i-1,j,0);
                if(j+1>=0 && j<M && arr[i][j+1]==1)
                    dfs(i,j+1,0);
                if(i+1>=0 && i<N && arr[i+1][j]==1)
                    dfs(i+1,j,0);
                if(j-1>=0 && j<M && arr[i][j-1]==1)
                    dfs(i,j-1,0);


            }
        }
    }

    int ans=INT_MAX;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]==1){
                ans=min(ans,dup[i][j]);
            }
        }
    }

    return 0;
}
