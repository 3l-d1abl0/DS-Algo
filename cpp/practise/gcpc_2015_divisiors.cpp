
By Simp_, contest: 2015 German Collegiate Programming Contest (GCPC 15) + POI 10-T3, problem: (F) Divisions, Accepted, #
 #include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

const int N6 = 1e6 + 6;
const int N9 = 1e9 + 7;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <int, ll> PIl;
typedef pair <ll, int> PlI;
typedef pair <ll, ll> Pll;


#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(x, a, b) for (int x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = b; x >= a; --x)
#define sz() size()
#define skip continue
#define gg exit(0)
#define boost ios_base::sync_with_stdio(0),cin.tie(NULL)
#define task ""

ll t, n, a[1000006], iN, N, t1[4 * 1000006];

inline ll Mult(ll x, ll y, ll md){
    ll res = 0;
    while (y){
        if (y & 1) res = (res + x) % md, y--;
        x = (x + x) % md, y >>= 1;
    }
    return res % md;
}

inline ll Pw(ll x, ll y, ll md){
    ll res = 1;
    while (y){
        if (y & 1) res = Mult(res, x, md), y--;
        y >>= 1, x = Mult(x, x, md);
    }
    return res % md;
}

inline ll isP(ll x){
    if (x == 2) return 1;
    for (int i = 1; i <= 100; i++){
        ll a = (rand() % (x - 2)) + 2;
        if (__gcd(a, x) != 1) return 0;
        if (Pw(a, x - 1, x) != 1) return 0;
    }
    return 1;
}

void input(){
	while(cin>>a[++iN]);
	N = iN;
	n = a[1];
}

void output(){
	while(--iN)cout<<a[N - iN]<<' ';
}

int main(){




	srand(time(0));

	boost;

	input();

	ll ans = 1,cnt = 1;

	for(ll i = 2; i * i * i <= n; ++i){
		while(n%i==0)n/=i,++cnt;
		if(cnt > 1)ans *= cnt,cnt=1;
	}

	if(isP(n))cout << ans * 2,gg;
	if(sqrt(n) * sqrt(n) == n && n > 1)cout << ans * 3,gg;
	if(n > 1)cout << ans * 4,gg;
	cout << ans;

	return 0;
}
