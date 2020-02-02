#include<bits/stdc++.h>

using namespace std;

bool testing(string str, string patt){

    int n = str.length();
    int m = patt.length();

    bool dp[n+1][m+1];

    memset(dp, false, sizeof(dp));

    //No string No pattern
    dp[0][0]=true;

    //when string is null and pattern is *
    for (int j =1 ; j<=m; j++)
        if(patt[j-1] == '*')
            dp[0][j] = dp[0][j-1];


    for(int i=1; i<=n; i++){

        for(int j=1; j<=m; j++){

            if(patt[j-1] =='?' || patt[j-1]==str[i-1])
                dp[i][j] = dp[i-1][j-1];

            else if (patt[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];

        }
    }

    return dp[n][m];

}

void test(string str, string patt){

    if (testing(str, patt))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}

int main(){

    test("baaabab", "*****ba*****ab");
    test("baaabab", "ba*****ab");
    test("baaabab", "ba*ab");
    test("baaabab", "a*ab");
    test("baaabab", "a*****ab");
    test("baaabab", "*a*****ab");
    test("baaabab", "ba*ab****");
    test("baaabab", "****");
    test("baaabab", "aa?ab");
    test("baaabab", "baaabab");
    return 0;
}
