#include<bits/stdc++.h>

using namespace std;



int main(){

    int N,Q;
    int T,I,B;
    vector<int>cnt(32,0);

    cin>>N>>Q;
    vector<int> vec(N,0);

    while(Q--){
        cin>>T>>I>>B;

        if(T==1){

            if(vec[I] & (1 << B))
                cnt[B]--;
            else
                cnt[B]++;
            
            vec[I] = vec[I] ^ (1 << B);

        }else{
            cout<<cnt[B]<<endl;

            for(int i=0; i<vec.size(); i++){
                cout<<vec[i]<<" , ";
            }
            cout<<endl;
            for(int i=0; i<32; i++)
                cout<<cnt[i]<<" , ";

            cout<<endl;
        }
    }


    return 0;
}