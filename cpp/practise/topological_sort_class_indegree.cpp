#include<bits/stdc++.h>


using namespace std;

class Graph{

    int V;
    list<int > *adj;

public:
    Graph(int V);

    void addEdge(int u, int v);
    void topoSort();
    void printGraph();

};

Graph::Graph(int nov){
    this->V= nov;
    adj= new list<int >[nov];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

/*
        5, 2
        5, 0
        4, 0
        4, 1
        2, 3
        3, 1
*/

void Graph::topoSort(){

    //calculateIndegree
    int in_degree[V];
    for(int i=0; i<V;i++)
        in_degree[i]=0;

    for(int i=0; i<V; i++){

        list<int>::iterator it;
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
            in_degree[*it]++;
    }

    queue<int > in_q;
    for(int i=0; i<V; i++)
        if(in_degree[i]==0)
            in_q.push(i);


    int cnt=0;
    //Process the queue
    while(!in_q.empty()){

        int node = in_q.front();
        cout<<node<<" ";
        in_q.pop();


        for(list<int >::iterator it = adj[node].begin(); it!=adj[node].end(); it++){
            in_degree[*it]--;
            if(in_degree[*it]==0)
                in_q.push(*it);
        }

        cnt++;
    }

    if(cnt!=V)
        cout<<"Cycle !!!"<<endl;

}

void Graph::printGraph(){

    for(int i=0; i<this->V; i++){

        cout<<i<<" :: ";
        list<int>::iterator it;
        for(it= adj[i].begin(); it!=adj[i].end(); it++){
            cout<<*it<<" -> ";
        }
        cout<<endl;
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
    // 4 5 2 0 3 1
    g.topoSort();
    return 0;
}
