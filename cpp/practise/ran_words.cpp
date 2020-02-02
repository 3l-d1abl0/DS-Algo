
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 105
#define MAXLEN 12

char arr[ROWS][MAXLEN] ;

int compare (const void * a, const void * b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);

    if(fa == fb)
        return ((const char *)a) > ((const char *)b);
    else
        return (fa > fb) - (fa < fb);
}

int main(int argc, const char * argv[]) {

    int n,i;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%s", &arr[i]);
    }

    qsort(arr, n, MAXLEN, compare);

    for(i=0;i<n; i++){
        printf("%s\n", arr[i]);
    }
    return 0;
}
