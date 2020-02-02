#include<bits/stdc++.h>

using namespace std;

vector<int > adj[10002];
priority_queue<int, vector<int>, greater<int> > toProcess;
vector<int> res;
int in_degree[10002];

int main(){

    int N,M,u,v;

    //cin>>N>>M;
    scanf("%d %d", &N,&M);

    for(int i=0; i<M;i++){
        //cin>>u>>v;
        scanf("%d %d", &u,&v);
        adj[u].push_back(v);
        in_degree[v]= in_degree[v]+1;
    }

    for(int i=1; i<=N; i++){
        if(in_degree[i]==0)
            toProcess.push(i);
    }

    ////
    while(!toProcess.empty()){
        int v = toProcess.top();
        toProcess.pop();
        //cout<<v<<" - ";
        res.push_back(v);

        for(int i=0; i< adj[v].size(); i++){

                int u = adj[v][i];
                in_degree[u]--;
                if(in_degree[u]== 0)
                    toProcess.push(u);

        }

    }
    ////

    //cout<<res.size()<<endl;
    if(res.size()!=N){
        cout<<"Sandro fails."<<endl;
    }else{
        vector<int>::iterator it;
        for(it= res.begin(); it!=res.end(); it++){
                cout<<(*it)<<" ";
        }
    }
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
