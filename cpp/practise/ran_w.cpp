#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        if(first.size() == second.size())
        	return first <second;
        else
        	return first.size() < second.size();
    }
};



int main(){

    int N;
    std::vector<std::string> v;
    string str;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        //scanf("%s", &str);
        cin>>str;
        v.push_back(str);
    }

    compare c;
    std::sort(v.begin(), v.end(), c);

    for(int i=0;i<N;i++){
        cout<<v[i]<<endl;
    }
    return 0;

}

