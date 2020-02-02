#include<bits/stdc++.h>

using namespace std;

class LRU{

    int  cache_size;
    list<int> dq;
    unordered_map<int, list<int>::iterator>ma;

public:

    LRU(int);
    void accessPage(int);
    void displayState();
};

LRU::LRU(int n){
    cache_size = n;
}

void LRU::accessPage(int page){

        if(ma.find(page)==ma.end()){ //Not Present
            cout<<"PAGE MISS"<<endl;
            //Check if Page Table is Full
            if(dq.size()==cache_size){
                cout<<"CACHE FULL"<<endl;
            //evict the last cache page
                int last_page = dq.back();
                dq.pop_back();
                ma.erase(last_page);

                dq.push_front(page);
                ma[page] = dq.begin();

            }else{
                //insert at the top
                dq.push_front(page);
                ma[page]= dq.begin();
            }
        }else{ //PRESENT
            cout<<"PAGE HIT"<<endl;
            //remove the page from its existing place in list
            dq.erase(ma[page]);

            //insert at the top
            dq.push_front(page);
            ma[page]= dq.begin();

        }

}

void LRU::displayState(){

        list<int>::iterator it;

        for(it = dq.begin(); it!=dq.end(); it++){
            cout<<(*it)<<" ";
        }

        cout<<endl;
}


int main(){

    int arr [] ={ 1,2,3,4,1,2,5,1,2,5,1,2,3,4,5};
    int sz = sizeof(arr)/sizeof(arr[0]);

    LRU *ch = new LRU(3);
    for(int i=0; i<sz; i++){

        cout<<"-> "<<arr[i]<<endl;
        ch->accessPage(arr[i]);
        ch->displayState();

    }
    return 0;
}
