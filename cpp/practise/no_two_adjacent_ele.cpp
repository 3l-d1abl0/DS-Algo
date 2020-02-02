#include<bits/stdc++.h>

using namespace std;

long long int FindMaxSum(int arr[], int N){

    long long int inc = arr[0];
    long long int exc = 0;

    for(int i=1; i<N;i++){

        long long old_inc = inc;

        inc = exc + arr[i];
        exc = max(old_inc, exc);

    }

    return ( ( inc>exc)?inc:exc );
}


int main(){

  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("%lld\n", FindMaxSum(arr, n));
  return 0;

}
