#include<bits/stdc++.h>
#define MAX 100000009
using namespace std;


int main(){

    int N,M,d,Q;
    string str1, str2;
    long long int adj[102][102];
    map<string, int> city;

    //memset(adj, MAX, sizeof(adj[0][0]) * 102 * 102);

    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>str1;   city[str1]=i;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) adj[i][j]=0;
            else adj[i][j]= MAX;
        }
    }

    for(int i=0; i<M; i++){
        cin>>str1>>str2>>d;
        adj[city[str1]][city[str2]] = d;
        adj[city[str2]][city[str1]] = d;
    }


    cin>>Q;
    //
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                if(adj[i][j] > adj[i][k]+adj[k][j] ){
                        adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
    //


    while(Q--){
        cin>>str1>>str2;
        cout<<adj[city[str1]][city[str2]]<<endl;
    }


    return 0;
}
