#include<bits/stdc++.h>

using namespace std;

int ceilIdx(vector<int> v, int l, int r, int key){

    while(l<r){

        int mid = l + (r-l)/2;
        if(v[mid]>=key){
            r=mid;
        }else{
            l=mid+1;
        }
    }

    return r;
}

int lis(vector<int> v){

    if(v.size()==0)
        return 0;

    vector<int > tail(v.size(), 0);
    tail[0]= v[0];
    int len =1;

    for(int i=1; i<v.size(); i++){

        if(v[i]< tail[0]){   tail[0]= v[i];   }

        else if(v[i]> tail[len-1]){
            tail[len++] = v[i];
        }else{
            tail[ceilIdx(tail,0, len-1, v[i])] = v[i];
        }

    }

    return len;

}

int main(){
    //int vv[]= { 10, 22, 9, 33, 21, 50, 41, 60 };
    int vv[]={ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int sz = sizeof(vv)/sizeof(vv[0]);
    vector<int> v; //{ 10, 22, 9, 33, 21, 50, 41, 60 };

    for(int i=0; i<sz; i++){
        v.push_back(vv[i]);
    }


    cout<<lis(v)<<endl;


}
