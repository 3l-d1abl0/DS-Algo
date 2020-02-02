#include<bits/stdc++.h>

using namespace std;


int floorSqrt(int x){

    if(x==0 || x==1)
        return 1;

    int num =1, sq =1;
    while(sq<=x){

        num++;
        sq = num *num;
    }

    return num -1;

}

int floorSqrt_binarySearch(int x){

    if(x ==0 || x==1)
        return x;

    int start =1 , end =x, ans;

    while(start<=end){

        int mid = start + (end-start)/2;

        if(mid*mid ==x)
            return mid;
        else if(mid*mid > x)
            end = mid-1;
        else{
            start = mid+1;
            ans = mid;
        }
    }

    return ans;
}

int main(){

     int x = 11; 
    //cout << floorSqrt(25) << endl;

    cout<<floorSqrt_binarySearch(39)<<endl;

    return 0;
}