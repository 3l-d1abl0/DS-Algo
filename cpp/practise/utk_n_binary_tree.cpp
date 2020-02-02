#include<bits/stdc++.h>

#define MOD 1000000007


using namespace std;

int N,H;

long long int getAns(int H, int N){

    long long int dp[H+1][N+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=H; i++){
        dp[i][0]=1;
    }

    for(int n=1; n<=N; n++){

            for(int h=1; h<=H; h++){
                    //printf("h= %d n= %d \n", h,n);
                    for(int k=1; k<=n; k++){
                        dp[h][n] =   (dp[h][n]+ dp[h-1][k-1]*dp[h-1][n-k] )%MOD;  //No of Nodes
                        //printf(" ==> dp[%d][%d]  *  dp[%d][%d]= %d\n", n, h, dp[n][h]);
                        //printf("dp[%d][%d] = %d\n", h, n, dp[h][n]);
                    }
            }
            //cout<<endl;
		}


    long long ans =0;
    for(int n=1; n<=N; n++){
        ans = (ans + ( (n*dp[H-1][n-1])%MOD*dp[H-1][N-n])%MOD )%MOD;
    }

    return ans;
}

int main(){

    cin>>N>>H;

    cout<<getAns(H, N);

    return 0;
}
