#include<bits/stdc++.h>

using namespace std;

int pathCount(int mat[][3], int x, int y, int k){

    if(x<0 || y<0)
        return 0;

    if(x==0 && y==0)
        return (k == mat[x][y]);
    else{
        return pathCount(mat, x-1, y, k-mat[x][y]) + pathCount(mat, x, y-1, k-mat[x][y]);
    }
}

int dp[3][3][100];

int dpCount(int mat[][3], int r, int c, int K){

    if(r<0 ||c<0) return 0;

    if(r==0 || c==0 ) return (K==mat[r][c]);

    if(dp[r][c][k]!=-1)
        return dp[r][c][k];

    dp[r][c][k] = dpCount(mat, r-1, c-1, K-mat[r][c]) + dpCount(mat, r-1, c-1, K_mat[r][c]);

    return dp[r][c][k];

}
int main(){

    int K = 12;
    int mat[R][C] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
                  };
    cout << pathCount(mat, 3,3,K);

    cout<<dpCount()mat,3,3,K);

    return 0;
}
