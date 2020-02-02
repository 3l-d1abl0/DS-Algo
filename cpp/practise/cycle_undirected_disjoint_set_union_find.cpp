#include<bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    list<int > * adj;
    int *parent;
    int findSet(int);
    void unionSet(int, int);

    public:
        Graph(int);
        void makeAllSet(int);
        void addEdge(int, int);
        bool checkForCycle();

};

Graph::Graph(int nov){
    this->V = nov;
    adj = new list<int> [nov];
    parent = new int[nov];
}

void Graph::makeAllSet(int nov){
    for(int i=0; i<nov; i++)
        parent[i] = i;
}

void Graph::addEdge(int u, int v){

    adj[u].push_back(v);
    //adj[v].push_back(u);

}

int Graph::findSet(int u){

    if(parent[u]==u)
        return u;
    else
        return findSet(parent[u]);
}

void Graph::unionSet(int u, int v){
    parent[findSet(u)] = findSet(v);
}

bool Graph::checkForCycle(){

    //Loop for every Edge and check if vertices are in same set
    list<int>::iterator it;
    for(int u=0; u<V; u++){
        //for(it = adj[u].begin(); it!=adj[u].end(); it++){
        for (int v : adj[u]){

            cout<<u<<" :: "<<findSet(u)<<endl;
            cout<<v<<" :: "<<findSet(v)<<endl;
            //get parent/root of the set
            if (findSet(u)==findSet(v)){
                return true;
            }
            else
                unionSet(u, v);
        }
    } //for

    return false;
}

int main(){

    Graph g(6);

    g.makeAllSet(6);

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

