#include<bits/stdc++.h>

using namespace std;

struct Edge{

    int u, v;
    float wt;
    bool operator<(Edge const &other){
        return wt < other.wt;
    }
};

class Graph{

    private:
        int E;
        int V;
        int *parent;
        vector<Edge> edges;
        vector<Edge> result;
        void makeAllSet();
        void prepareEdge();
        int findSet(int);
        void unionSet(int ,int);
        void prepareEdges(int [][2], float []);

    public:
        Graph(int, int [][2], float[], int);
        void Kruskal();
        void printMST();

};

void Graph::makeAllSet(){
    for(int i=0; i<V; i++){
        parent[i]=i;
    }
}

int Graph::findSet(int u){

    if(parent[u] == u)
        return u;
    else
        return findSet(parent[u]);
}

void Graph::unionSet(int u,int v){
    parent[findSet(u)] = findSet(v);
}

void Graph::prepareEdges(int ed[][2], float weight[]){

    for(int i=0; i<E; i++){
        edges.push_back({ed[i][0], ed[i][1], weight[i]});
    }

    sort(edges.begin(), edges.end());
}

Graph::Graph(int noe, int ed[][2], float weight[],  int nov){
    this->V = nov;
    this->E = noe;
    //cout<<"E:: "<<E<<endl;
    parent = new int[E];

    makeAllSet();
    prepareEdges(ed, weight);
}

void Graph::Kruskal(){

    //for(int i=0; i<E; i++){
    for(Edge e: edges){

        if( findSet(e.u) != findSet(e.v)){
            result.push_back({e.u, e.v, e.wt});
            unionSet(e.u,e.v);
        }
    }
}

void Graph::printMST(){

    float sum = 0.0;
    for(Edge e: result){

        sum += e.wt;
        cout<<e.u<<" "<<e.v<<" ,"<<e.wt<<endl;
    }
    cout<<"Weight of MAT :: "<<sum<<endl;

}

int main(){

    int arr [][2] = { {0,7},{2,3},{1,7},{0,2},
                      {5,7},{1,3},{1,5},{2,7},
                      {4,5},{1,2},{4,7},{0,4},
                      {6,2},{3,6},{6,0},{6,4} };

    float weight[] = { 0.16, 0.17, 0.19, 0.26,
                     0.28, 0.29, 0.32, 0.34,
                     0.35, 0.36, 0.37, 0.38,
                     0.40, 0.52, 0.58, 0.93 };

    //V= 8
    int noe = sizeof(arr)/sizeof(arr[0]);
    Graph g(noe, arr, weight, 8);

    g.Kruskal();
    g.printMST();

    return 0;

}
