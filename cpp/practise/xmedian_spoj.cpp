#include<bits/stdc++.h>


using namespace std;

void addNumbers(int x, priority_queue<int> &lHeap, priority_queue<int, vector<int>, greater<int> > &hHeap){

        if(lHeap.empty() || x<lHeap.top()){
            lHeap.push(x);
        }else{
            hHeap.push(x);
        }
}

void rebalance(priority_queue<int>  &lHeap, priority_queue<int, vector<int>, greater<int> > &hHeap){

        //priority_queue<int > biggerHeap = (lHeap.size() > hHeap.size() )? lHeap : hHeap;
        //priority_queue<int > smallerHeap = (lHeap.size() > hHeap.size() )? hHeap : lHeap;
        if(lHeap.size() > hHeap.size() &&  (lHeap.size() - hHeap.size()) >=2 ){
                hHeap.push(lHeap.top());    lHeap.pop();
        }else if(hHeap.size() > lHeap.size() &&  (hHeap.size() - lHeap.size()) >=2 ){
                    lHeap.push(hHeap.top());   hHeap.pop();
        }

}

int get_median(priority_queue<int > &lHeap, priority_queue<int, vector<int>, greater<int> > &hHeap){

                //priority_queue<int > biggerHeap = lHeap.size() > hHeap.size() ? lHeap : hHeap;
                //priority_queue<int > smallerHeap = lHeap.size() > hHeap.size() ? hHeap : lHeap;

                if(lHeap.size() == hHeap.size()){
                        return (lHeap.top() + hHeap.top())/2;
                }else{

                    if( lHeap.size() > hHeap.size())
                        return lHeap.top();
                    else{
                        return hHeap.top();
                    }
                }
}

int main(){

    int n, x;
    priority_queue<int, vector<int>, greater<int> > hHeap;  //heap for higher numbers       //mIN hEAP
    priority_queue<int> lHeap;      //heap for lower numbers    // Max Heap

    scanf("%d", &n);

    for(int i=0; i<n;i++){
        scanf("%d", &x);

        addNumbers(x, lHeap, hHeap);   // cout<<"adding ... "<<x<<endl;
        rebalance(lHeap, hHeap);        //cout<<"rebalancing ..."<<endl;
        printf("%d\n", get_median(lHeap, hHeap));
    }

    return 0;
}
