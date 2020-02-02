#include<bits/stdc++.h>


using namespace std;

class Graph{

    int V;
    list<int > *adj;
    char *color;
    bool isCycle(int i);

    public:
        Graph(int);
        void addEdge(int, int);
        bool checkForCycle();
};


Graph::Graph(int nov){

    this->V = nov;
    adj = new list<int>[nov];
    color = new char[nov];
    for(int i=0; i<nov; i++)
        color[i] = 'W'; //WHITE , all not visited nodes are White
}

void Graph::addEdge(int u, int v){

    adj[u].push_back(v);
}

bool Graph::checkForCycle(){

    for(int i=0; i<V; i++){

        if(color[i]=='W')
            if(isCycle(i))
                return true;
            color[i] = 'B'; //BLACK , since this vertex has been

    }
    return false;
}

bool Graph::isCycle(int u){

    color[u] = 'G'; //GREY, since this vextes is being discovered
    list<int>::iterator it;

    for(it = adj[u].begin(); it!= adj[u].end(); it++){

        if(color[*it]=='G')
            return true;

        if(color[*it]=='W' && isCycle(*it))
            return true;
    }

    return false;

}

int main(){

    Graph g(6);

    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 4);
    g.addEdge(4, 2);

    if(g.checkForCycle()){
        cout<<"Cycle Detected !"<<endl;
    }else{
        cout<<"Cycle Not Found !"<<endl;
    }

    return 0;

}
