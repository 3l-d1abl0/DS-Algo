
#include<bits/stdc++.h>

using namespace std;


vector<int > adj[10002];
bool vis[10002];

queue<int> q;

void topo(int vertex){

    vis[vertex]= true;
    //cout<<"vertex ::"<<vertex<<endl;

        for(int i=0; i<adj[vertex].size(); i++){
                int u = adj[vertex][i];
                if(vis[u]==false)
                    topo(u);
        }

        q.push(vertex);
}

int main(){

    int N,M,u,v;
    int tt;

    //cin>>N>>M;
    scanf("%d %d", &N,&M);

    for(int i=0; i<M;i++){
        //cin>>u>>v;
        scanf("%d %d", &u,&tt);
        for(int j=1; j<=tt; j++){
            scanf("%d", &v);
            adj[u].push_back(v);
        }
    }

    for(int i=1; i<=N; i++){
        if(vis[i]==false)
            topo(i);
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
