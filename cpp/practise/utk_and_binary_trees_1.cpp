#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define all(v)                      v.begin(),v.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
LL dp[5010][5010];
int N,H;
int main()
{
	cin>>N>>H;
	for(int h=0;h<=H;h++)
		dp[0][h] = 1;

	for(int i=1;i<=N;i++)
		for(int h=1;h<=H;h++){
			printf("i= %d h= %d \n", i,h);
			for(int k=1;k<=i;k++){
				dp[i][h] = (dp[i][h] + dp[k-1][h-1]*dp[i-k][h-1])%MOD;
                printf("dp[%d][%d] = %d\n", i, h, dp[i][h]);
			}
			cout<<endl;
		}

	LL ans = 0;
	for(int k=1;k<=N;k++)
		ans = (ans + ((k*dp[k-1][H-1])%MOD*dp[N-k][H-1])%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}
