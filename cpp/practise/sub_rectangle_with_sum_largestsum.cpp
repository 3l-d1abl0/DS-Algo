#include<stdio.h>
#include<limits.h>
int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		if(size==0)
		{
			printf("\n");
			continue;
		}
		int sum1=0,sum2=0, maxsum=INT_MIN;
		int a[size][size];
		int i,j,k,l,c,b;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				scanf("%d",&a[i][j]);

		for(i=0;i<size;i++)
	  	{
		   for(j=0;j<size;j++)
		   {
			for(k=i;k<size;k++)
			{
				for(l=j;l<size;l++)
				{
					sum1=0;
					for(c=i;c<k+1;c++)
					{
						for(b=j;b<l+1;b++)
						{
							sum1+=a[c][b];
						}
					}
					if(sum1>maxsum)
					{
						maxsum=sum1;
					}
				}
			}
		   }
		}
		printf("%d\n",maxsum);
	}
	return 0;
}`
