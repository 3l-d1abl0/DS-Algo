#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>

using namespace std;

int jCol[100001][2];
int cnt[100001];
int hm[100001];
int aw[100001];

int main(){

    int n,m;

    scanf("%d %d", &n, &m);

    for(int i=0; i<n;i++){
        scanf("%d %d", &jCol[i][0], &jCol[i][1]);
        cnt [jCol[i][0]] ++;
    }

for (int i = 0; i <n; i ++)
{
    cout<<(n-1)+cnt[jCol[i][1]]<<" "<<2*(n-1)-((n-1)+cnt[jCol[i][1]])<<endl;
}

    //for(int i=1; i<=n;i++){
        //printf("%d %d\n",hm[i], aw[i]);
    //}


    return 0;
}
