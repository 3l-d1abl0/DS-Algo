#include<bits/stdc++.h>

using namespace std;

struct Edge{

    int u,v;
    float wt;
    bool operator<(Edge const &other){
        return wt < other.wt;
    }
};


class Graph{

    private:
        int E;
        int V;
        bool *mst;
        list<pair<float, int>> *adj;
        vector<Edge> result;
        priority_queue< pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>> > pq;

    public:
        Graph(int, int[][2], float[], int);
        void prims(int);
        void printMST();
};

Graph::Graph(int noe, int ed[][2], float weight[], int nov){

    this->V= nov;
    this->E= noe;
    mst = new bool[nov];
    adj = new list< pair<float, int> >[nov];

    //create adjcent list from edges
    for(int i=0; i<noe; i++){
        adj[ed[i][0]].push_back(make_pair(weight[i], ed[i][1]));
        adj[ed[i][1]].push_back(make_pair(weight[i], ed[i][0]));
    }
    //Initalize mst array // none of the nodes are in MST
    for(int i=0; i<nov; i++)
        mst[i] = false;

}

void Graph::prims(int vtx){

    pq.push(make_pair(0.0, vtx));
    pair<float, int> pp;
    float sum = 0.0;
    while(!pq.empty()){
        pp = pq.top();
             pq.pop();

        if(mst[pp.second]==false){ // current node is not is mst, can be processed further
           mst[pp.second] = true;
            sum += pp.first;
            cout<<pp.first<<" "<<pp.second<<endl;
           for( pair<float, int > u: adj[pp.second] ){
               if(mst[u.second]==false)
                pq.push(u);
           }
        }

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

    g.prims(0); //starting from node 0
    //g.printMST();

    return 0;

}