
#include<bits/stdc++.h>

using namespace std;

int adj [3002][3002];

void findDistance(int source, int N){
        /*Considering vertices are starting from 0*/

        set< pair<int, int > > toProcess;

        vector<int> dist(N, INT_MAX);
        dist[source] = 0;
        toProcess.insert(make_pair(0, source));

        while(!toProcess.empty()){

            pair<int, int> tmp = *(toProcess.begin());      toProcess.erase(toProcess.begin());
            int vertex = tmp.second;

            //list<pair<int, int> >::iterator it;
            for(int i = 0; i<N; i++){

                            if(adj[vertex][i]==0) continue;

                            int w = adj[vertex][i];
                            int dest = i;

                            if(dist[dest]> dist[vertex]+ w){

                                    if(dist[dest]!=INT_MAX) //It has been updated earlier
                                        toProcess.erase(toProcess.find(make_pair(dist[dest], dest)));

                                    toProcess.insert(make_pair(dist[vertex]+w, dest));
                                    //cout<<"dest :: "<<dest<<" :: "<<dest<<dist[dest]<<" => "<<dist[vertex]+w<<endl;
                                    dist[dest] = dist[vertex]+w;
                            }

            }//for

        }//while

        for(int i=0; i<N;i++)
            if(i!=source)
            cout<<dist[i]<<" ";

}


int main(){

    int T,N,M,v,u,w,src;

    cin>>T;
    while(T--){
        cin>>N>>M;

        //vector< vector<int> > adj;
        for(int i=0; i<M; i++){
            cin>>v>>u>>w;

                if(adj[v-1][u-1]!=0)
                    w = (adj[v-1][u-1]<w)?(adj[v-1][u-1]):w;

                adj[v-1][u-1] = w;
                adj[u-1][v-1] = w;
        }

        for(int i=0; i<N;i++){
            for(int j=0; j<N; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        cin>>src;

    }

    findDistance(src-1, N);

    memset(adj, 0, sizeof(adj[0][0]) * N * N);

    return 0;
}
