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
            if ( tm[j]+ tm[i]<=drp[i].d && lis[i] < lis[j] + drp[i].r){ // tm[j]+drp[i].p
                lis[i] = lis[j] + drp[i].r;
                tm[i] = tm[j]+ drp[j].p;
            }
    }

    for(int i=0; i<n ;i++){
        cout<<lis[i]<<" ";
    }
    cout<<endl;
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


/*
1
6
1 2 1
2 3 1
4 1 2
10 10 10
15 13 10
5 7 5


D R P

d: 4 5 5 6 7 17 19
t: 2 3 2 1 3 5 2
p: 2 10 2 5 4 9 4

4 2 2
5 10 3
5 2 2
6 5 1
7 4 3
17 9 5
19 4 2


2 12 4 7 6 21 25
25
*/

//https://ideone.com/vUVaEC

//20
//https://ideone.com/AUVl0O
//30
