#include<bits/stdc++.h>

//One element appear once rest appear N times

using namespace std;

int once(int arr[], int sz, int N){

    int countSetBit[32];
    memset(countSetBit, 0, sizeof(countSetBit));

    for(int i=0; i<=sz;i++){

        for(int k=0; k<32; k++){
                int kSetBit = 1<<k;

                if( (arr[i] & kSetBit) == kSetBit){
                        countSetBit[k]++;
                        //cout<<(arr[i] & kSetBit)<<"  ";
                }
        }
    }

    int onceNum =0;
    for(int i=0;i<32;i++){

        countSetBit[i] = countSetBit[i] % N;

        if(countSetBit[i]==1){
                onceNum = onceNum | (1<<i);
                //cout<<onceNum<<endl;
        }
    }

//    for(int i=0;i<32;i++){
//        cout<<countSetBit[i]<<"     ";
//    }
//    cout<<endl;
    return onceNum;
}


int main(){

    int N=3;
    int arr[] ={5,5,5,3,8,3,3};
    //int arr[] = { 5, 5, 4, 8, 4, 5, 8, 9, 4, 8 };
    int sz = sizeof(arr)/sizeof(arr[0]);
    cout<<once(arr, sz,N)<<endl;
    return 0;
}
