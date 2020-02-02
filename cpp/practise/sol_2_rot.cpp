#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#define FOR(i,n) for(int i=(0);i<(n);i++)

using namespace std;
typedef long long int ll;
#define T 1000
int N,M;
int arr[1000][1000];

bool isvalid(int i, int j) {
	if(i < 0 || j < 0 || i >= N || j >= M) return false;
	else return true;
}

struct ele {
	int x;
	int y;
};

bool isdelim(ele temp) {
	if(temp.x == -1 && temp.y == -1) return true;
	else return false;
}

bool checkall() {
	FOR(i,N) FOR(j,M) if(arr[i][j] == 1) return true;
	return false;
}

void solve() {

	queue<ele> Q;
	ele temp;
	int ans = 0;

	FOR(i,N) {
		FOR(j,M) {
			if(arr[i][j] == 2) {
				temp.x = i;
				temp.y = j;
				Q.push(temp);
			}
		}
	}

	temp.x = -1;
	temp.y = -1;
	Q.push(temp);

	while(!Q.empty()) {

		bool flag = false;

		while(!isdelim(Q.front())) {

			temp = Q.front();

			if(isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1) {
				if(!flag) ans++, flag = true;
				arr[temp.x+1][temp.y] = 2;
				temp.x++;
				Q.push(temp);
				temp.x--;
			}

			if(isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
				if(!flag) ans++, flag = true;
				arr[temp.x-1][temp.y] = 2;
				temp.x--;
				Q.push(temp);
				temp.x++;
			}

			if(isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
				if(!flag) ans++, flag = true;
				arr[temp.x][temp.y+1] = 2;
				temp.y++;
				Q.push(temp);
				temp.y--;
			}

			if(isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
				if(!flag) ans++, flag = true;
				arr[temp.x][temp.y-1] = 2;
				temp.y--;
				Q.push(temp);
			}

			Q.pop();
		}

		Q.pop();

		if(!Q.empty()) {
			temp.x = -1;
			temp.y = -1;
			Q.push(temp);
		}
	}

	if(checkall()) cout <<"-1"<<endl;
	else cout <<ans << endl;
}

int main() {

    cin>>N>>M;
    //int arr[N][M];
    //cout<<N<<"=>"<<M<<endl;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }

	solve();
	return 0;
}
