#include<bits/stdc++.h>
using namespace std;

bool visited[301];
bool mp[301][301];
int N;
void dfs(bool mp[][301], int idx){
    visited[idx]=true;
    for(int i=0; i<N; i++){
        if(mp[idx][i]==true && visited[i]==false)
            dfs(mp, i);
    }
}

int main(){

    //int N;
    cin>>N;
    //bool mp[N+1][N+1];

    char val;
    for(int i=0; i<N; i++){
        visited[i] = false;
        for(int j=0; j<N; j++){
            cin>>val;
            mp[i][j] = (val=='Y')?1:0;
        }
        cout<<endl;
    }
    int ctr=0;
    for(int i=0; i<N;i++){
        if(visited[i]==false){
            dfs(mp,i);
            ctr++;
        }
    }

    cout<<ctr;

    return 0;
}
