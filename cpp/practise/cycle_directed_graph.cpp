#include<bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    list<int> *adj;
    bool isCycle(int v, bool *visited, bool *recStack );

public:
    Graph(int n);
    void addEdge(int u, int v);
    bool checkForCycle();
};

Graph::Graph(int v){
    this->V= v;
    adj = new list<int>[v];
}
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

bool Graph::isCycle(int v, bool *visited, bool *recStack){

    if(visited[v] == false){

        visited[v] = true; recStack[v]=true;
        list<int>::iterator i;
        for(i= adj[v].begin(); i!=adj[v].end(); i++){

            if(recStack[*i])
                return true;
            else if(visited[*i]==false && isCycle(*i, visited, recStack) )
                return true;

            //else if()

        }
    }

    recStack[v] = false;
    return false;
}

bool Graph::checkForCycle(){

    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for(int i=0; i<V; i++){
        visited[i] = false; recStack[i]=false;
    }

    //DFSing
    for(int i=0; i<V; i++){
        if(isCycle(i, visited, recStack))
            return true;
    }

    return false;
}


int main(){

    //https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.checkForCycle()){
        cout<<"Cycle Detected !"<<endl;
    }else{
        cout<<"Cycle Not Found !"<<endl;
    }

    return 0;
}
