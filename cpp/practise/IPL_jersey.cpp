/*
3
3*2

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>

using namespace std;

int jCol[100001][2];
int hm[100001];
int aw[100001];

int main(){

    int n,m;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n;i++){
        scanf("%d %d", &jCol[i][0], &jCol[i][1]);
        hm[i]=n-1;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1; j<=n;j++){
                if(jCol[i][0] == jCol[j][1]){ hm[j]++; }
                else{ aw[j]++; }

                if(jCol[j][0] == jCol[i][1]){ hm[i]++; }
                else{ aw[i]++; }
        }
        printf("%d %d\n",hm[i], aw[i]);
    }

    //for(int i=1; i<=n;i++){
        //printf("%d %d\n",hm[i], aw[i]);
    //}


    return 0;
}
