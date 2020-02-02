#include<bits/stdc++.h>

using namespace std;

int findWater(int arr[], int sz){

    int lf[sz], rt[sz];

    int cal_water =0;

    lf[0] = arr[0];
    for(int i=0; i<sz; i++)
        lf[i]=max(lf[i-1], arr[i]);

    rt[sz-1] = arr[sz-1];
    for(int i=sz-2; i>=0; i--)
        rt[i]=max(rt[i+1], arr[i]);

    for(int i=0; i<sz;i++){
        cal_water += min(rt[i],lf[i])-arr[i];
        //cout<<cal_water<<endl;
    }

    return cal_water;

}

int main(){

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int sz = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max Water Accumulated : "<<findWater(arr, sz)<<endl;
    return 0;
}
