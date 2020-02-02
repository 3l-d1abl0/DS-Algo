#include<bits/stdc++.h>

using namespace std;


/*
If n is even
   f(n) = 2f(n/2) - 1
Else
   f(n) = 2f((n-1)/2) + 1

Solution of above recurrence is

f(n) = 2(n - 2^floor(Log2n) + 1
     = 2n - 2^(1 + floor(Log2n)) + 1

*/

int josephus(int n){

    int p=1;
    while(p<=n)
        p*=2;

    return (2*n - p+1);
}

int main(){

    int n=15;

    cout<<josephus(n)<<endl;

    return 0;
}
