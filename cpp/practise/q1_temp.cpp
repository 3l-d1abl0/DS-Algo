// by realflash
#include <bits/stdc++.h>
using namespace std;

#include<limits>
#define ll long long

typedef pair<int, int > pii;
#define pb push_back
#define mk make_pair
#define MEM(a,b) memset(a,(b),sizeof(a))
#define rep(p,q,r) for(int p=q;p<r;p++)
#define repr(p,q,r) for(int p=q;p>=r;p--)
#define TEST int test; cin >> test;while(test--)
#define si(x) scanf("%d",&x)
#define author real_flash
#define si2(x,y) scanf("%d %d",&x,&y)
#define si3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define prl(x) printf("%lld\n",x)
#define ff first
#define ss second
#define BE(a) a.begin(), a.end()
#define bitcnt(x) __builtin_popcountll(x)
#define INF 111111111111111LL
#define mo 1000000007
//std::cout << std::setprecision(3) << std::fixed;
int MAX=numeric_limits<int>::max();
const int N=1e3+5;
//ios_base::sync_with_stdio(0);cin.tie(0);

int s[N][N];
int n,k;
queue<int> ts ;
queue<int> pr;
int ans=0;
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("D:/progs/input.txt", "r", stdin);
	//freopen("D:/progs/output.txt", "w", stdout);
//#endif

	TEST
	{
		cin>>n>>k;
		cout<<"entered value1 "<<n<<" "<<k<<"\n";
		rep(i,0,n)
		rep(j,0,n)
		{
		    char ch;
		    cin>>ch;
		    cout<<"yuu "<<ch<<"\n";
    }
		ans=0;

		rep(i,1,n+1)
		{
			rep(j,1,n+1)
			cout<<i<<","<<j<<" "<<s[i][j]<<"\n";
		}

		rep(i,1,n+1)
		{
				                                                                                                                                                                                                                                                                                                                                                                                                              ;
				while(!ts.empty())
				{
					ts.pop();
				}


				while(!pr.empty())
				{
					pr.pop();
				}

				rep(j,1,n+1)
				{
					cout<<i<<" "<<j<<"\n";
					if(s[i][j]=='T')
					{
						cout<<i<<" * "<<j<<" "<<s[i][j]<<"\n";
						while(!pr.empty()&&i-pr.front()>k)
							{
								pr.pop();
							}
							if(!pr.empty())
							{
								ans++;
								pr.pop();
							}
							else
							{
								ts.push(i);
							}
					}
					else
					{
						cout<<i<<" -- "<<j<<" "<<s[i][j]<<"\n";

						while(!ts.empty()&&i-ts.front()>k)
							{
								ts.pop();
							}
							if(!ts.empty())
							{
								ans++;
								ts.pop();
							}
							else
							{
								pr.push(i);
							}

					}
				}
		}

		cout<<ans<<"\n";
	}

}
