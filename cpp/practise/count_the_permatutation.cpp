#include<bits/stdc++.h>

using namespace std;

int P(int k, int n){

    if(k>n) return 0;

    if(k==n) return 1;
    cout<<k<<" "<<n<<endl;
    return P(k+1, n)+P(k, n-k);

}

int main(){

    int T, SUM,NUM;

    cin>>T;
    while(T--){
        cin>>SUM>>NUM;

        cout<<P(NUM, SUM)<<endl;

    }

    return 0;
}



//https://stackoverflow.com/questions/8193438/find-the-no-of-ways-of-getting-a-sum-n-with-all-positive-integers-less-than-n
//http://vwww.academickids.com/encyclopedia/index.php/Partition_function_%28number_theory%29
