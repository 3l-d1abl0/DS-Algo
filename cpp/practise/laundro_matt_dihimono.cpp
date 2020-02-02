
#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

long long w[100005];

void sol() {
	int l, n, m, d;
	priority_queue<pair<long long, int>> pq;
	scanf("%d%d%d%d", &l, &n, &m, &d);
	for(int i = 0;i < n;i++) {
		scanf("%lld", &w[i]);
		pq.push(pair<long long, int>(-w[i], i));
	}
	vector<long long> wtq;
	for(int i = 0;i < l;i++) {
		auto x = pq.top(); pq.pop();
		wtq.push_back(-x.first);
		pq.push(pair<long long, int>(x.first - w[x.second], x.second));
	}
	sort(wtq.begin(), wtq.end());
	vector<long long> dryer;
	long long ans = 0;
	for(int i = 0;i < wtq.size();i++) {
		if(dryer.size() == m)
			dryer[i % m] = max(dryer[i % m] + d, wtq[i] + d);
		else dryer.push_back(wtq[i] + d);
		ans = max(ans, dryer[i % m]);
	}
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	for(int i = 1;i <= t;i++) printf("Case #%d: ", i), sol();
}
