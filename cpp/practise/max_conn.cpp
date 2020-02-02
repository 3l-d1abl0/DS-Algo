#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int visited[100002];
vector<int> mp[100002];
int spl[100002];
map <int, vector<int> > mm;

vector<int> bfs(int componentNum, int node){
    queue <int> q;
    q.push(node);
    visited[node]= componentNum;

    vector<int> reachableNodes;

    while(!q.empty()){
        int start= q.front();
                   q.pop();
        reachableNodes.push_back(start);

        for(int i=0; i<mp[start].size(); i++){
                if(!visited[mp[start][i]]){
                    q.push(mp[start][i]);
                    visited[mp[start][i]] = componentNum;
                }
        }//for
    }//while

    return reachableNodes;
}//bfs

int countSpecial(int comp){

        vector<int> temp = mm[comp];
        int cnt=0;
        for (int i=0; i<temp.size(); i++)
            if(spl[temp[i] ] ==1 ) cnt++;

        return cnt;
}

int main(){

    int N,M,P,x,y;


    scanf("%d %d %d", &N, &M, &P);

    for(int i=0;i<M;i++){
        scanf("%d", &x);
        spl[x]=1;
    }

    for(int i=0; i<P;i++){
        scanf("%d %d", &x, &y);
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    int componentNum = 0;
    int cnt=0;
    printf("Visiting.. \n");
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            componentNum++;
            mm [visited[i]] = bfs(componentNum, i );
        }
        int xx =countSpecial(visited[i]);
        cout<<":: "<<xx<<endl;
        cnt+=xx;
    }

    cout<<cnt<<endl;

    return 0;
}


/*
4 3 2
1 3 4
1 2
2 3
*/
