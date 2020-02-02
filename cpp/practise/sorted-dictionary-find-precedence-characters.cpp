#include<bits/stdc++.h>

using namespace std;

class Graph{

        int V;
        list<int> *adj;

        void topoSort(int v, bool vis[], stack<int > &st);
        void addEdge(int v, int u);
public :

        Graph(int);
        void makeGraph(string words[], int sz);
        void topo();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int u){
    adj[v].push_back(u);
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


void Graph::topoSort(int v, bool vis[], stack<int> &Stack){

    vis[v] = true;

    list<int >::iterator it;
    for(it = adj[v].begin(); it!=adj[v].end(); it++)
        if(!vis[*it]){
                topoSort(*it, vis, Stack);
        }

    Stack.push(v);
}

void Graph::topo(){

    stack<int> Stack;

    bool *vis = new bool[V];
    for(int i=0; i<V; i++)
        vis[i] = false;


    for(int i=0; i<V; i++){
        if(vis[i]==false)
            topoSort(i, vis, Stack);
    }

    while(!Stack.empty()){
        cout<< (char) ('a'+Stack.top())<<" ";
        Stack.pop();
    }
}

int main(){

    string words[] = {"baa", "abcd", "abca", "cab", "cad"};

    int sz = sizeof(words)/sizeof(words[0]);

    Graph g(4);    //max # vertex

    g.makeGraph(words, sz);
    cout<<"Calling topo Sort "<<endl;

    g.topo();

    return 0;
}
