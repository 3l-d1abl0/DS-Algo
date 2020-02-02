#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;
int main()
{
    int t,c=0,i,target;

    long long int P;

    int     dp[1002][1002];

    scanf("%d",&t);
    int arr[t];
    while((t--)>0)
    {
           int N,P,i,j;
           target=0;
           scanf("%d",&N);
           scanf("%lld",&P);
           int milk[N],apples[N];
           for(i=0;i<N;i++)
               scanf("%d",&milk[i]);
           for(i=0;i<N;i++){
               scanf("%d",&apples[i]);
                target +=apples[i];
           }

            if(P>=N){
                printf("%d\n", target);
                continue;
            }

            for(i=0; i<N; i++) {
                dp[0][i] = apples[i];
            }

            for(i=1; i<N; i++) {
                for(j=0; j< N; j++) {
                    dp[i][j] = max(dp[i-1][j+1] + apples[i] , dp[i-1][j-milk[i]]);
                }
            }

            int max_apple = 0;

            for(i=0; i<N; i++) {
                    if(dp[N][i] > max_apple)
                    max_apple = dp[N][i];
            }

            cout<<max_apple<<endl;
    }

    return 0;
}
