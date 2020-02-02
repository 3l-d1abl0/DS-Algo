#include<bits/stdc++.h>

using namespace std;

class LRU{

    int totalFrames;
    int ctr;

    struct node{
        int pageNum;
        node *prev;
        node *next;

        node(int num){
            pageNum = num;
            prev = next = NULL;
        }
    };

    node * ft, *rr;
    //snode temp;
    map<int, node *> cacheMap;

public:
    LRU(int);
    void accessPage(int);
    void displayState();

};

LRU::LRU(int num){
    totalFrames = num;
    ctr=0;
    ft = NULL;
    rr = NULL;
}

void LRU::accessPage(int page){

    if(this->cacheMap.find(page)==this->cacheMap.end()){
        //PAGE MISS
        cout<<"PAGE MISS "<<endl;

        //Check Page Full
        if(this->totalFrames == this->ctr){

            //remove the last
            //rr->prev->next =NULL;

        }else{


        }

    }else{ //PAGE HIT

        cout<<"PAGE HIT"<<endl;
    }

}

void LRU::displayState(){

    this->node *temp ;

    while(temp != NULL){
        cout<<temp->pageNum<<endl;
        temp = temp->next ;
    }
}

int main(){

    int arr [] ={ 1,2,3,4,1,2,5,1,2,5,1,2,3,4,5};
    int sz = sizeof(arr)/sizeof(arr[0]);

    LRU *ch = new LRU(3);
    for(int i=0; i<sz; i++){

        cout<<"-> "<<arr[i]<<endl;
        ch->accessPage(arr[i]);
        //ch->displayState();

    }
    return 0;

}
