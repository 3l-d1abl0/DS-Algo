#include<bits/stdc++.h>

using namespace std;

class DisjointSet{

    private :

    class Node{
        int data, rank;
        Node *parent;
        public:
        Node(int, int);
    };

    Node::Node(int data, int rank){
        this->data = data;
        this->parent = this;
        this->rank = rank;
    };


    map<int, Node> mp;

public:

    void makeSet(int data){
        Node node = new Node(data,0);
        //node.parent = node;
        mp[data] = node;
    }

    void findSet(int data){

        Node set = mp[data];

        if(set.parent == set){
            return set;
        }else{
            return findSet(set.parent.data);
        }
    }

    //finds parent of the both nodes
    //add node to the node with greater rank
    void union_set(int data1, int data2){

        Node parent1 = findSet(data1);
        Node parent2 = findSet(data2);

        //already in same set, since same parent
        if(parent1.data == parent2.data){
            return;
        }

        if(parent1.rank >= parent2.rank){
            parent2.parent = parent1;

            if(parent1.rank == parent2.rank){
                parent1.rank++;
            }

        }else{
            parent1.parent = parent2;
        }

        //return
    }

};

int main(){

    DisjointSet ds = new DisjointSet();

        ds.makeSet(1);
        ds.makeSet(2);
        ds.makeSet(3);
        ds.makeSet(4);
        ds.makeSet(5);
        ds.makeSet(6);
        ds.makeSet(7);

        ds.union_set(1, 2);
        ds.union_set(2, 3);
        ds.union_set(4, 5);
        ds.union_set(6, 7);
        ds.union_set(5, 6);
        ds.union_set(3, 7);

        cout<<(ds.findSet(1).data);
        cout<<(ds.findSet(2).data);
        cout<<(ds.findSet(3).data);
        cout<<(ds.findSet(4).data);
        cout<<(ds.findSet(5).data);
        cout<<(ds.findSet(6).data);
        cout<<(ds.findSet(7).data);


    return 0;
}
