#include<bits/stdc++.h>

using namespace std;

#define MAX 200002

bool isPrime[MAX];
bool visited[MAX];

void sieve(){
    memset(isPrime, true, MAX*sizeof(bool));
    isPrime[1] = false;
    for(int i=2; i*i<100002; i++){
            if ( isPrime[i] ) {
                for (int j= i + i; j <100002; j += i)
                    isPrime[j] = false;
        }
    }
}

int V;
list<int> *adj;
int Gcnt;
void dfs(int v, int cnt,int u){

        visited[v]=true;
        if(isPrime[v+1]==true){
            cnt++;
            //cout<<"visiting ... "<<(v+1)<<" count :: "<<cnt<<endl;
        }

        if(v==u){   //current vertex is the Node
            Gcnt = cnt;
            return;
        }

        list<int>::iterator it;

        for(it= adj[v].begin(); it!=adj[v].end(); it++){
                if(!visited[*it] && !visited[u]){
                    dfs(*it, cnt, u);
                }
        }

}

int main(){
        sieve();

        int N, u,v,Q;
        cin>>N;

        adj = new list<int>[N];
        for(int i=0; i<N-1; i++){
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        cin>>Q;
        while(Q--){
            memset(visited, false, N*sizeof(bool));
            cin>>v>>u;
            dfs(v-1, 0,u-1);
            cout<<Gcnt<<endl;
        }

    return 0;
}
