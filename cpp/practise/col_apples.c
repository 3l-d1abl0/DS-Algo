#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ml[1005];
int ap[1005];


int main(){

    int t,n,i;
    long long p;

    scanf("%d", &t);

    while(t--){

        scanf("%d %lld", &n, &p);

        for(i=0;i<n; i++)
            scanf("%d ", &ml);

        for(i=0;i<n;i++)
            scanf("%d", &ap);
    }


    return 0;
}
