#include<bits/stdc++.h>

using namespace std;

class Graph{

        int V;
        list<int> *adj;
        int *indegree;  //in degree array
        priority_queue<int, vector<int>, greater<int> > toProcess;

        void addEdge(int v, int u);
public :

        Graph(int);
        void makeGraph(string words[], int sz);
        void topo();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    indegree = new int [V];
    for(int i=0; i<V; i++)
        indegree[i] = 0;
}

void Graph::addEdge(int v, int u){
    adj[v].push_back(u);
    indegree[u]++;
};

void Graph::makeGraph(string words[], int n){

    for(int i=0; i<=n-2; i++){

        string w1= words[i];
        string w2 = words[i+1];
            for(int j=0; j< min(w1.length(), w2.length()); j++){

                if(w1[j]!=w2[j]){
                    addEdge(w1[j]-'a', w2[j]-'a');
                    break;
                }
            }
    }

}

void Graph::topo(){

    for(int i=0; i<V; i++){
        if(indegree[i]==0)
            toProcess.push(i);
    }

    while(!toProcess.empty()){

        int v = toProcess.top();
        toProcess.pop();

        cout<<(char)('a'+v)<<"  ";

        list<int>::iterator it;
        for(it = adj[v].begin(); it!=adj[v].end(); it++){
            int u = *it;
            indegree[u]--;
            if(indegree[u]==0)
                toProcess.push(u);
        }

    }

}

int main(){

    string words[] = {"baa", "abcd", "abca", "cab", "cad"};

    int sz = sizeof(words)/sizeof(words[0]);

    Graph g(4);    //max # vertex

    g.makeGraph(words, sz);

    g.topo();

    return 0;
}
