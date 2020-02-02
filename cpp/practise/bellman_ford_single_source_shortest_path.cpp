#include<bits/stdc++.h>

using namespace std;
//Bellman ford - single source shortest path work on Grap with
//negative edges. Also can find Graph with negative cycle

class Graph{

    private:
        int V;
        int E;
        vector<float> result;
        vector<float> dist;
        //list< pair<int, float> > *adj;
        struct Edge{
            int u, v;
            float wt;
        };

        Edge *edges;
    public:
        Graph(int, int [][2], float[], int);
        void bellmanFord(int);
        void printDistance();
};

Graph::Graph(int noe, int ed[][2], float weight[], int nov){

    this->V = nov;
    this->E = noe;

    //adj = new <pair<int, float> > [V];
    edges = new Edge[noe];

    // for(i=0; i<noe; i++){
    //     adj[ed[i][0]].push(make_pair(ed[i][1], weight[i]));
    // }
    for(int i=0; i< noe; i++){
        edges[i] = {ed[i][0], ed[i][1], weight[i]};
    }

}

void Graph::bellmanFord(int src){

    for(int i=0; i<V; i++)
        dist.push_back(FLT_MAX);

    dist[src] =0;

    for(int i=0; i<V-1; i++){

        for( int j=0; j<E; j++ ){
            if(dist[edges[j].v] > dist[edges[j].u]+edges[j].wt){
                //cout<< dist[edges[j].v]<<" "<<dist[edges[j].u]<<" + "<<edges[j].wt<<endl;
                dist[edges[j].v] = dist[edges[j].u] + edges[j].wt;
            }
        }
    }
}

void Graph::printDistance(){

    for(int i=0; i<V; i++){
        cout<<i<<" :: "<<dist[i]<<endl;
    }
}
int main(){

    /**int arr [][2] = { {4,5}, {3,4}, {2,5}, {0,2}, {1,2},
                    {5,4}, {0,3}, {0,1} };
    float weight [] = { 2, 2, 4,5,-3,1,6,4 };
    **/
   /**
    int arr [][2] = { {0,1}, {0,2}, {1,2}, {0,3}, {3,4}, {4,3},
                    {2,4}};
    float weight[] = { 4, 5, -3, 8, 2, 1, 4};
    **/

   int arr[][2] = { {0,1}, {0,2}, {1,2}, {1,4}, {1,3},
                    {3,1}, {3,2}, {4,3} };
   float weight[] = { -1, 4, 3, 2, 2, 1, 5, -3};

    int noe = sizeof(arr)/sizeof(arr[0]);
    Graph g(noe, arr, weight, 5);

    g.bellmanFord(0);
    g.printDistance();

    return 0;
}