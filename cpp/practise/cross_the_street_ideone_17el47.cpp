
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
int Graph::shortestPath(int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[V-1];
}

int main(){
    int n,m,l,t,r,b,c,k;
    cin >> n >> m;
    vector<vector<int> > a(n,vector<int>(m,0));
    k = n*m;
    Graph g(k);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            t = (i-1)*n + j;
            l = (i)*n + j-1;
            r = (i)*n + j+1;
            b = (i+1)*n + j;
            c = (i)*n + j;

            cout<<"I: "<<i<<" J: "<<j<<endl;
            cout<<"L: "<<l<<" T: "<<t<<" R: "<<r<<" B: "<<b<<endl;

            if(t>0 & t<k) g.addEdge(c, t, abs(a[i-1][j]-a[i][j]));
            if(l>0 & l<k) g.addEdge(c, l, abs(a[i][j-1]-a[i][j]));
            if(r>0 & r<k) g.addEdge(c, r, abs(a[i][j+1]-a[i][j]));
            if(b>0 & b<k) g.addEdge(c, b, abs(a[i+1][j]-a[i][j]));
        }
    }
    cout << g.shortestPath(0) << endl;
}
