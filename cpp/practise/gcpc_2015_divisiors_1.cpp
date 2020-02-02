
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <bitset>
#include <tuple>
#include <algorithm>
#include <functional>
#include <string>
#include <random>
#include <complex>
#include <cstring>
#include <cmath>
#include <cassert>
#include <chrono>
const int INF = 2e9+1;
const long long LLINF = 9e18+1;
const long double LDINF = 1e300+1;
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

#define REP(i,n) for(auto i = decltype(n)(0); i<(n); i++)
#define F(v) begin(v), end(v)

constexpr ll SIZE = 1e6+10;
bitset<SIZE> bs;
vector<ll> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= SIZE; ++i) if (bs[i]) {
		for (ll j = i * i; j <=SIZE; j+= i) bs[j] = 0;
		primes.push_back(i);
	}
}


// (a*b)%m
ll mulmod(ll a, ll b, ll m){
	ll x = 0, y=a%m;
	while(b>0){
		if(b&1)
			x = (x+y)%m;
		y = (2*y)%m;
		b/=2;
	}
	return x % m;
}

ll powmod(ll a, ll n, ll m){
	if(n==0) return 1;
	if(n==1) return a;
	ll aa = mulmod(a,a,m);
	if(n&1) return mulmod(a,powmod(aa,n/2,m),m);
	else return powmod(aa,n/2,m);
}


constexpr bool LOG = true;
void Log(){if(LOG) cerr << "\n";}
template<class T, class... S> void Log(T t, S... s){
	if(LOG) cerr << t << "\t", Log(s...);
}
vector<ll> test_primes = {2,3,5,7,11,13,17,19,23}; // sufficient to 3.8e18
// true when prime
bool miller_rabin(const ll n){
	if(n<2) return false;
	if(n%2==0) return n==2;
	ll s = 0, d = n-1; // n-1 = 2^s * d
	while((d&1) == 0) s++, d/=2;
	for(auto a : test_primes){
		if(a > n-2)
			break;
		ll x = powmod(a,d,n);
		if(x == 1 || x == n-1){
			continue;
		}
		REP(i,s-1){
			x = mulmod(x,x,n);
			if(x==1) return false;
			if(x==n-1) goto next_loop;
		}
		return false;
next_loop:;
	}
	return true;
}
struct Factor{ll prime; ll exp;};
vector<Factor> factor(ll n){
	vector<Factor> factor;
	for(auto & prime : primes){
		if(n==1 || prime*prime > n) break;
		ll exp=0; while(n%prime ==0) n/=prime, exp++;
		if(exp>0)
			factor.push_back({prime,exp});
	}
	// when n > SIZE^2
	// do miller rabin for primality test;
	if(n <= SIZE*SIZE){
		if(n>1) factor.push_back({n,1});
		return factor;
	}
	if(miller_rabin(n)){
		// prime
		factor.push_back({n,1});
	} else{
		// only two factors
		// check for square
		ll sq = sqrt(n);
		if( sq * sq == n){
			factor.push_back({sq,2});
		} else{
			// just make two random factors
			factor.push_back({1,1});
			factor.push_back({n,1});
		}
	}
	return factor;
}

ll numdiv(ll n){
	ll divisors = 1;
	for(auto&& p: factor(n)){
		Log(p.prime,p.exp);
		divisors *= p.exp + 1;
	}
	return divisors;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve();

	ll n; cin >> n;
	cout << numdiv(n) << "\n";

	return 0;
}

