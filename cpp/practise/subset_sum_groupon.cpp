#include<bits/stdc++.h>

using namespace std;

int cnt=0;
int N;

void noSubset(int i, int sum, int arr[],int K){

    if(i==N)
        return ;
    if(arr[i]+sum>=K ){
        //cout<<arr[i]+sum<<endl;
        cnt++;
    }

    noSubset(i+1, sum+arr[i], arr, K);
    noSubset(i+1, sum,arr, K);

};

int main(){

    int K;
    cin>>N;
    int arr[N];
    for(int i =0; i<N;i++){
        cin>>arr[i];
    }
    cin>>K;


    noSubset(0, 0, arr,K);
    cout<<cnt;

    return 0;
}


/*
5
1 5 9 2 3
16
*/

/*
5
2 4
2 3
3 1
3 5
3
2 3
4 2
1 5
*/
