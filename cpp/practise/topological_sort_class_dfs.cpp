#include<bits/stdc++.h>

using namespace std;

class Graph{

    int nov;

    list<int> *adj;

    void topoSortUtil(int node, bool visited[], stack<int> &st);

public:
    Graph(int v);

    void addEdge(int v, int u);

    void topoSort();

    void printGraph();

};

/*
        5, 2
        5, 0
        4, 0
        4, 1
        2, 3
        3, 1
*/

Graph::Graph(int v){
    this->nov = v;
    adj = new list<int>[nov];
}

void Graph::addEdge(int v, int u){
    adj[v].push_back(u);
}

void Graph::printGraph(){

    for(int i=0; i<this->nov; i++){

        cout<<i<<" :: ";
        list<int>::iterator it;
        for(it= adj[i].begin(); it!=adj[i].end(); it++){
            cout<<*it<<" -> ";
        }
        cout<<endl;
    }
}

void Graph::topoSortUtil(int node, bool visited[], stack<int> &st){

    list<int >::iterator it;
    visited[node] = true;
    for(it= adj[node].begin(); it!=adj[node].end(); it++){
            if(visited[*it]==false)
                topoSortUtil(*it, visited, st);
    }

    st.push(node);
}


void Graph::topoSort(){

    bool visited[this->nov];
    for(int i=0; i<this->nov; i++)
        visited[i]= false;

    stack<int > st;
    for(int i=0; i<this->nov; i++)
        if(visited[i]==false)
                topoSortUtil(i, visited, st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

int main(){

    Graph g(6);

    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.printGraph();

    g.topoSort();


    return 0;
}
