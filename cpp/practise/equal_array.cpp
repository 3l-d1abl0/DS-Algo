#include<bits/stdc++.h>

using namespace std;

int arr[100002];

int main(){

    int T,N,num;
    cin>>T;

    while(T--){

        cin>>N;
        long long int fSum =0;
        for(int i=0; i<N; i++){
            cin>>num;
            arr[i]= num;
            fSum += num;
        }

        long long int curr = 0;
        long long int min_num = INT_MAX;
        for(int i=0; i<N; i++){
            curr+= arr[i];

            min_num = min( abs(fSum - 2*curr), min_num);
        }

        cout<<min_num<<endl;


    }

    return 0;
}
