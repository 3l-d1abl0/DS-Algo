#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int findRange(int p1,int p2, int p3)
{
	return max(max(abs(p1-p2),abs(p2-p3)),abs(p3-p1));
}


int** findMin( int **p1,int **p2,int **p3)
{
	int **m = p1;
    if (**m > **p2) m = p2;
    if (**m > **p3) return p3;
    return m;
}



int main()
{

//	int a[]={4, 10, 15, 24, 26,-1};
//	int b[]={0, 9, 12, 20,-1};
//	int c[]={5, 18, 22, 30,-1};


//	int a[] = {4, 7, 9, 12, 15};
//    int b[] = {0, 8, 10, 14, 20};
//    int c[] = {6, 12, 16, 30, 50};

//    int a[] = {4, 7, 30};
//    int b[] = {1, 2};
//    int c[] = {20, 40};

    int a[] = {1, 1000, 2000, -1};
    int b[] = {20, 1001, 5000, -1};
    int c[] = {55, 1002, 222222, -1};

	int i=0;
	int *p1=a,*p2=b,*p3=c;
	int min=INT_MAX;
	int **t;
	while((*p1 != -1)&&(*p2!=-1)&&(*p3!=-1))
	{

		int(findRange(*p1,*p2,*p3)<min);
		min=findRange(*p1,*p2,*p3);
		t=findMin(&p1,&p2,&p3);

		(*t)++;


	}
	(*t)--;
	cout<<*p1<<"'"<<*p2<<"'"<<*p3<<"'"<<min<<endl;

	return 0;
}
