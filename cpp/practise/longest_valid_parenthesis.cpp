#include<bits/stdc++.h>

using namespace std;


int validParenthesisLength(string s, int len){

    int dp[len+1];
    memset(dp, 0, sizeof(int)*len);

    int max = 0;
    for(int i=1; i<len; i++){

        if (s[i]==')'){

            int lastIdx = i-1;
            if(s[lastIdx]=='('){
                dp[i] =(lastIdx-1>0 ? dp[lastIdx-1]: 0)+2;
            }else if( lastIdx-dp[lastIdx]>=0 && s[lastIdx-dp[lastIdx]]=='('){
                dp[i] = (2 + dp[lastIdx]) + ( (lastIdx-dp[lastIdx]-1)>0? dp[lastIdx-dp[lastIdx]-1]:0) ;
            }else
                dp[i]=0;

            max = dp[i]>max?dp[i]:max;
        }

    }

    /*for(int i=0; i<len; i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/

    return max;
}

int main(){

    //string s= "()(()))))";
    //string s= "))))))()()))(())))())((()()()())(((()))())";
    //string s= "(()())";
    //string s= "())((()()))))";
    string s= "((((()()))))()))())))))))";
    int len = s.length();

    cout<<validParenthesisLength(s, len)<<endl;

    return 0;
}