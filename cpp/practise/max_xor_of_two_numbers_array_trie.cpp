#include<bits/stdc++.h>

#define MSB 32

using namespace std;

struct trie{

    bool isLeaf;
    map<int, trie *>children;

    trie(){
        isLeaf = false;
    }
    ~trie(){
        children.clear();
    }

};

void insert_num(trie *root, int num){

    map<int, trie*>::iterator it;

    for(int i=MSB; i>=0;i--){
        int bit = (bool)(num & (1<<i));

        it = root->children.find(bit);
        if(it== root->children.end()){
                root->children[bit] = new trie();
        }
        root = root->children[bit];
    }
        root->isLeaf = true;
}

int query(trie *root, int num){

    int XoR=0;
    map<int, trie *>::iterator it;
    for(int i=MSB; i>=0; i--){
        int bit = (bool)(num & (1<<i));

            it = root->children.find(!bit);
            if(it == root->children.end()){
                root= root->children[bit];
            }else{
                root = root->children[!bit];
                XoR |= (1<<i);
            }
    }
    return XoR;
}

int findMaximumXOR(trie *root, vector<int >& arr){

    int n = arr.size();

    if(n<2) return 0;

    for(int i=0;i<n;i++){
        insert_num(root, arr[i]);
    }

    int result =0;
    for(int i=0; i<n; i++){
        result = max(result, query(root, arr[i]));
    }

    return result;

}


int main(){

    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    vector<int > vec  (arr, arr+ sizeof(arr)/sizeof(arr[0]) );
    trie *root = new trie();

    cout<<findMaximumXOR(root, vec )<<endl;

    return 0;
}
