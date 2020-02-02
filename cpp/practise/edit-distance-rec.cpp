#include<bits/stdc++.h>

using namespace std;

int customMin(int a, int b, int c){

    return min(min(a,b),c);
}

int editDist(string str1, string str2, int len1, int len2){

    if(len1==0)
        return len2;

    if(len2==0)
        return len1;

    if(str1[len1-1] == str2[len2-1])
        return editDist(str1, str2, len1-1, len2-1);

    return 1 + customMin( editDist(str1, str2, len1, len2-1), editDist(str1, str2, len1-1, len2), editDist(str1, str2, len1-1, len2-1) );

}

int editDistDP(string str1, string str2, int len1, int len2){

    int dp[len1+1][len2+1];

    dp[0][0] = 0;

    for(int i=0; i<=len1; i++){

        for(int j=0; j<=len2; j++){

            if(i==0)
                dp[i][j] = j;

            else if(j==0)
                dp[i][j] = i;

            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else{
                dp[i][j] = 1+customMin(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[len1][len2];
}

int main(){

    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist( str1 , str2 , str1.length(), str2.length())<<endl;
    cout << editDistDP( str1 , str2 , str1.length(), str2.length())<<endl;

    return 0;

}
