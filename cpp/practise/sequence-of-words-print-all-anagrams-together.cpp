#include<bits/stdc++.h>

using namespace std;

void printAnagramsTogether(char *wordArr[], int sz){

    map<string, vector<int> > mp;
    map<string, vector<int> >::iterator it;

    for(int i=0; i<sz; i++){

        string str = wordArr[i];
        sort(str.begin(), str.end());
        mp[str].push_back(i);
    }

    vector<int>::iterator v;
    for(it=mp.begin(); it!=mp.end(); it++){

            for(v= it->second.begin(); v!=it->second.end(); v++){
                cout<<wordArr[*v]<<" ";
            }
            cout<<endl;
    }

}


int main(){
    char* wordArr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
