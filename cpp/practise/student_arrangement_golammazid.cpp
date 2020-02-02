#include<stdio.h>
#define Sz 100005
int visit[Sz],next[Sz];
int findNext(int c,int k,int m,int s,int f){
    if(next[c]==0){
        return 0;
    }
    if(c==0)
        return next[c]=0;
    if(c==s&&f)
        return next[c]=0;
    if(next[c]==c&&visit[c]<k){
        return c;
    }
    if(c+1>m)
        return next[c] = findNext(1,k,m,s,1);
    return next[c] = findNext(c+1,k,m,s,1);
}
int main(){
    int n,m,k,i,c,ans;
    while(scanf("%d%d%d",&n,&m,&k)==3){
        ans=0;
        for(i=0;i<=Sz;i++){
            visit[i]=0;
            next[i]=i;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&c);
            if(visit[c]==k){
                ans++;
                if(c==m){
                    next[c] = findNext(1,k,m,1,0);
                } else{
                    next[c] = findNext(next[c],k,m,next[c],0);
                }
                visit[next[c]]++;
            }else{
                visit[c]++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
