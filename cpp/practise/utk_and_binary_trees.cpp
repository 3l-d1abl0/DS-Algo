#include <stdio.h>
#define MOD 1000000007
int h;
long long int dp[501][501];
long long int solve(int n, int curHeight)
{
    printf("n= %d  curHeight = %d\n", n, curHeight);

	if(n<2){
	   printf("==> ans = 1 \n\n");
	   return 1;
	}

	if(dp[n][curHeight]>-1){
	    printf("==> Ans = %d \n\n",dp[n][curHeight]);
	    return dp[n][curHeight];
	}
	long long int ans = 0;
	long long int leftST, rightST;
	int root;
	for(root=1; root<=n; root++)
	{
		leftST=0;
		rightST=0;
		if(curHeight+1<=h)
		{
		    printf("root = %d n= %d  curHeight = %d\n",root,n, curHeight);
			leftST = solve(root-1,curHeight+1)%MOD;
			rightST = solve(n-root,curHeight+1)%MOD;
			/*if(curHeight == 0)
			    ans=ans+(((root*leftST)%MOD*rightST)%MOD);
			else*/
			    ans=ans+((leftST*rightST)%MOD);
			ans=ans%MOD;
		}
	}
    printf("==> ANS = %d  n= %d  curHeight = %d\n\n", ans%MOD, n, curHeight);
	return dp[n][curHeight]=ans % MOD;
}

int main()
{
    int n,i,j;
    for(i=0;i<501;i++)
    for(j=0;j<501;j++)
    dp[i][j]=-1;
    scanf("%d%d",&n,&h);
    h--;
    printf("%lld\n",solve(n,0));
    return 0;
}
