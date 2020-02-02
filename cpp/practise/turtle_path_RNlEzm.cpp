#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000][1000];
struct node{
    int x;
    int y;
    node* prev;
    node(int x, int y, node* par): x(x), y(y), prev(par)
    {
    }
};

vector<pair<int, int > > v;
int vis[1000][1000];
int path[1000][1000];

bool backtrack(int i, int j){
	if(i == n-1 && j == m-1){
		v.push_back(make_pair(i+1, j+1));
		return true;
	}
	vis[i][j] = 1;
	int x = i+1;
	int y = j+1;

	if(!vis[x][y] && path[x][y] > 0){
		if(backtrack(x, y)){
			v.push_back(make_pair(i+1, j+1));
			return true;
		}
	}
	x = i+1;
	y = j;
	if(!vis[x][y] && path[x][y] > 0){
		if(backtrack(x, y)){
			v.push_back(make_pair(i+1, j+1));
			return true;
		}
	}
	x = i;
	y = j+1;
	if(!vis[x][y] && path[x][y] > 0){
		if(backtrack(x, y)){
			v.push_back(make_pair(i+1, j+1));
			return true;
		}
	}
	return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];
    bool p[100011]; int limit = 100010; memset(p, true, sizeof(p)); p[0] = p[1] = false;
    for(int i = 2; i <= limit; ++i) {
        if(p[i]) {
            for(int j = i*2; j <= limit; j += i) p[j] = false;
        }
    }
    memset(path, 0, sizeof(path)); path[0][0] = 1;
    for(int i = 1; i < m; ++i) if(p[a[0][i]]) path[0][i] = 1; else break;
    for(int i = 1; i < n; ++i) if(p[a[i][0]]) path[i][0] = 1; else break;
    //Yahan dekh mc.
    int mod = 1e9+7;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if(p[a[i][j]]) {
                path[i][j] = ((path[i-1][j-1] + path[i][j-1])%mod + path[i-1][j])%mod;
            } else {
                path[i][j] = 0;
            }
        }
    }
    printf("%d\n", path[n-1][m-1]);
    //cout << path[n-1][m-1] << endl;
    if(path[n-1][m-1] == 0) return 0;

    vis[0][0] = true;
    memset(vis, 0, sizeof vis);
    bool ret = backtrack(0, 0);
    if(ret){
    //reverse(v.begin(), v.end());
    	for(int i = v.size()-1; i >= 0; --i) printf("%d %d\n", v[i].first ,v[i].second);
    }
    return 0;
}
