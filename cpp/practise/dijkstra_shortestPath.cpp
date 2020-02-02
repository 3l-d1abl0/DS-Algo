#include<bits/stdc++.h>

using namespace std;

class Graph{

    int V;
    list<pair<int, int > > *adj;

    struct Node{
        int weight;
        int vertex;

        bool operator<(const Node &k)const{
            return weight>k.weight;
        }
    };

public:
    Graph(int);

    void addEdge(int vertex, int node, int weight);
    void findDistance(int source);
    void getW(int , int);
};

Graph::Graph(int nov){
    this->V= nov;
    this->adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int vertex, int node, int weight){

    this->adj[vertex].push_back(make_pair(node, weight));
    this->adj[node].push_back(make_pair(vertex, weight));

}
//void Graph::getW(int v, int u){
//
//            cout<<adj[v].size();
//            for(int i=0; i<adj[v].size(); i++){
//                cout<<adj[v][i].first<<endl;
//            }
//            list<pair<int, int> >::iterator it;
//            for(it = adj[v].begin();  it!=adj[v].end(); it++ ){
//
//                            cout<<v<<" : "<<(*it).first<<" = "<<(*it).second<<endl;
//            }
//}

void Graph::findDistance(int source){
        /*Considering vertices are starting from 0*/

        set< pair<int, int > > toProcess;

        vector<int> dist(V, INT_MAX);
        dist[source] = 0;
        toProcess.insert(make_pair(0, source));

        while(!toProcess.empty()){

                for (set<pair<int, int > >::iterator it=toProcess.begin(); it!=toProcess.end(); ++it)
                    cout<<(*it).first<<" "<<(*it).second<<endl;

                cout<<endl;

            //Extract Min
            pair<int, int> tmp = *(toProcess.begin());      toProcess.erase(toProcess.begin());
            int vertex = tmp.second;

            list<pair<int, int> >::iterator it;
            for(it = adj[vertex].begin();  it!=adj[vertex].end(); it++ ){

                            int w = (*it).second;
                            int dest = (*it).first;

                            if(dist[dest]> dist[vertex]+ w){

                                    if(dist[dest]!=INT_MAX) //It has been updated earlier
                                        toProcess.erase(toProcess.find(make_pair(dist[dest], dest)));

                                    toProcess.insert(make_pair(dist[vertex]+w, dest));
                                    dist[dest] = dist[vertex]+w;
                            }

            }//for

        }//while

        for(int i=0; i<V;i++)
            cout<<i<<" : "<<dist[i]<<endl;




}

int main(){

    Graph g(6);

    g.addEdge(0,1,5);
    g.addEdge(0,1,9);
    g.addEdge(0,3,9);
    g.addEdge(0,4,2);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);


    //g.getW(0,2);
    g.findDistance(0);

    return 0;
}
