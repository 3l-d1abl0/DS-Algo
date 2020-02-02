#include<bits/stdc++.h>


using namespace std;

void genPar(int left, int right, string par){

    if(left==0 && right ==0)
        cout<<par<<endl;

    if(left>right)
        return ;

    if(left>0)
        genPar(left-1, right, par+"(");

    if(right>0)
        genPar(left, right-1, par+")");
}

int main(){

    int N=8;

    if(N&1) {
        cout<<"cant form parenthesis with N="<<N<<endl;
    }

    genPar(N/2, N/2, "");

    return 0;
}
