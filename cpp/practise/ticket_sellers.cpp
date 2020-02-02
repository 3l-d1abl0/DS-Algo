#include<bits/stdc++.h>

using namespace std;

int getRev(int arr[], int N, int K, int maxx){

    int win[maxx+1];
    memset(win, 0, sizeof(win));

    for(int i=0; i<N;i++){
        win[arr[i]]++;
    }

    long long int tkt = maxx;
    int revenue =0;
    while(K--){
        //cout<<"k: "<<K<<endl;
        if(win[tkt]>0){
            revenue  = (revenue+tkt);//%(pow(10,9)+7);
            //cout<<"tkt : "<<tkt<<endl;
            win[tkt]--;
            if(tkt-1>=0){
                win[tkt-1]++;
            }

            //K--;
        }else{
            tkt--;
            K++;
        }
    }

    return revenue;

}

int main(){

    int T;
    int N, K;
    int arr[1000000];
    cin>>T;
    while(T--){
        cin>>N>>K;
        int maxx =-1;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            maxx = (maxx>arr[i])?maxx:arr[i];
        }

        cout<<getRev(arr,N,K, maxx)<<endl;
    }

    return 0;
}
