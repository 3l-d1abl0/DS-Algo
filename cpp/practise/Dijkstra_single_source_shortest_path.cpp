#include<bits/stdc++.h>

using namespace std;

class Graph{
    private:
        int V;
        int E;
        list< pair<float, int> > *adj;
        vector<float> dist;
        priority_queue< pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>> > pq;

    public:
        Graph(int, int [][2], float [], int);
        void dijkstra(int);
        void printDistance();

};

Graph::Graph(int noe, int ed[][2], float weight[], int nov){

    this->V= nov;
    this->E= noe;
    adj = new list< pair<float, int> > [nov];

    //make adjcency Graph
    for (int i = 0; i < noe; i++){
        adj[ed[i][0]].push_back(make_pair(weight[i], ed[i][1]));
        adj[ed[i][1]].push_back(make_pair(weight[i], ed[i][0]));
    }

    //init distance array as INT_MAX
    for(int i=0; i<nov; i++){
        dist.push_back(INT_MAX);
    }   
}

void Graph::dijkstra(int src){

    dist[src] =0;
    pq.push(make_pair(0.0, src));
    pair< float, int> current;
    while(!pq.empty()){
        
        current = pq.top();
        pq.pop();
        list<pair<float, int> >::iterator u;

        cout<<"Current :: "<<current.second<<" wt:: "<<current.first<<endl;
        for(u = adj[current.second].begin(); u!= adj[current.second].end(); u++){

            if(current.first+(*u).first < dist[(*u).second]){
                dist[(*u).second] = current.first+(*u).first;
                pq.push(make_pair(dist[(*u).second], (*u).second )); 
            }
        }
    }
}

void Graph::printDistance(){
   for(int i=0; i<dist.size(); i++){
       cout<<i<<" =>"<<dist[i]<<endl;
   } 
}

int main(){

    //int arr [][2] = { {0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {0,3}, {0,4} };
    //float weight[] = {5, 2, 3, 2, 3, 9, 2};

    /*
        Cant handle negative edge weights
    */

    int arr [][2] = { {0,1}, {0,4}, {0,7}, {1,2}, {1,3}, {1,7}, {2,3}, {2,6}, {3,6}, {4,5}, {4,6}, {4,7}, {5,2}, {5,6}, {7,5}, {7,2} };
    float weight[] = {5, 9, 8, 12, 15, 4, 3, 11, 9, 4, 20, 5, 1, 13, 6, 7};

    //V=6
    int noe = sizeof(arr)/sizeof(arr[0]);
    Graph g(noe, arr, weight, 8);

    g.dijkstra(0);
    g.printDistance();
    return 0;
}