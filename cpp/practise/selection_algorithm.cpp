#include<bits/stdc++.h>

using namespace std;

#define MAX 7

int A[MAX] = {12, 3, 5, 7, 4, 19, 26};
int N = sizeof(A)/sizeof(A[0]);

int partitions(int low,int high)
{
    int p=low,r=high,x=A[r],i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int selection_algorithm(int left,int right,int kth)
{
    for(;;)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;

        if(kth==len)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}

int main(){

    cout<<"N : "<<N<<endl;

    for(int i=0; i<N;i++){
        cout<<A[i]<<"  ";
    }
    cout<<endl<<endl;

    int K=N/2;
    selection_algorithm(1,N,K);
    cout<<"N : :"<<N<<endl;
    for(int i=0; i<N;i++){
        cout<<A[i]<<"  ";
    }

    cout<<endl<<endl;
    cout<<A[N/2]<<endl;

    return 0;
}
