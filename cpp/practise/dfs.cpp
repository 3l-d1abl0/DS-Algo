#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>

#define N 4

using namespace std;

bool visited[N];
vector<int> mp[N];

using namespace std;

void dfs(int node){
    printf("%d ",node);
    visited[node]=true;

    for(int i=0;i< mp[node].size(); i++){
        if(!visited[mp[node][i]])
            dfs(mp[node][i]);
    }
}


int main(){

    mp[0].push_back(2); mp[2].push_back(0);
    mp[1].push_back(2); mp[2].push_back(1);
    mp[2].push_back(3); mp[3].push_back(2);
    mp[3].push_back(3);
    printf("Visiting.. \n");
    for(int i=0; i<N; i++){
        if(!visited[i])
            dfs(i);
    }

    return 0;
}
