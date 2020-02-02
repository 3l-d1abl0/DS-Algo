#include<bits/stdc++.h>

using namespace std;

long long int maxPrimeFac(long long int num){

    long long int maxP =-1;

    while(num%2==0){
        maxP=2;
        num >>= 1;
    }

    //num odd at this point
    for(long long int i=3; i<=sqrt(num); i+=2){
        while(num%i==0){
            maxP=i;
            num = num/i;
        }
    }


    if(num>2)
        maxP=num;

    return maxP;
}

int main(){


    long long int num = 600851475143;
    cout<<"Largest Prime Fac :"<<maxPrimeFac(num)<<endl;

    num = 25698751364526;
    cout<<"Largest Prime Fac : "<<maxPrimeFac(num)<<endl;
    return 0;
}
