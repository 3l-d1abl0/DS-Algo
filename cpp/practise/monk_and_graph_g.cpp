#include<bits/stdc++.h>

using namespace std;

int INF = 1e9;

vector<vector<int> > adj;

void bfs(int src, vector<int > &forw, int N){

    bool visited[N+1];
    memset(visited, false, sizeof(visited[0]*N+1));

    forw[src]=0;
    visited[src] = true;
    queue<int > q;
    q.push(src);
    while(!q.empty()){

            int ver = q.front();    q.pop();

            for(int i=0; i<adj[ver].size(); i++){
                if(visited[adj[ver][i]] ==false){
                    visited[adj[ver][i]] = true;
                    q.push(adj[ver][i]);
                    forw[adj[ver][i]]= forw[ver]+1;
                }
            }
    }
}

int main(){

    int N,M;
    int src, dest;
    int u, v;
    cin>>N>>M;
    adj.resize(N+1);
    for(int i=1; i<=M;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin>>src>>dest;
    vector<int >forw(N+1), rev(N+1);

    //cout<<"Calling bfs"<<endl;
    bfs(src, forw, N);  //from source
    //cout<<"Calling bfs"<<endl;
    bfs(dest, rev, N);      //from destination

    vector<vector<int> > nodesAtDistance;
    nodesAtDistance.resize(N+1);
    for(int i=1; i<=N; i++){

        if(forw[i]+rev[i]== forw[dest] && forw[i]!=INF){
            nodesAtDistance[forw[i]].push_back(i);
        }
    }

    int ans = INF;
    for(int i=1; i<=N; i++){
        if(nodesAtDistance[i].size()==1 &&  (nodesAtDistance[i][0]!=src && nodesAtDistance[i][0]!=dest) )
            ans = min(ans, nodesAtDistance[i][0]);
    }


    if(ans==INF)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}



