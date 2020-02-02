#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100001
#define ll long long
typedef struct Node{
	int i;
	struct Node *next;
}node ,*list;
list start[MAX] = {0} ,tail[MAX] = {0};
int special[MAX] = {0};
int n,m ,x;
void addEdge(int u,int v){
	list tmp = (list)malloc(sizeof(node));
	tmp->i = v;
	tmp->next = NULL;
	if(tail[u]==NULL){
		start[u] = tmp;
		tail[u] = tmp;
	}else{
		tail[u]->next = tmp;
		tail[u] = tmp;
	}
}
void dfs(int s,int visited[],int *node,int *spe){
    visited[s]=1;
    printf("visiting ... %d\n", s);
    list pp = start[s];
    if(special[s])    (*spe)++;
    (*node)++;
    while(pp){
        if(!visited[pp->i])  dfs(pp->i ,visited ,node ,spe);
        else printf("already visited %d\n", pp->i);
        pp=pp->next;
    }
    printf("done visitng ... %d\n",s);
}
 main(){
    int i ,nodes ,sp;
    scanf("%d%d%d" ,&n ,&m ,&x);
    //printf("%d%d%d\n" ,n ,m ,x);
    for(i=0;i<m;i++){ int s;    scanf("%d" ,&s);    s--;   special[s]=1; }
    for(i=0;i<x;i++){
        int u ,v;
        scanf("%d%d" ,&u ,&v);
        u-- ,v--;
        addEdge(u ,v);
        addEdge(v,u);
    }
    int visited[n];
    ll ans=0;
    memset(visited ,0 ,sizeof(visited));
    for(i=0;i<n;i++){
        if(!visited[i]){
            nodes=0 ,sp=0;
            dfs(i ,visited ,&nodes ,&sp);
            ans+=(1LL*nodes*sp);
            printf("node=%d \t sp=%d \t ans = %lld\n",nodes, sp, ans);
        }
    }
    printf("%lld" ,ans);
    return 0;
}

/*
4 3 2
1 3 4
1 2
2 3
*/
