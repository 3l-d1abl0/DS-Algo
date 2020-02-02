#include<bits/stdc++.h>

using namespace std;

int printknapSack(int W, int wt[], int val[], int sz){

    int table[sz+1][W+1];

    for(int i=0; i<=sz; i++){

        for(int j=0; j<=W; j++){

            if(i==0 || j==0)
                table[i][j] = 0;

            else if (wt[i-1]<W){ //include
                table[i][j] = max( val[i-1]+table[i-1][j-wt[i-1]], table[i-1][j]);
            }else{ //exclude
                table[i][j] = table[i-1][j];
            }

        }
    }

    return table[sz][W];

}

int main(){

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;

    //int val[] = {40, 100, 50, 60};
    //int wt[] = {20, 10, 40, 30};
    //int W = 60;

    //int val[] = { 60, 100, 120 };
    //int wt[] = { 10, 20, 30 };
    //int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout<<printknapSack(W, wt, val, n)<<endl;

    return 0;
}
