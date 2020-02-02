#include<bits/stdc++.h>

using namespace std;

struct Node{

    int prob;
    int att;
};

int main(){

    int T,N,k, a,b;
    cin>>T;

    while(T--){

        vector< pair<int, int> > pq;
        vector< pair<int, int> >::iterator it;

        cin>>N>>k;
        cout<<"========="<<endl;

        for(int i=0; i<N; i++){
            cin>>a>>b;
            pq.push_back( make_pair(a, b) );
        }
        sort(pq.begin(), pq.end());

        cout<<"+_+_+_+_"<<endl;

        /*for(it=pq.begin(); it!=pq.end(); it++){
            cout<<it->first<<" "<<it->second<<endl;
        }*/

        int max_att = -1;
        for(int i=0; i<N; i++){
            int att_sum =pq[i].second;
            for(int j=i+1; pq[i].first+k>pq[j].first && j<N ;  j++){
                att_sum += pq[j].second;
                //cout<<att_sum<<" "<<pq[i].first<<" "<<pq[j].first<<" "<<k<<endl;
            }

            max_att = max_att>att_sum ? max_att:att_sum;
        }

        cout<<"Attach Fact : "<<max_att<<endl;

    }

    return 0;
}
