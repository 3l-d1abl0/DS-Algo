#include <bits/stdc++.h>

using namespace std;

#define MX 1002
#define LIMIT 1000000009

int dp[MX][MX];

int pre_comp(){

    for(int i=0; i<MX; i++)
        dp[i][i]=1;

    //[n][k]
    for(int k= MX-2; k>=1; k-- ){
        for(int n=k+1; n<=MX-1; n++){
            dp[n][k] = ( dp[n][k+1] + dp[n-k][k])%LIMIT;
        }
    }

}

int main()
{
    pre_comp();
    int t;
    scanf("%d", &t);
    int n,k;
    while(t--){
        scanf("%d %d",&n, &k);

        printf("%d\n", dp[n][k]);
    }


    return 0;
}
