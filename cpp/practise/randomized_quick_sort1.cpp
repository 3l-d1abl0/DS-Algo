#include<bits/stdc++.h>

using namespace std;

void print_a(int A[], int sz){

    for(int i=0; i<sz; i++)
        cout<<A[i]<<" ";

    cout<<endl;
}

int part(int arr[], int left, int right){

    int n= right-left+1;
    int piv = rand() % n;

    swap(arr[left + piv], arr[left]);

    int pivot = left;
    int pval = arr[pivot];

    int l= left; int r = right;

    while(l<r){

        while(arr[l]<=pval && l<=right)
            l++;

        while(arr[r]>pval && r>=left)
            r--;

        if(l<r)
            swap(arr[l], arr[r]);

    }

    swap(arr[pivot], arr[r]);

    return r;
}

int kthSmallest(int arr[], int left, int right, int k){

    if(k-1>=left && k-1<= right){
        int pos = part(arr, left, right);
       // cout<<"POS :: "<<pos<<"  "<<arr[pos]<<" K-1= "<<k-1<<endl;
        if(pos == k-1){
            return arr[pos];
        }else if(pos> k-1){
            return kthSmallest(arr, left,pos-1,k);
        }else{
            return kthSmallest(arr, pos+1, right, k);
        }
    }

    return INT_MAX;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};   // 3 4 5 7 12 19 26
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;//(index 1);
    for(int i=1; i<=n; i++){
        int arr[] = {12, 3, 5, 7, 4, 19, 26};
        //int n = sizeof(arr)/sizeof(arr[0]);
        cout <<i<<" smallest element is " << kthSmallest(arr, 0, n-1, i)<<endl;
    }
    return 0;
}
