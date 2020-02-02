#include<bits/stdc++.h>

using namespace std;

class Graph{

    private:
        int V;
        list<int > *adj;
        bool isCycle(int node, bool visited[], int parent);

    public:
        Graph(int n);
        void addEdge(int u, int v);
        bool checkForCycle();

};

Graph::Graph(int n){
    this->V = n;
    adj = new list<int>[n];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::checkForCycle(){
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    bool stat = false;
    for(int i=0; i<V; i++){
        if(!visited[i])
            if(isCycle(i, visited, -1))
                return true;
    }

    return false;
}

bool Graph::isCycle(int node, bool visited[], int parent){

    visited[node] = true;
    cout<<"Checking :: "<<node<<endl;
    list<int > :: iterator it;

    for(it= adj[node].begin(); it!=adj[node].end(); it++){

        cout<<"neigh :: "<<*it<<" "<<visited[*it]<<endl;

        if( visited[*it] == false){ // node is unvisted
            if(isCycle(*it, visited, node))
                return true;
        }else if(parent != *it) // if the neighbour node has visited true and is not parent
            return true;
    }
    return false;
}

int main(){

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    //g.addEdge(1, 2);
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
