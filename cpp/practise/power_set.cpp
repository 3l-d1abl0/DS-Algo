#include<bits/stdc++.h>

using namespace std;

int power_set(int arr[], int sz){

    int no_of_set = 1<<sz;

    for(int i=0; i<no_of_set; i++){
            cout<<"Set "<<i<<" :: ";
            int sum =0;
            for(int j=0; j<sz; j++){

                    if(i & (1<<j) ){
                        cout<<arr[j]<<" ";
                        sum+=arr[j];
                    }
            }
            cout<<"  Sum :: "<<sum<<endl;
    }

}

int main(){

    int arr[] ={1,2,3,4,5};
    int sz = sizeof(arr)/sizeof(arr[0]);

    power_set(arr, sz);
    return 0;
}
