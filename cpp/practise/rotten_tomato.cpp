#include<bits/stdc++.h>
#define FOR(i,n) for(int i=(0);i<(n);i++)
#define R 3
#define C 5
using namespace std;
typedef long long int ll;

bool isvalid(int i, int j) {
	if(i < 0 || j < 0 || i >= R || j >= C) return false;
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

bool checkall(int arr[][C]) {
	FOR(i,R) FOR(j,C) if(arr[i][j] == 1) return true;
	return false;
}

void solve(int arr[][C]) {

	queue<ele> Q;
	ele temp;
	int ans = 0;

	FOR(i,R) {
		FOR(j,C) {
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

	if(checkall(arr)) cout << "All Apples cannot rot\n";
	else cout << "Time required for all apples to rot => " << ans << endl;
}

int main() {

	int arr[][C] = { {2, 1, 0, 2, 1},
					 {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
	solve(arr);
	return 0;
}
