#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define MAXX 100000

using namespace std;

int A[MAXX];
int sum[MAXX];

int main(){

    int T,N,P,ans;
    scanf("%d", &T);

    for(int cs= 1;cs<=T;cs++){
       scanf("%d %d", &N, &P);

       //scanf("%d", &A[0]);
       //sum[0]= A[0];
       for(int i=1; i<=N; i++){
            scanf("%d", &A[i]);
            sum[i]= A[i]+sum[i-1];
       }

       ans =0;
       int i =1;

       for(int j =1; j<=N;j++){

            while(i<=j && sum[j]-sum[i-1] > P){
                i++;
            }
            printf("j= %d  i=%d  Ans=%d \n",j, i, (j-i+1));
            ans+=j-i+1;
       }

       printf("Case #%d: %d \n",cs,ans );
    }

    return 0;
}
