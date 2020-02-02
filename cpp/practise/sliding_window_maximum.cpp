#include<bits/stdc++.h>

using namespace std;

void sliding_window_k(int arr[], int n, int k){

    deque<int >dq(k);
    int i;
    for(i=0;i<k;i++){

        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }


    for(;i<n;i++){

        cout<<arr[dq.front()]<<" ";

        //removing the out of range indices
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();


        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    cout<<arr[dq.front()]<<endl;
}

int main(){

    //int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int arr[] = {9,6,11,8,10,5,4,13,93,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    sliding_window_k(arr, n, k);

    return 0;
}
