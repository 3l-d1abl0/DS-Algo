#include<bits/stdc++.h>
#define R 4
#define C 4

using namespace std;

void printMatrix(int arr[R][C])
{
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
            cout << arr[i][j] << " ";
        cout<<'\n';
    }
}



void transpose(int arr[R][C]){

    for(int i=0;i <R; i++){
        for(int j=i; j<C; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void revCol(int arr[R][C]){
    for(int i=0;i<C; i++ ){
        for(int j=0, k=R-1; j<k; j++, k-- ){
            swap(arr[j][i], arr[k][i]);
        }
    }
}

void revRow(int arr[R][C]){

    for(int i=0; i<R;i++){
        for(int j=0, k=C-1; j<k; j++, k--){
                swap(arr[i][j], arr[i][k]);
        }
    }
}

void rotate90(int arr[R][C] ){
    transpose(arr);
    //revCol(arr);
    revRow(arr);
}

int main()
{
    int arr[R][C]= { {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotate90(arr);
    printMatrix(arr);
    return 0;
}
