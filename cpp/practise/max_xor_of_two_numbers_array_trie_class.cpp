#include<bits/stdc++.h>

#define MSB 30  //Most significant Bit

using namespace std;

class trie{

private:
    struct trieNode{
            bool isLeaf;
            map<int, trieNode*>children;

            trieNode(){     //structure Constructor
                isLeaf = false;
            }
        ~trieNode(){    //Structure Destructor
                children.clear();
        }
    };

    trieNode *root;

public:
    trie(): root(new trieNode()){ }     //trie Constructor
    ~trie(){    //trie Destructor
            delete root;
    }

    void insert_num(int);
    int query(int);
    int findMaxXor(vector<int>&);
};

void trie:: insert_num(int key){

    trieNode *temp = root;
    map<int, trie::trieNode *>::iterator it;
    for(int i= MSB; i>=0; i--){
        int bit = (bool)(key & (1<<i));

        it = temp->children.find(bit);
        if(it == temp->children.end()){
                temp->children[bit] = new trieNode();
        }
        temp = temp->children[bit];
    }
    temp->isLeaf= true;
}

int trie::query(int key){

    int XoR=0;
    trieNode *temp = root;
    map<int, trie::trieNode *>::iterator it;

    for(int i=MSB; i>=0; i--){
        int bit = (bool)(key & (1<<i));
        it = temp->children.find(!bit);
        if(it == temp->children.end()){
                temp = temp->children[bit];
        }else{
                temp = temp->children[!bit];
                XoR |= (1<<i);
        }
    }

    return XoR;

}

int trie :: findMaxXor(vector<int >& arr){

    int n = arr.size();
    if(n<2) return 0;

    for(int i=0; i<n; i++){
        insert_num(arr[i]);
    }
    int XoR=0;
    for(int i=0;i<n;i++){
        XoR = max(XoR, query(arr[i]));
    }

    return XoR;
}

int main(){

    trie ob;
    //ob.insert_num(123);

    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    vector<int > vec  (arr, arr+ sizeof(arr)/sizeof(arr[0]) );
    cout<<ob.findMaxXor(vec)<<endl;
    return 0;
}
