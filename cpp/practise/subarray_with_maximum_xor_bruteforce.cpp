#include<bits/stdc++.h>

using namespace std;



int main(){

    //int arr[] ={1,2,3,4,5,6,7,8,9,10};
    int arr[]={8, 1, 2, 12};
    int sz= sizeof(arr)/sizeof(arr[0]);
    int maxx =0;
    for(int i=0; i<sz; i++){
        int xx=0;
        for(int j=i; j<sz; j++){
            xx=xx^arr[j];
            maxx= max(maxx, xx);
        }

    }

    cout<<"Maxx :: "<<maxx<<endl;

    return 0;
}
