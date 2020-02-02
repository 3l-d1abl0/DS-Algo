#include<bits/stdc++.h>

using namespace std;

int minJumps(int arr[], int start, int end){

    if(start == end)
        return 0;

    if(arr[start] == 0)
        return INT_MAX;

    int minn = INT_MAX;
    for(int i=start+1; i<=end && i<= (start+arr[start]) ; i++){

        int jmp = minJumps(arr, i, end);
        if(jmp != INT_MAX && jmp+1 < minn )
            minn= jmp+1;

    }

    return minn;

}



int main(){

    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr, 0, n-1));

    return 0;
}
