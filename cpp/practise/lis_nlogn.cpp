#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>

using namespace std;

int get_ceil(vector <int > v, int l, int r, int key){

        while(l<r){

            int mid = l+ (r-l)/2;

            if(v[mid]>= key){
                r=mid;
            }else{
                l = mid+1;
            }
        }

        return r;
}


int lis_modified(vector <int> &v){

        int sz = v.size();

        if(sz==0)
            return 0;

        vector <int> lis(v.size() ,0);

        lis[0] = v[0];
        int len=1;

        for(int i=1; i< v.size(); i++){

                if(v[i]< lis[0]){
                        lis[0] = v[i];
                }else if(v[i] > lis[len-1]){
                    lis[len] = v[i];
                    len++;  cout<<"Len ::"<<len<<endl;
                }else{
                    //cout<<"LL ::::"<<endl;
                    int ll=  get_ceil(v, 0, len-1,v[i] );
                    cout<<"LL ::"<<ll<<endl;
                    lis[ll] = v[i];
                }
        }

       for(int i=0;i < len; i++)
            cout<<lis[i]<<" ";

        cout<<endl<<"Len : "<<len<<endl;

        return len;
}

int main(){

    //vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    //{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}
    //int vv[]= { 10, 22, 9, 33, 21, 50, 41, 60 };
    int vv[]={ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int sz = sizeof(vv)/sizeof(vv[0]);
    vector<int> v; //{ 10, 22, 9, 33, 21, 50, 41, 60 };

    for(int i=0; i<sz; i++){
        v.push_back(vv[i]);
    }









    /*
        v.push_back(0);
    v.push_back(8);
    v.push_back(4);
    v.push_back(12);
    v.push_back(2);
    v.push_back(10);
    v.push_back(6);
    v.push_back(14);
    v.push_back(1);
    v.push_back(9);
    v.push_back(5);
    v.push_back(13);
    v.push_back(3);
    v.push_back(11);
    v.push_back(7);
    v.push_back(15);

    */

   // cout<<"Calling... "<<endl;
    int len_lis = lis_modified(v);

    cout<<"LIS ::"<<len_lis;

    return 0;
}
