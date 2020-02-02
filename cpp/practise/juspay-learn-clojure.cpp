#include<bits/stdc++.h>

using namespace std;

int dijs(map<int, vector<pair<int,int>> > &adjlist, map<int, int> &dist, int src, int desc){

    dist[src] =0;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push(make_pair(0, src));
    pair<int, int> current;

    while(!pq.empty()){

        current = pq.top();
        pq.pop();

        vector<pair<int, int>>::iterator it;

        for(it = adjlist[current.second].begin(); it!= adjlist[current.second].end();it++){
            

            if(current.first+ (*it).second < dist[(*it).first]){
                dist[(*it).first] = current.first+ (*it).second;
                pq.push(make_pair(dist[(*it).first], (*it).first));
            }

        }
    }

    map<int, int>::iterator it;
    for(it=dist.begin(); it!=dist.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return dist[desc];
}

int main(){

    int N,x;

    cin>>N;
    vector<int> vec;
    map<int, int> dist;

    for(int i=0; i<N; i++){
        cin>>x;
        vec.push_back(x);
        dist[x]= INT_MAX;
    }

    int E,u,v;
    cin>>E;
    vector<pair<int, int>> edges;
    vector<int> weight;

    map<int, vector<pair<int,int>> >adjlist; 

    for(int i=0; i<E; i++){
        cin>>u>>v>>x;
        //edges.push_back(make_pair(u,v));
        //weight.push_back(x);
        adjlist[u].push_back(make_pair(v,x));
    }

    int src, desc;
    cin>>src>>desc;

    cout<<dijs(adjlist, dist, src, desc)<<endl;

    return 0;
}