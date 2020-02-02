#include<bits/stdc++.h>

using namespace std;
//Design a data structure that supports insert, delete, search and getRandom in constant time

class customDS{

    private:
        map<int, int> mp;
        vector<int > arr;

    public:
        void add(int x);
        int searchds(int x);
        int getRandom();
        void remove(int x);

        void printArray(){
            for(auto const& value: arr) {
                cout<<value<<" ";
            }
        }

        void printMap(){
            cout<<endl;
            map<int, int>::iterator it;
            for(it= mp.begin(); it!=mp.end(); it++){
                    cout<<it->first<<" "<<it->second<<endl;
            }
        }
};

void customDS::add(int x){

    if(mp.find(x)!=mp.end())
        return;

    arr.push_back(x);
    mp.insert(make_pair(x,arr.size()-1));
    //mp.insert(pair<int, int>(x,arr.size()));
}

int customDS::searchds(int x){

    if(mp.find(x)!=mp.end())
        return mp[x];
        //return mp.at(x);

    return -1;
}

void customDS::remove(int x){

    if(mp.find(x)==mp.end())
        return;

    int idx = mp.at(x);
    mp.erase(x);
    int new_idx = arr.size()-1;

    swap(arr[idx],arr[new_idx]);

    mp[arr[idx]] = idx;
    arr.pop_back();

}

int customDS::getRandom(){

    srand(time(NULL));
    int idx = rand()%arr.size();
    cout<<idx<<endl;
    return arr[idx];
}

// Driver main
int main()
{
    customDS ds;
    ds.add(10);
    ds.add(20);
    ds.add(30);
    ds.add(40);

    //ds.printArray();
    //ds.printMap();

    cout << ds.searchds(20) << endl;
    ds.remove(20);
    //ds.printArray();
    //ds.printMap();


    ds.add(50);
    cout << ds.searchds(50) << endl;
    cout << ds.getRandom() << endl;

    return 0;
}
