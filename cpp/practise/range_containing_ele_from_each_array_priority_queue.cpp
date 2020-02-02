#include<bits/stdc++.h>

using namespace std;

pair<int, int> find_min_range(vector<vector<int> > &arr){

    pair<int, int> mRange= make_pair( INT_MIN, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;

    //For Counting Index
    vector< int> idx(arr.size());

    //Inserting first Elements into heap;

    int maxEle = INT_MIN;
    for(int i=0; i <arr.size(); i++){
            minHeap.push({arr[i][0], i});
            if(maxEle < arr[i][0]){ maxEle = arr[i][0]; }
    }

    while(true){
        long long int curr_range = maxEle - minHeap.top().first;
        long long int def_range  = double(mRange.second) - double(mRange.first);
        //cout<<long(maxEle) - long(minHeap.top().first)<<" <==>  "<<long( long(mRange.second) - long(mRange.first))<<endl;
        cout<<"Curr :: "<<curr_range<<"  Def ::"<<def_range<<endl;
        if( curr_range < def_range ){
            mRange = make_pair( minHeap.top().first, maxEle);
        }
        //cout<<"++++"<<endl;
        pair<int, int> oldEle = minHeap.top();
        cout<<"Removed Ele :: "<<oldEle.first<<endl;
        minHeap.pop();

        //cout<<"mnmnmnmn"<<endl;
        //cout<<idx[oldEle.second]<<endl;
        idx[oldEle.second]++;
        //cout<<"klklkllklklk"<<endl;
        if( idx[oldEle.second] == arr[oldEle.second].size()){
            return mRange;
        }
        //cout<<"tyftdtfgyfgtf"<<endl;
        minHeap.push({arr[oldEle.second][idx[oldEle.second]], oldEle.second});
        //cout<<"====================================="<<endl;
        if(maxEle < arr[oldEle.second][idx[oldEle.second]] ) {    maxEle = arr[oldEle.second][idx[oldEle.second]] ;   }
        //cout<<"nnnnnnnnnnnnnnnnnnnnn"<<endl;
    }

        return mRange;
}


int main(){

//vector<vector<int> > arr {   {4, 7, 9, 12, 15},
//                                                {0, 8, 10, 14, 20},
//                                                {6, 12, 16, 30, 50}     };

    vector<vector<int> > arr(3, vector<int>(5,0));
    arr[0][0]= 4; arr[0][1]=7; arr[0][2]=9; arr[0][3]=12; arr[0][4]=15;

    arr[1][0]= 0; arr[1][1]=8; arr[1][2]=10; arr[1][3]=14; arr[1][4]=20;

    arr[2][0]= 6; arr[2][1]=12; arr[2][2]=16; arr[2][3]=30; arr[2][4]=50;

    pair <int, int> range = find_min_range(arr);
    printf("Minimum Range :: [%d  ,   %d ]\n", range.first, range.second);


    return 0;

}



/*
arr1[] : [4, 7, 30]
arr2[] : [1, 2]
arr3[] : [20, 40]

[1 1000 2000]
[20 1001 5000]
[55 1002 222222]]


List 1: [4, 10, 15, 24, 26]
List 2: [0, 9, 12, 20]
List 3: [5, 18, 22, 30]



*/
