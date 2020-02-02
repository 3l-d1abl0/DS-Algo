#include<bits/stdc++.h>

using namespace std;

class Graph{

    private:
        int V;
        list<int > * adj;
        bool isCycle(int, vector<bool>&);
    public:
        Graph(int);
        void addEdge(int, int);
        bool checkForCycle();
};

Graph::Graph(int nov){

    this->V = nov;
    adj = new list<int>[nov];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::checkForCycle(){

    vector<bool> visited(V, false);

    for(int i=0; i<V; i++){
        if(!visited[i])
            if(isCycle(i, visited))
                return true;
    }
    return false;
}

bool Graph::isCycle(int node, vector <bool> &visited){

    vector<int > parent(V, -1);
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while(!q.empty()){

        int u = q.front();
        q.pop();

        list<int> :: iterator it;
        for( it = adj[u].begin(); it!= adj[u].end(); it++){

            if(visited[*it]== false){
                q.push(*it);
                parent[*it] = u;
                visited[*it] = true;
            }else if (*it != parent[u])
                return true;
        }
    }//while

    return false;
}

int main(){

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    if(g.checkForCycle()){
        cout<<"Cycle Detected !"<<endl;
    }else{
        cout<<"Cycle Not Found !"<<endl;
    }

    return 0;

}
