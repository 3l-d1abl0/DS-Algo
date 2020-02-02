#include<bits/stdc++.h>


using namespace std;

int g = 0;
void *myThreadFun(void *vargp)
{
    int i;
    for (i = 0; i < 10000; i++)
    g++;
    return NULL;
}

int main()
{
    int i;
    pthread_t tid;
    pthread_create(&tid, NULL, myThreadFun, NULL);
    for (i = 0; i < 10000; i++)
    g++;
    pthread_join(tid, NULL);
    printf("%d\n", g);
    return 0;
}
