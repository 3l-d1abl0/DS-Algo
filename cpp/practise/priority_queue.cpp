#include<bits/stdc++.h>

using namespace std;

void normal_pq(){

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);
    pq.push(3);

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

}

void ascending_pq(){

    priority_queue<int, vector<int>, greater<int> > pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);
    pq.push(3);

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }


}




    struct Node
    {
        int freq; // store frequency of character
        char ch;

        // function for priority_queue to store Key
        // according to freq
        bool operator<(const Node &k) const{
              //return freq < k.freq;   //descending
            //return freq > k.freq;   //ascending
        }

    };

void custom(){

    priority_queue< Node > pq;

    pq.push( Node { 3, 'b'} );
    pq.push( Node { 2, 'a'} );
    pq.push( Node { 4, 'c'} );
    pq.push( Node { 5, 'd'} );
    pq.push( Node { 1, 'e'} );

    while(!pq.empty()){
        cout<<pq.top().freq<<"  "<<pq.top().ch<<endl;
        pq.pop();
    }

}

    struct Key{
            int freq;   char ch;
    };

    struct comparator{
        bool operator()(const Key &lhs, const Key &rhs)const{
                //return lhs.freq < rhs.freq;     //descending
                return lhs.freq > rhs.freq;     //ascending
        }
    };

    void new_custom(){

        priority_queue<Key, vector<Key>, comparator> pq;

            pq.push( Key { 3, 'b'} );
            pq.push( Key { 2, 'a'} );
            pq.push( Key { 4, 'c'} );
            pq.push( Key { 5, 'd'} );
            pq.push( Key { 1, 'e'} );

            while(!pq.empty()){
                cout<<pq.top().freq<<"  "<<pq.top().ch<<endl;
                pq.pop();
            }

    }

int main(){

    normal_pq();
    cout<<endl;
    ascending_pq();
    cout<<endl;
    custom();
    cout<<endl;
    new_custom();

    return 0;
}
