#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> v;
bool prime[100000];
void seive(int n){
    memset(prime, true, sizeof(prime));
    cout<<endl;
    for(int p=2;p*p<=n;p++){
        if(prime[p] == true){
            for(int i=p*2;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }
}
void getPath(int arr[1000][1000], int row, int col, vector<pair<int,int>> temp, int pos_x,int pos_y, int visited[1000][1000]){
    if(pos_x == row && pos_y == col){
        v.push_back(temp);
        return;
    }
    if(pos_x+1 <= row && pos_y <= col && prime[arr[pos_x+1][pos_y]] == true && visited[pos_x+1][pos_y] == 0){
        temp.push_back(make_pair(pos_x+1,pos_y));
        visited[pos_x+1][pos_y] = 1;
        getPath(arr,row,col,temp,pos_x+1,pos_y,visited);
        visited[pos_x+1][pos_y] = 0;
        temp.pop_back();
    }
    if(pos_x+1 <= row && pos_y+1 <= col && prime[arr[pos_x+1][pos_y+1]] == true && visited[pos_x+1][pos_y+1] == 0){
        temp.push_back(make_pair(pos_x+1,pos_y+1));
        visited[pos_x+1][pos_y+1] = 1;
        getPath(arr,row,col,temp,pos_x+1,pos_y+1,visited);
        visited[pos_x+1][pos_y+1] = 0;
        temp.pop_back();
    }
    if(pos_x <= row && pos_y+1 <= col && prime[arr[pos_x][pos_y+1]] == true && visited[pos_x][pos_y+1] == 0){
        temp.push_back(make_pair(pos_x,pos_y+1));
        visited[pos_x][pos_y+1] = 1;
        getPath(arr,row,col,temp,pos_x,pos_y+1,visited);
        visited[pos_x][pos_y+1] = 0;
        temp.pop_back();
    }
}
void getPathUtil(int arr[1000][1000], int row, int col){
    vector<pair<int,int>> temp;
    temp.push_back(make_pair(1,1));
    int visited[1000][1000];
    for(int i=0;i<=row;i++)
        for(int j=0;j<=col;j++)
            visited[i][j] = 0;
    getPath(arr,row,col,temp,1,1,visited);
}
int main()
{
    int row,col;
    cin>>row>>col;
    int arr[1000][1000];
    int max = INT_MIN;
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++){
            cin>>arr[i][j];
            if(arr[i][j] > max)
                max = arr[i][j];
        }
    seive(max);
    getPathUtil(arr,row,col);
    cout<<(v.size()%1000000009)<<endl;
    sort(v.begin(),v.end(),greater<vector<pair<int,int>>>());
	for(int i=0;i<v[0].size();i++){
		cout<<v[0][i].first<<" "<<v[0][i].second<<endl;
	}

    return 0;
}
