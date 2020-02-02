#include <iostream>
using namespace std;

//Given a sorted array with possible duplicate elements.
//Find Number of Occurances

int findLeft(int A[], int l, int r, int key){

    while(r-1>l){
        //cout<<"L = "<<l<<" R = "<<r<<endl;
        int mid = l + (r-l)/2;

        if(A[mid]>=key)
            r= mid;
        else
            l=mid;
    }

    return r;

}

int findRight(int A[], int l, int r, int key){

    while(r-1>l){
        //cout<<"L = "<<l<<" R = "<<r<<endl;
        int mid = l +(r-l)/2;

        if(A[mid]>=key)
            l=mid;
        else
            r=mid;
    }
    return l;
}

int countOcc(int A[], int sz, int key){

    int left_b = findLeft(A, 0, sz-1, key);

    int right_b = findRight(A, 0, sz-1, key);


    if(A[left_b]==key && A[right_b]==key)
        return right_b-left_b+1;
    else
        return -1;

}

int main() {

    int A[] = {1, 1, 2, 2, 2, 2, 3};
    int sz = sizeof(A)/sizeof(A[0]);


    cout<<countOcc(A, sz, 2)<<endl;
    return 0;
}
