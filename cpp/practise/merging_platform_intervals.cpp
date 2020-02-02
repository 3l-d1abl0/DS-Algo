#include<bits/stdc++.h>


using namespace std;

int findPlatform(int arr[], int dep[], int n){

    sort(arr, arr+n);   sort(arr, dep+n);

    int plat_needed=1, res =1;
    int ar=1, dp=0;
    while(ar<n && dp<n){

            if(arr[ar] < dep[dp]){
                    plat_needed++;  cout<<plat_needed<<" ";
                    res = plat_needed>res ? plat_needed : res;
                    ar++;
            }else{
                dp++;
                plat_needed--;
            }
    }

    cout<<endl;
    return res;
}

int main(){

    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "<< findPlatform(arr, dep, n);
    return 0;

    return 0;
}
