#include<bits/stdc++.h>

using namespace std;

int jose(int n, int k){

    if(n==1)
        return 1;
    else
        return (jose(n-1,k)+k-1)%n+1;
}

int main(){

  //josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
  //josephus(1, k) = 1

  //After the first person (kth from begining) is killed, n-1 persons are left.
  //So we call josephus(n – 1, k) to get the position with n-1 persons.
  //But the position returned by josephus(n – 1, k) will consider the position starting from k%n + 1.
  //So, we must make adjustments to the position returned by josephus(n – 1, k).

  int n = 14;
  int k = 2;

  cout<<"Survival Position = "<<jose(n,k);

  return 0;
}
