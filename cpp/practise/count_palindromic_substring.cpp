// C++ program to find palindromic substrings of a string
#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000];

long int count_ways(char str[], int idx, int N, int K){

    if(K<=0)
      return -1;

    if(idx+1>=N)
      return -1;

      long int total_count =0;
      for(int start = idx+1; start<N; start++){
          //dp[idx+1][start]
          int val = count_ways(str,start, N, K--);
          if(val==-1)
            continue;

          total_count += (dp[idx][idx+1] + val)%1000000007;
      }
    return total_count;
}


// Returna total number of palindrome substring of
// length greater then equal to 2
int CountPS(char str[], int n, int K)
{
    // creat empty 2-D matrix that counts all palindrome
    // substring. dp[i][j] stores counts of palindromic
    // substrings in st[i..j]
    //int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // P[i][j] = true if substring str[i..j] is palindrome,
    // else false
    bool P[n][n];
    memset(P, false , sizeof(P));

    // palindrome of single lenght
    for (int i= 0; i< n; i++)
        P[i][i] = true;

    // palindrome of length 2
    for (int i=0; i<n-1; i++)
    {
        if (str[i] == str[i+1])
        {
            P[i][i+1] = true;
            dp[i][i+1] = 1 ;
        }
    }

    // Palindromes of length more then 2. This loop is similar
    // to Matrix Chain Multiplication. We start with a gap of
    // length 2 and fill DP table in a way that gap between
    // starting and ending indexes increases one by one by
    // outer loop.
    for (int gap=2 ; gap<n; gap++)
    {
        // Pick starting point for current gap
        for (int i=0; i<n-gap; i++)
        {
            // Set ending point
            int j = gap + i;

            // If current string is palindrome
            if (str[i] == str[j] && P[i+1][j-1] )
                P[i][j] = true;

            // Add current palindrome substring ( + 1)
            // and rest palinrome substring (dp[i][j-1] + dp[i+1][j])
            // remove common palinrome substrings (- dp[i+1][j-1])
            if (P[i][j] == true)
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1];
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
    }

    // return total palindromic substrings
    //return dp[0][n-1];

    return count_ways(str, -1, n, K);
}


// Driver program
int main()
{
    //char str[] = "abaab";
    char str[] = "aabbc";
    int n = strlen(str);

    int K=2;

    cout << CountPS(str, n, K) << endl;
    return 0;
}
