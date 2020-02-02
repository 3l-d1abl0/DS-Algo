#include<bits/stdc++.h>

using namespace std;

int main(){

    int N;

    cin>>N;

    int arr[2*N];

    for(int i=0; i<2*N; i++)
        cin>>arr[i];

    sort(arr, arr+2*N);

    long long int sum=0;

    for(int i=0; i<2*N;i++)
        cout<<arr[i];
    cout<<endl;

    for(int i=0; i<2*N; i+=2)
        sum+=arr[i];

    cout<<sum;

    return 0;
}
