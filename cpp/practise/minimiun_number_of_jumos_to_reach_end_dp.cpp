#include<bits/stdc++.h>

using namespace std;

int minJumps(int arr[], int sz){

    if(sz ==0 || arr[0]==0)
        return INT_MAX;

    int jmp[sz];
    jmp[0]=0;

    for(int des=1; des<sz; des++){
        jmp[des]= INT_MAX;
        for(int i=0; i<des;  i++){
                if(i+arr[i] >= des && jmp[i]!=INT_MAX){
                    jmp[des] = min(jmp[des], jmp[i]+1);
                    break;
                }

        }
    }

    return jmp[sz-1];
}



int main(){

    //int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int arr[] = {1, 3, 6, 1, 0, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr, n));

    return 0;

    return 0;
}
