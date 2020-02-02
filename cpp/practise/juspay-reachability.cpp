#include<iostream>
#include<queue>
#include<map>

using namespace std;

bool reachable(int src, int des, map<int, bool> &visited, map<int, vector<int>> &adj){

    visited[src] = false;
    queue<int> q;
    q.push(src);

    int node;
    while(!q.empty()){

        node= q.front();
        q.pop();
        cout<<"node= "<<node<<endl;
        vector<int>::iterator it;

        for(it= adj[node].begin(); it!=adj[node].end(); it++){

            if(*it == des)  
            {   cout<<"Found ="<<des<<endl;
                return true;
            }

            if(visited[*it]==false){
                visited[*it] = true;
                q.push(*it);
            }
        }

    }

    return false;

}

int main(){

    int N,E,x,y;

    cin>>N;
    map<int,bool> mp;

    for(int i=0; i<N;i++){
        cin>>x;
        mp[x]= false;
    }

    cin>>E;
    map<int, vector<int>> adj;
    for(int i=0; i<E; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        cout<<x<<" ->"<<y<<endl;
    }

    //cin>>x>>y;

    int q;
    cin>>q;

    while(q--){
        cin>>x>>y;
        cout<<reachable(x,y, mp, adj)<<endl;
    }
    
    return 0;
}