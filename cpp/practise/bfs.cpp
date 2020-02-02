#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#define N 4

using namespace std;

bool visited[N];
vector<int> mp[N];

void bfs(int node){
    queue <int> q;
    q.push(node);
    visited[node]= true;

    while(!q.empty()){
        int start= q.front();
                   q.pop();
        printf("%d ",start);
        for(int i=0; i<mp[start].size(); i++){
                if(!visited[mp[start][i]]){
                    q.push(mp[start][i]);
                    visited[mp[start][i]] = true;
                }
        }//for
    }//while
}//bfs

int main(){

    mp[0].push_back(2); mp[2].push_back(0);
    mp[1].push_back(2); mp[2].push_back(1);
    mp[2].push_back(3); mp[3].push_back(2);
    mp[3].push_back(3);
    printf("Visiting.. \n");
    for(int i=0; i<N; i++){
        if(!visited[i])
            bfs(i);
    }

    return 0;
}
