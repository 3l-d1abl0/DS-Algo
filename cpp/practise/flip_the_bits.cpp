#include<bits/stdc++.h>
using namespace std;

// Flip the zeros to get the max 1's in an array
int findMaxZeroCount(bool arr[], int n){

    int one_count =0;
    int curr_max=0, maxx=0;
    for(int i=0; i<n; i++){

        one_count = (arr[i]==1)?one_count+1 : one_count;

        int val = (arr[i]==0)? 1: -1;

        curr_max = max(val, curr_max+val);
        maxx  = max(maxx, curr_max);

    }

    maxx = max(maxx,0);
    cout<<maxx<<" "<<one_count<<endl;
    return one_count+maxx;
}

int main(){

    bool arr[] = {1,0,0, 1, 0, 0, 1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << findMaxZeroCount(arr, n);
	return 0;
}
