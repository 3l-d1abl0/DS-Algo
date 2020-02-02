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


void dfs(int visited[], int start, int *node_num, int *spcl){
    printf("visiting ... %d\n", start);
    (*node_num)++;
    visited[start]= 1;
    if(spl[start])  (*spcl)++;

    for(int i=0; i<mp[start].size(); i++)
            if(!visited[mp[start][i]])
                dfs(visited, mp[start][i], node_num, spcl);

    printf("done visitng ... %d\n",start);
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
    //printf("Visiting.. \n");

    long long int tot = 0;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            int node_num=0, spcl=0;
            dfs(visited,i,&node_num,&spcl);
            tot = tot +(long long int )node_num * spcl;
            printf("node=%d \t sp=%d \t ans = %lld\n",node_num, spcl, tot);
        }

    }

    //cout<<"TOt :: "<<tot<<endl;
    cout<<tot<<endl;

    return 0;
}
