#include<bits/stdc++.h>

using namespace std;

struct node{
    int pageNum;
    node *prev;
    node *next;

    node(int pagenum){
        pageNum = pagenum;
        prev = next= NULL;
    }

};

struct lruQ{

    int totalFrames;
    int cnt;
    node *front, *rear;

    lruQ(int frames){
        totalFrames = frames;
        cnt =0;
        front = rear = NULL;
    }
};

//Map // address to page
map<int, node *>cacheMap;

void dqueue_page(lruQ *q){

    //If only Node // If Frames are One
    node *temp ;
    if(q->front==q->rear){
        temp = q->front;
        q->front = q->rear = NULL;
    }else{
        temp = q->rear;

        q->rear->prev->next = q->rear->next;    //Should be NULL Since last node
        q->rear = q->rear->prev;
    }

    cacheMap[temp->pageNum] = NULL;
    delete(temp);
    q->cnt--;

}

void enqueue_page(lruQ *q, int pageNum){

    if(q->cnt == q->totalFrames){   //Cache is Full
        dqueue_page(q);
    }

        node *new_page = new node(pageNum);
        new_page->next = q->front;

        if(q->front == NULL && q->rear==NULL){ //cache empty // very first node has been inserted
            q->front = q->rear = new_page;
        }else{
            q->front->prev = new_page;
            q->front = new_page;
        }
        cacheMap[pageNum] = new_page;
        q->cnt++;

}

void accessPage(lruQ *q, int pageNum){

        //1. check Page exists in Cache
        node *pageFrame = cacheMap[pageNum];    // it = cacheMap.find(pageNum)
        if(pageFrame == NULL){  //PAGE MISS
            //EnQueue that page in the Cache
            cout<<"MISS"<<endl;
            enqueue_page(q, pageNum);
        }else{  //PAGE HIT

            //Bring that page to the Front of Queue If Not
            if(pageFrame != q->front){

                //Link the Neighbours
                pageFrame->prev->next = pageFrame->next;

                if(pageFrame->next)
                    pageFrame->next->prev = pageFrame->prev;

                //If tha page is the last one
                if(pageFrame == q->rear){
                    q->rear = pageFrame->prev;
                }

                //Put page at top
                pageFrame->next = q->front;
                q->front->prev = pageFrame;
                pageFrame->prev = NULL;

                q->front = pageFrame;

            }

        }

}

void printQstate(lruQ *q){

    node *temp = q->front;
    while(temp!=NULL){
        cout<<temp->pageNum<<"  ";
        temp = temp->next;
    }
}

int main(){

    int arr [] ={ 1,2,3,4,1,2,5,1,2,5,1,2,3,4,5 };
    int sz = sizeof(arr)/sizeof(arr[0]);
    lruQ *q = new lruQ(4);

    for(int i=0; i<sz;i++){

        cout<<"Query -> "<<arr[i]<<endl;
        accessPage(q, arr[i]);
        cout<<"State :: "<<endl;
        printQstate(q);
        cout<<endl;
    }


    return 0;
}
