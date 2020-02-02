#include <stdio.h>

int main()
{
    int t,c=0,i,target;
    scanf("%d",&t);
    int arr[t];
    while((t--)>0)
    {
           int N,P,i,j;
           target=0;
           scanf("%d",&N);
           scanf("%d",&P);
           int milk[N],apples[N];
           for(i=0;i<N;i++)
               scanf("%d",&milk[i]);
           for(i=0;i<N;i++)
               scanf("%d",&apples[i]);
           for(i=0;i<N;i++)
           {
           if((--P)>0)
            target = target + apples[i];
           else
             P = P + milk[i];
           }
           printf("%d\n", target);

    }

    return 0;
}
