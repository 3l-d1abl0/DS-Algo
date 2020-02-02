#include<bits/stdc++.h>


using namespace std;

void sieveOfE(int num){

    vector<bool > pri (num+1);

    for(int i=0; i<=num; i++)
        pri[i] = true;

    for(int i=2; i*i<=num; i++){

        if(pri[i]==true){

            for(int j=i*2; j<=num; j+=i)
                pri[j] = false;
        }
    }


    for(int i=2; i<=num; i++)
        if(pri[i])
            cout<<i<<" ";

}


int main(){

    int num = 1000;

    cout<<"Primes less than : "<<num<<" : "<<endl;

    sieveOfE(num);

    return 0;
}
