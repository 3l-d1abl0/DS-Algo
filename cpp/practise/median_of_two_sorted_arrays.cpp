#include<bits/stdc++.h>

using namespace std;

double getMedian(int arr1[], int arr2[], int n1, int n2){

    int i =0, j=0;

    int m1 = -1, m2=-1;

    //m1+m2/2 ->
    if(n1+n2 & 1){ //odd length
        cout<<"ODD"<<endl;
        int limit = n1+n2/2;
        for(int idx =0; i<= limit; i++){

            if(i != n1 && j!=n2){
                m1 = (arr1[i] < arr2[j]) ? arr1[i++]: arr2[j++];
            }else if(i<n1){
                m1 = arr1[i++];
            }else{
                m1 = arr2[j++];
            }
        }// for

        return m1;
    }else{ //even length
        cout<<"EVEN"<<endl;
        int limit = n1+n2/2;
        for(int idx=0; idx<=limit; idx++){
            m2 =m1;
            if(i !=n1 && j!=n2){
                m1 = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
            }else if(i<n1){
                m1 = arr1[i++];
            }else{
                m1 = arr2[j++];
            }
        }
        cout<<m1<<" "<<m2<<endl;
        cout<<double(m1+m2)<<endl;
        double m3  =m1+m2;
        return m3;
    } //else

}

int main(){

    int ar1[] = {90, 100};
    int ar2[] = {5, 8, 10, 20};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);

    //printf("%ld", getMedian(ar1, ar2, n1, n2));
    cout<<getMedian(ar1, ar2, n1, n2);

    return 0;
}
