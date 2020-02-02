#include<bits/stdc++.h>

#define MSB 32

using namespace std;

  struct trie{

    bool isLeaf;
    map<int, trie*>children;
    trie(){
        isLeaf=false;
    }
    ~trie(){
        children.clear();
    }
  };

void trie_insert(trie *root, int num){

    map<int, trie*>::iterator it;

    for(int i=MSB; i>=0; i--){
        int bit = (bool) (num & (1<<i));
       // cout<<bit<<endl;
        it = root->children.find(bit);
        if(it== root->children.end()){
            root->children[bit] = new trie();
        }
        root = root->children[bit];
    }
    root->isLeaf = true;

}

int query(trie *root, int num){

    map<int, trie *>::iterator it;
    int XoR =0;

    for(int i=MSB; i>=0; i--){
        int bit = (bool)(num &(1<<i));
        cout<<bit<<endl;
        it= root->children.find(!bit);
        if(it== root->children.end()){
            root = root->children[bit];
        }else{
            root = root->children[!bit];
            XoR |= (1<<i);
        }
    }

    return XoR;
}

int main(){

    /*
        1010
        0000
        _____
        1010

        1010
        1111
        ____
        0101

        1,2,3,4,5,6
        1 ,1-2, 1-3, 1-4, 1-5, 1-6
        1,
        1, 1-2
        1, 1-2, 1-3
        1, 1-2, 1-3, 1-4
        1, 1-2, 1-3, 1-4, 1-5
        1, 1-2, 1-3, 1-4, 1-5, 1-6
    */

    trie *root = new trie();

    //int arr[] ={1,2,3,4,5,6,7,8,9,10};
    int arr[]={8, 1, 2, 12};
    int sz= sizeof(arr)/sizeof(arr[0]);
    int leftRange =0;
    int maxXoR =0;
    trie_insert(root, 0);
    //cout<<"Loop :: "<<endl;
    for(int i=0;i<sz;i++){
        leftRange = leftRange^arr[i];   //cout<<"inserting.."<<leftRange<<endl;
        trie_insert(root, leftRange);
        //cout<<"Comaring .."<<endl;
        maxXoR = max(maxXoR, query(root, leftRange));

        //cout<<"i = "<<i<<endl;
    }

    cout<<"Maxx XOR of Ranges :: "<<maxXoR<<endl;

    return 0;
}
