#include <iostream>
#include<cstdio>
#include <vector>

using namespace std;

// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<long long> &v, int l, int r, int key) {
	while (r-l > 1) {
	int m = l + (r-l)/2;
	if (v[m] >= key)
		r = m;
	else
		l = m;
	}

	return r;
}

int LongestIncreasingSubsequenceLength(std::vector<long long> &v) {
	if (v.size() == 0)
		return 0;

	std::vector<long long> tail(v.size(), 0);
	int length = 1;

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] < tail[0])
			tail[0] = v[i];
		else if (v[i] > tail[length-1])
			tail[length++] = v[i];
		else
			tail[CeilIndex(tail, 0, length-1, v[i])] = v[i];
	}
	return length;
}

int main() {
	int N;
	long long zz;
	scanf("%d", &N);
	vector<long long> v;
	for(int i=0; i<N; i++){
        scanf("%lld", &zz);
        v.push_back(zz);
	}

	std::cout << N- LongestIncreasingSubsequenceLength(v);
return 0;
}
