#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int a[100002];

int sit_next(int X, int K, int N){

    int i,flag=0;

    for( i=X; i<=N; i++){
        if(a[i]<K){
            a[i]++;
            flag=1;
            break;
        }
    }
    if(flag==0){
        for(i=0;i<X;i++){
            if(a[i]<K){
                a[i]++;
                break;
            }

        }
    }

}

int main(){

    int M, N,K;
    int i,X;
    int cnt =0;
    scanf("%d %d %d", &N, &M, &K);

    for(i=0;i<N;i++){
        scanf("%d", &X);

        if(a[X]>=K){
            cnt++;
            sit_next(X, K, N);
        }else{
            a[X]++;
        }
    }

    printf("%d", cnt);

    return 0;
}
