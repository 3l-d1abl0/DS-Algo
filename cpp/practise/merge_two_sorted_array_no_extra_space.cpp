#include<bits/stdc++.h>

using namespace std;

/*
    In order to conform with the constraint of no extra space we have to utilize th logic 
    similar to shell sort. we chose a gap between the elements to compare and gradually decrease it.
    Time Complexity : O(n^2)
*/

int nextGap(int gap){

    if(gap<=1)
        return 0;

    //return ceil(gap/2);
    return (gap/2) + (gap%2);
}

void mergeArray(int a1[], int a2[], int n, int m){

    int gap = n+m;
    int i,j;

    for(gap = nextGap(gap); gap>0; gap= nextGap(gap)){

        cout<<"Gap :: "<<gap<<endl;

        for(i=0; i+gap<n ;i++){ //when i and i+gap is in the same array
            if(a1[i]>a1[i+gap]){
                swap(a1[i], a1[i+gap]);
            }
        }

        //when a is in 1st array and b is in Second Array
        for(j= (i+gap>n)?(i+gap)-n:0 ; i<n && j<m; j++, i++){
            cout<<a1[i]<<" "<<a2[j]<<endl;
            if(a1[i]>a2[j]){
                swap(a1[i], a2[j]);
            }
        }

        //when both 1 and b are in Second Array
        if(j<m){
            for(j=0; j+gap<m ;j ++){
                if(a2[j]>a2[j+gap]){
                    swap(a2[j], a2[j+gap]);
                }
            }
        }

        for(int i=0; i<n; i++) cout<<a1[i]<<" "; cout<<" - ";
        for(int i=0; i<m; i++) cout<<a2[i]<<" "; cout<<endl;
    }
}

int main(){

    int a1[] = { 10, 27, 38, 43 ,82 }; 
	int a2[] = { 3,9 }; 

	int n = sizeof(a1) / sizeof(int); 
	int m = sizeof(a2) / sizeof(int); 

	mergeArray(a1, a2, n, m); 

	printf("\nFirst Array: "); 
	for (int i = 0; i < n; i++) 
		printf("%d ", a1[i]); 

	printf("\nSecond Array: "); 
	for (int i = 0; i < m; i++) 
		printf("%d ", a2[i]); 
	printf("\n"); 


    return 0;
}