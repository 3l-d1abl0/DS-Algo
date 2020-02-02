#include<bits/stdc++.h>


using namespace std;

void bubble_sort(int *arr, int N){

    for(int i=0; i< N; i++){

            for(int j =0; j<N-1-i; j++){

                    if(arr[j] > arr[j+1]){
                        swap(arr[j], arr[j+1]);
                    }
            }
    }

}

int main(){

    int arr [] = {12, 54, 23, 5, 67, 22, 53 ,23, 78,90};

    int N= sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<N; i++)
        printf("%d ", arr[i]);
        cout<<endl;

    bubble_sort(arr, N);


    for (int i=0; i<N; i++)
        printf("%d ", arr[i]);
        cout<<endl;



    return 0;

}
