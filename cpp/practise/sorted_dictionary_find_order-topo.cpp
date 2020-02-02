#include<bits/stdc++.h>

using namespace std;

class Graph{

    int N;
    list <int > *adj;

    void tsort(int i, bool visited[], stack<int> &st);

public :
    Graph(int N);
    void showGraph();
    void toposort();
    void addEdge(int v, int u);

};

Graph::Graph(int V){
    this->N=V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int v, int u){

    adj[v].push_back(u);
}

void Graph::showGraph(){

    list<int>::iterator j;
    for(int i=0; i<N; i++){
        cout<<i<<" :: ";
        for(j=adj[i].begin(); j!=adj[i].end(); j++){
            cout<<*j<<" ";
        }

        cout<<endl;
    }
}

void Graph::tsort(int i, bool visited[], stack<int> &st){

    visited[i]= true;

    cout<<endl;
    for(int i=0; i<this->N; i++)
        cout<<visited[i]<<" ";
    cout<<endl;

    list<int>::iterator it;

    for(it=adj[i].begin(); it!=adj[i].end();it++){
        if(!visited[*it])
            tsort(*it, visited, st);
    }

    st.push(i);
}

void Graph::toposort(){

    stack<int> st;
    bool * visited = new bool[N];
    memset(visited,false, sizeof(visited));


    for(int i=0; i<N; i++){
        if(!visited[i]){
            tsort(i, visited, st);
        }
    }

    while(!st.empty()){
        cout<<(char)('a'+st.top())<<" ";
        st.pop();
    }
}

void printOrder(string words[], int N, int ch){

    //initalizethe Graph
    Graph g(ch);

    //Make Graph based on dictionary
    for(int i=0; i<=N-2;i++){

        string w1 = words[i]; string w2 = words[i+1];

        for(int j=0; j<min(w1.length(), w2.length()); j++){

            if(w1[j]!=w2[j]){
                g.addEdge(w1[j]-'a', w2[j]-'a');
                break;
            }
        }
    }

    //g.showGraph();
    g.toposort();

}

int main(){

    	//string words[] = {"caa", "aaa", "aab"};
	string words[] = {"baa", "abcd", "abca", "cab", "cad"};
	printOrder(words, 5, 4);
	return 0;

}
