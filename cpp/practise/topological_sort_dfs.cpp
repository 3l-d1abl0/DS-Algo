#include<bits/stdc++.h>

using namespace std;


vector<int > adj[10002];
bool vis[10002];

stack<int> q;

void topo(int vertex){

    vis[vertex]= true;
    cout<<"vertex ::"<<vertex<<endl;

        for(int i=0; i<adj[vertex].size(); i++){
                int u = adj[vertex][i];
                if(vis[u]==false)
                    topo(u);
        }

        q.push(vertex);
}

int main(){

    int N,M,u,v;

    //cin>>N>>M;
    scanf("%d %d", &N,&M);

    for(int i=0; i<M;i++){
        //cin>>u>>v;
        scanf("%d %d", &u,&v);
        adj[u].push_back(v);
        //in_degree[v]= in_degree[v]+1;
    }

    for(int i=1; i<=N; i++){
        if(vis[i]==false)
            topo(i);
    }

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
*/
