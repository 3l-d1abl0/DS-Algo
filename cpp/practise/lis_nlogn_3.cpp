#include <stdio.h>
#include <stdlib.h>

void update(int *b, long n, int val)
{
	long low = 0, high = n, mid;
	while(low < high)
	{
		mid = (high - low)/2 + low ;
		if (b[mid] < val)
		{
			low = mid + 1;
		}
		else
			high = mid;
	}
	b[high] = val;
}

int main(int argc, char const *argv[])
{
	int a, *b;
	long b_n = 0;
    long n;

    scanf("%ld",&n);

    b = (int*)malloc(sizeof(int)*n);

    scanf("%d", &a);
	b[0] = a;

	for (long i = 1; i < n; ++i)
	{
        scanf("%d", &a);
		if(a > b[b_n])
			b[++b_n] = a;
		else if(a < b[b_n])
			update(b, b_n+1, a);
	}
	printf("%d\n", b_n+1);
    free(b);

	return 0;
}
