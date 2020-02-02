#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > findSub(int arr[], int n){

    unordered_map<int, vector<int> >mp;
    vector<pair<int, int>> out;

    int sum =0;

    for(int i=0; i<n;i++){

        sum+=arr[i];

        if(sum==0){
            out.push_back(make_pair(0,i));
        }

        if(mp.find(sum)!=mp.end()){

            vector<int> vec = mp[sum];
            vector<int>::iterator it;
            for(it=vec.begin(); it!=vec.end(); it++){
                out.push_back(make_pair(*it+1, i));
            }
        }

        mp[sum].push_back(i);
        cout<<"sum ="<<sum<<endl;
    }

    return out;

}


void printArr(vector<pair<int, int>> out){

    vector<pair<int,int>>::iterator it;
    for(it=out.begin(); it!=out.end(); it++){
        cout<<"From :: "<<it->first<<" to "<<it->second<<endl;
    }

}


int main(){
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int, int> > out = findSub(arr, n);

    if (out.size() == 0)
        cout << "No subarray exists";
    else
        printArr(out);

    return 0;
}
