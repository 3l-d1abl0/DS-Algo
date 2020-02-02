#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int T,Q,L,R;
long long int num[100000];
int main(){
    cin>>T>>Q;
    long long int fib[100002];
    for(int i=0; i<T; i++){
        cin>>num[i];
    }

            fib[0] = 0; fib[1] = 1;

          for (int i = 2; i <= 100001; i++)
          {
              fib[i] = fib[i-1] + fib[i-2];
          }

    for(int i=0;i <Q;i++){
        cin>>L>>R;

        long long len = num[L-1];
        //cout<<". "<<len<<"  ";
        for(int i =L; i<R;i++){
                //cout<<" . "<<num[i]<<" ";
            len = __gcd(num[i], len);
        }

        //cout<<"len :: "<<len<<"   ";
        cout<<fib[len]<<endl;
    }


    return 0;
}



/////////////////////////
//Fibbonaci GCD and FIbonacci GCD AGain
//O(longN)


//https://www.snip2code.com/Snippet/876012/Find-the-best-lexicographic-path-in-a-2D





/****************************/
/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/kth-shortest-path/


*/
