#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
#define MAXX 10000000

using namespace std;

int tl[1002];
int pl[1002];

int main(){

    int T,N,K;
    //int a[1002][1002];

    cin>>T;
    while(T--){

        cin>>N>>K;
        char xx;

        int tptr, tsz;
        int pptr, psz;

        int cnt =0;

        for(int i=0; i<N; i++){
                tptr=0, tsz=0;
                pptr=0, psz=0;

            for(int j=0; j<N; j++){
                    cin>>xx;

                    if(xx=='P')
                        pl[pptr++]=j;
                    else
                        tl[tptr++]=j;
            }
                    //cout<<"pptr = "<<pptr<<" tptr ="<<tptr<<endl;
                    for(int p=0; p<pptr; p++){
                        int catchCount =0;
                        for(int t=0; t<tptr; t++){

                            if(abs(pl[p]-tl[t])<=K){
                                tl[t] = INT_MAX;
                                catchCount++;
                                break;
                            }
                        }

                        //cout<<"catchCount :: "<<catchCount<<" =>"<<pl[p]<<" p="<<p<<endl;
                        cnt+=catchCount;
                    }

            //for//j
        }

        cout<<cnt<<endl;
    }

    return 0;
}
