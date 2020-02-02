#include<iostream>
#include<cstdio>

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

        int catchCount =0;

        for(int i=0; i<N; i++){
                tptr=0, tsz=0;
                pptr=0, psz=0;
            for(int j=1; j<=N; j++){
                    cin>>xx;

                    if(xx=='P'){
                        pl[++psz]=j;
                        if(tsz!=0 && tptr<=tsz){

                            while(pl[pptr]-tl[tptr] > K || tptr<=tsz){
                                tptr++;
                            }

                            if(tptr<=tsz){
                                catchCount++;
                                tptr++; pptr++;
                            }else{
                                pptr++;
                            }
                        }

                    }else{
                        tl[++tsz]=j;
                        if(psz!=0 && tptr<=tsz){

                            while(pl[pptr]-tl[tptr] > K || tptr<=tsz){
                                tptr++;
                            }

                            if(tptr<=tsz){
                                catchCount++;
                                tptr++; pptr++;
                            }else{
                                pptr++;
                            }
                        }

                    }
            }//for//j
        }

        cout<<catchCount<<endl;
    }

    return 0;
}
