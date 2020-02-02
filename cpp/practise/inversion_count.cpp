#include<bits/stdc++.h>
#define long long long

using namespace std;

int arr[200002];

long merge(int l, int m, int r){

    int n1 = m-l+1; int n2 = r-m;
    int a1[n1]; int a2[n2];

    for(int i=0; i<n1; i++)
        a1[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        a2[i] = arr[m+1+i];

    int k=l, i=0, j=0;

    long inv_cnt =0;

    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            arr[k] = a1[i]; i++;
        }else{

            //cout<<"a :: "<<a1[i]<<" > "<<a2[j]<<endl;
            //cout<<"m :: "<<m<<" i :: "<<i<<endl;
            arr[k] = a2[j]; j++;
            inv_cnt += (m-(i+l)+1);
        }
        k++;
    }

    while(i<n1){
        arr[k] = a1[i];
        k++; i++;
    }
    while(j<n2){
        arr[k] = a2[j];
        k++; j++;
    }

    return inv_cnt;
}

long merge_sort(int l, int r){
    long cnt=0;
    if(l<r){
        int mid = l + (r-l)/2;

        cnt += merge_sort(l,mid);
        cnt += merge_sort(mid+1,r);

        cnt += merge(l,mid,r);
    }

    return cnt;
}

int main(){

    int T,N;
    cin>>T;
    while(T--){

        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr[i];

        cout<<merge_sort(0,N-1)<<endl;
    }

    return 0;
}
