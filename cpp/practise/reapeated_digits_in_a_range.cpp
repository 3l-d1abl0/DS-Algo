#include<bits/stdc++.h>

using namespace std;

int table[10000];

int no_repeated(int n){

    bool a[10];
    for(int i=0; i<10; i++)
        a[i] = false;

    while(n!=0){

        int dig = n%10;

        if(a[dig]==true)
            return 0;

        a[dig] = true;

        n=n/10;
    }

    return 1;

}

void preCalc(int range){

    table[1]=1;

    for(int i=2; i<range; i++){

        table[i]= no_repeated(i)+table[i-1];
    }

}

int calrepetative(int l, int r){

    return table[r]-table[l-1];
}

int main(){

    int range = 10000;

    preCalc(range);

    int q=10;
    //while(q--){
        cout<<calrepetative(1,100)<<endl;
    //}

    return 0;
}
