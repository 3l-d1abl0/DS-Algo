#include<bits/stdc++.h>

using namespace std;

int findRotations(string str){

    string tmp = str+str;
    int n = str.length();

    for(int i=1; i<=n; i++){

        string subs = tmp.substr(i, n);

        if(subs == str)
            return i;

    }

    return n;

}

int main(){

    //string str = "abc";
    string str = "abab";
    cout << findRotations(str) << endl;
    return 0;
}
