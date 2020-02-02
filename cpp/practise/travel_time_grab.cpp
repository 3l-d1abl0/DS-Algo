#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
    int sz= A.size();
    int dt[A[sz-1]+1];
    for(int i=0; i<=sz; i++)
        dt[i]=0;

    int dp=2, wt=7; int wp=7; int mp=25;

    int idx =0;
    for(int i=1; i<=A[sz-1]; i++){

            if(i==A[idx]){  idx++;

                    if(i>= (wt+1) ){
                                dt[i] = min( dt[i-(wt+1)]+wp, dt[i-1]+dp );
                    }else{
                                dt[i] = min(dt[0]+wp, dt[i-1]+dp);
                    }

            }else{
                dt[i]= dt[i-1];
            }

            //cout<<dt[i]<<" ";
    }
    //cout<<endl;
    return min(dt[A[sz-1]], mp);
}

int main(){

    vector<int > v ;//={1,2,4,5,7,29,30};
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);
    v.push_back(29);
    v.push_back(30);

    cout<<solution(v)<<endl;
    return 0;
}
