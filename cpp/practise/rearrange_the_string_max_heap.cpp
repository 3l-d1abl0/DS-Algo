#include<bits/stdc++.h>

using namespace std;

struct Node{
    char ch; int freq;
};

void maxHeapify(Node *dp, int start, int sz){

    int root = start;

    while(2*root+1 < sz){
        int child1= 2*root;

        if(child1+1 < sz && dp[child1].freq<dp[child1+1].freq) child1++;

        if(dp[root] < dp[child1]){
            swap( dp[root].ch , dp[child1].ch);
            swap(dp[root].freq, dp[child1].freq);
            root = child1;
        }

    }
}

void rearrangeString(string str){

    //Store Frequency //a-z
    int len = str.length();
    int freq[26];
    memset(freq,0,sizeof(freq));

    for(int i=0; i<len;i++)
        freq[str[i]-'a'] = freq[str[i]-'a']? freq[str[i]-'a']++ : freq[str[i]-'a'];

    Node hp[26];
    int i=0;
    for(char c='a'; c<='z'; c++){
            if(freq[c-'a']){
                hp[i].ch = c;
                hp[i].freq = freq[c-'a'];   i++
            }
    }

    maxHeapify(&dp, 0, i);

}


int main(){

    string str = "bbbaa" ;
    rearrangeString(str);
    return 0;
}
