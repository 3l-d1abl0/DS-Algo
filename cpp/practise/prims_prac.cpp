#include<bits/stdc++.h>

using namespace std;

class Graph{

    private:
        int V;
        int E;
        list<pair<float,int>> *adj;
        bool *mst;
        //vector<bool> mst;
        vector<pair<float, int>> result;

        priority_queue< pair<float, int>, vector< pair<float, int>>, greater< pair<float, int>> > pq;
    public:

        Graph(int, int, int [][2], float []);
        void prims(int);
        void addEdge(int u, int v, float wt);
        void printMST();
};

Graph::Graph(int nov, int noe, int edges[][2], float weight[]){
    this->V = nov;
    this->E = noe;

    adj = new list<pair<float, int> >[nov];

    for(int i=0; i<E; i++){
        addEdge(edges[i][0], edges[i][1], weight[i]);
    }

    mst = new bool[V];
    for(int i=0; i<V; i++){
        mst[i] = false;
        //mst.push_back(false);
    }
}

void Graph::addEdge(int u, int v, float wt){
    adj[u].push_back(make_pair(wt, v));
    adj[v].push_back(make_pair(wt, u));
}

void Graph::prims(int vertex){

    pq.push(make_pair(0, vertex));

    pair<float, int> current_node;
    float sum = 0.0;

    while(!pq.empty()){

        current_node = pq.top();    //get minimum edge from queue
        pq.pop();

        if(mst[current_node.second] == false){

            mst[current_node.second] = true;   // add it to the mst
            result.push_back(current_node);

            for(list< pair<float, int>>::iterator it = adj[current_node.second].begin(); it != adj[current_node.second].end(); it++){

                if(mst[(*it).second] == false ){
                    pq.push((*it));
                }
            }
        }
    }//while

}

void Graph::printMST(){
    float sum =0.0;
    for(auto ele: result){
        sum+=ele.first;
        cout<<"E: "<<ele.second<<" wt: "<<ele.first<<endl;
    }

    cout<<"MST Sum : "<<sum<<endl;
}

int main(){

    /*
    int arr [][2] = { {0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {0,3}, {0,4} };
    float weight[] = {5, 2, 3, 2, 3, 9, 2};
    */

    /*
    int arr [][2] = { {0,1}, {0,4}, {0,7}, {1,2}, {1,3}, {1,7}, {2,3}, {2,6}, {3,6}, {4,5}, {4,6}, {4,7}, {5,2}, {5,6}, {7,5}, {7,2} };
    float weight[] = {5, 9, 8, 12, 15, 4, 3, 11, 9, 4, 20, 5, 1, 13, 6, 7};
    */

    int arr [][2] = { {0,7},{2,3},{1,7},{0,2},
                      {5,7},{1,3},{1,5},{2,7},
                      {4,5},{1,2},{4,7},{0,4},
                      {6,2},{3,6},{6,0},{6,4} };

    float weight[] = { 0.16, 0.17, 0.19, 0.26,
                     0.28, 0.29, 0.32, 0.34,
                     0.35, 0.36, 0.37, 0.38,
                     0.40, 0.52, 0.58, 0.93 };

    //V=6
    int noe = sizeof(arr)/sizeof(arr[0]);
    Graph g(8, noe, arr, weight);

    g.prims(0);
    g.printMST();
    return 0;
}