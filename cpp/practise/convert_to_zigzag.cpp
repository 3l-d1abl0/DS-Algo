#include<bits/stdc++.h>

using namespace std;


int main(){

           //int arr[] = {4, 3, 7, 8, 6, 2, 1 };
           int arr[] = {1, 4, 3, 2 };

//    bool flag = true;

//    for (int i=0; i<10; i++){
//        cout<<flag<<endl;
//        flag ^=1;
//    }

    int N= sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<N; i++)
        printf("%d ", arr[i]);
        cout<<endl;

    bool flag = true;
    for(int i=0; i<N-1;i++){
            if(flag){
                    if(arr[i]>arr[i+1]){
                        swap(arr[i], arr[i+1]);
                    }
                    flag ^=1;
            }else{
                    if(arr[i]<arr[i+1]){
                        swap(arr[i], arr[i+1]);
                    }
                    flag^=1;
            }
    }


        for (int i=0; i<N; i++)
            printf("%d ", arr[i]);
        cout<<endl;

    return 0;
}
