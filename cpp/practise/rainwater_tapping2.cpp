#include<bits/stdc++.h>

using namespace std;

int findWater(int arr[], int n){

    int lf =0, rt=n-1;
    int left_max = -1; int rt_max = -1;
    int water =0;
    while(lf<=rt){

        if(arr[lf]<arr[rt]){
                if(arr[lf]>left_max)
                    left_max = arr[lf];
                else
                    water += left_max -arr[lf];
                    lf++;
        }else{

            if(arr[rt]>rt_max)
                rt_max = arr[rt];
            else
                water += rt_max - arr[rt];
                rt--;
        }

    }

    return water;

}

int main()
{
    //int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int arr[] = {7,1,4,0,2,8,6,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
        << findWater(arr, n);
}
