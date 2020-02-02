#include<bits/stdc++.h>

using namespace std;


void printMatrix(int arr[][5], int sz){

    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            if(arr[i][j]>=10)
                cout<<arr[i][j]<<" ";
            else
                cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotateMatrix(int arr[][5], int sz){

    for(int layer=0; layer<sz/2; layer++){

        int first = layer;
        int last = sz-1-first;
        for(int i=first; i<last; i++){

            int offset = i-first;
            swap(arr[first][i], arr[i][last]);
            swap(arr[first][i], arr[last][last-offset]);
            swap(arr[first][i], arr[last-offset][first]);

        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr [][5] = { { 0, 1, 2, 3, 4 },
                     { 5, 6, 7, 8, 9},
                     { 10, 11, 12, 13, 14},
                     { 15, 16, 17, 18, 19},
                     { 20, 21, 22, 23, 25} };

    
    int sz = sizeof(arr)/sizeof(arr[0]);

    printMatrix(arr, sz);
    rotateMatrix(arr, sz);
    printMatrix(arr, sz);



    return 0;
}