#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

#define lli long long int
#define pli pair<lli , int>

lli w[100000];
vector<lli> ans;
//lli ans[1000000];

lli solve(int L, int N, lli M, lli D){

        priority_queue< pli, vector<pli>, greater<pli> > pq;

        for(int i=0; i<N; i++){
            scanf("%I64d", &w[i]);
            pq.push(make_pair(w[i],i));
        }

        pli cur_lau;
        int lau_idx = -1;

        //fill(ans.begin(), ans.end(), 0);
        lli minn = L>M ? L:M;
        //for(lli ii=0; ii<minn; ii++)
            //ans.push_back(0);
        vector<lli> ans(minn);

        //cout<<ans[0]<<endl;
        //fill(ans, ans + M, 0);
        //memset(ans, 0, sizeof(ans));
        //cout<<"----------"<<endl;
        for(int i=0;i<L; i++){

                cur_lau = pq.top();
                pq.pop();
                //cout<<"----------"<<endl;
                lau_idx ++;
                if(lau_idx >=M){    lau_idx-= M; }
                //cout<<"----------"<<endl;
                pq.push(make_pair(cur_lau.first+ w[cur_lau.second],  cur_lau.second) );
                //cout<<"----------!!"<<endl;
                //int maxx = max(ans[lau_idx], cur_lau.first);
                //cout<<ans[lau_idx]<<"  "<<cur_lau.first<<endl;
                lli maxx = ans[lau_idx]>cur_lau.first?ans[lau_idx]:cur_lau.first;
                //cout<<"----------!!!"<<endl;
                ans[lau_idx] = maxx + D;
               //cout<<"ans["<<lau_idx<<"] = "<<maxx<<" + "<<D<<" = "<<ans[lau_idx]<<endl;
        }

        return ans[lau_idx];
}

int main(){

    int T;
    int L, N;
    lli M, D;

    scanf("%d",&T);

    for(int ii=1; ii<=T; ii++){

        scanf("%d %d %I64d %I64d", &L,  &N, &M, &D);

        printf("Case #%d: %I64d\n", (ii), solve(L, N, M, D));


    }


    return 0;
}
