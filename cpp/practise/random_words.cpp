#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define MAXLEN 20

int compare (const void * a, const void * b) {
    size_t fa = strlen((const char *)a);
    size_t fb = strlen((const char *)b);

    if(fa == fb)
        return ((const char *)a) > ((const char *)b);
    else
        return (fa > fb) - (fa < fb);
}

int main(int argc, const char * argv[]) {
    /*char arr[ROWS][MAXLEN] = {
        "watfi",
        "wh",
        "barified",
        "foo"
    };*/

    char arr[ROWS][MAXLEN] = {
        "omar",
        "apple",
        "banana",
        "cat",
        "ant"
    };
    qsort(arr, ROWS, MAXLEN, compare);
    int i;
    for(i=0;i<ROWS; i++){
        printf("%s\n", arr[i]);
    }
    return 0;
}
