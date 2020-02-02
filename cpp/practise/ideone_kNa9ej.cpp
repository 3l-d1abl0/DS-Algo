#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair< int , int >
#define vii vector< int >
#define ff first
#define ss second
#define rep(i,n) for(int i=0;i<n;i++)
#define frep(i , a , b) for(int i = a;i <= b;i++)
#define fast cin.sync_with_stdio(0);cin.tie(0);
#define CASES int t;cin >> t;while(t--)
#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define inf 0x7fffffff
const int MOD = 1e9 + 7;

ll milk[1111], app[1111];
ll dp[1111][2222];
ll rsum[1111];
int main()
{
	fast
	CASES {
		ll n, p;
		cin >> n >> p;
		memset(milk, 0, sizeof milk);
		memset(rsum, 0, sizeof rsum);
		memset(app, 0, sizeof app);
		memset(dp, 0, sizeof dp);
		rep(i, n) {
			cin >> milk[i];
		}
		rep(i, n) {
			cin >> app[i];
		}
		ll ans = 0;
		rep(i, n) ans += app[i];
		if (p >= n) {
			cout << ans << "\n";
			continue;
		}
		// dp[0][p] = 0;
		rep(i, n) {
			rep(j, 2222) {
				dp[i][j] = -1;
			}
		}
		dp[0][p - 1] = app[0];
		dp[0][p + milk[0] - 1] = 0;
		rep(i, n - 1) {
			rep(j, 2222) {
				if (dp[i][j] != -1 && j >= 1)
					dp[i + 1][j - 1] = max(dp[i][j] + app[i + 1], dp[i + 1][j - 1]);
				if (j - milk[i] >= 0 && j >= 1) {
					dp[i + 1][j - 1] = max(dp[i + 1][j], dp[i][j - milk[i]]);
				}
			}
		}
		// rep(i, n) {
		// 	rep(j, 10) {
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		rsum[n - 1] = app[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			rsum[i] = rsum[i + 1] + app[i];
		}
		ans = 0;
		rep(i, n) {
			if (dp[i][n - i - 1] != -1) {
				ans = max(ans, dp[i][n - i - 1] + rsum[i + 1]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}