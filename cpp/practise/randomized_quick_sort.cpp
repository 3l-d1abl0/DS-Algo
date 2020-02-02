#include<bits/stdc++.h>

using namespace std;

void print_a(int A[], int sz){

    for(int i=0; i<sz; i++)
        cout<<A[i]<<" ";

    cout<<endl;
}

int partition(int A[], int start, int end){

  srand(time(NULL));
  int pIdx = start + rand() % (end-start+1);

  int pvt = A[pIdx];
  cout<<"Pivot = "<<pvt<<endl;
  swap(A[pIdx], A[start]);

  pIdx = start;
  int left = start; int right = end;

  while (left<right) {

    while (A[left]<=pvt && left<=end) {
      left++;
    }

    while (A[right]>pvt && right>=start) {
      right--;
    }

    if(left<right){
      swap(A[left], A[right]);
    }

  } //while

  A[pIdx] = A[right];
  A[right] = pvt;

  return right;

}

void random_quick_sort(int A[], int l, int r){
    if(l<r){
      int part = partition(A, l, r);
      random_quick_sort(A,l,part-1);
      random_quick_sort(A, part+1, r);
    }
}

int main(){

    int A[] = {2,5,7,1,10,8,9};

    int sz = sizeof(A)/sizeof(A[0]);
    cout<<"Size : "<<sz<<endl;
    print_a(A, sz);
    random_quick_sort(A,0,sz-1);
    print_a(A,sz);
    return 0;
}
