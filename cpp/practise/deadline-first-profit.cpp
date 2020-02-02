#include<bits/stdc++.h>

using namespace std;


struct node{
    int d;
    int r;
    int p;
};

bool customFun(node a,node b){
    return a.d<b.d;
}


int getProfit(int n, node drp[]){

    int lis[n];
    int tm[n];

    lis[0] = drp[0].r;
    tm[0] = drp[0].p;

    for (int i = 1; i < n; i++ )
    {
        lis[i] = drp[i].r;
        tm[i] = drp[i].p;

        for (int j = 0; j < i; j++)
            if ( tm[j]+ tm[i]<=drp[i].d && lis[i] < lis[j] + drp[i].r){
                lis[i] = lis[j] + drp[i].r;
                tm[i] = tm[j]+ drp[j].p;
            }
    }

    return *max_element(lis, lis+n);
}

int main(){

    int T, N;

    cin>>T;

    node drp[1002];

    while(T--){

        cin>>N;

        for(int i=0; i<N;i++){
            cin>>drp[i].d>>drp[i].r>>drp[i].p;
        }


        sort(drp, drp+N, customFun);

        int maxPro = getProfit(N, drp);

        cout<<maxPro<<endl;


    }

    return 0;
}
