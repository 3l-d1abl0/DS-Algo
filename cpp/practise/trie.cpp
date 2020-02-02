#include<bits/stdc++.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

struct trie{

    bool isLeaf;
    struct trie *children[ALPHABET_SIZE];

    trie(){
        isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
            children[i] = NULL;
    }
};

void insertTrie(trie *root, char *word){

    int len =strlen(word);
    trie *temp = root;
    for(int i=0; i<len;i++){

        if(!temp->children[word[i]-'a'])
                temp->children[word[i]-'a'] = new trie();
        temp =temp->children[word[i]-'a'];

    }
    temp->isLeaf = true;
}

bool searchTrie(trie *root, char *word){
    int len = strlen(word);
    trie *temp = root;
    for(int i=0; i<len; i++){

        if(!temp->children[ word[i]-'a'])
                return false;

        temp = temp->children[ word[i]-'a' ];
    }

    return (temp!=NULL && temp->isLeaf);    //Node Exists and is Leaf Node
}

int main(){

    char words [][10] = { "the", "a", "there","thereat", "answer", "any","by", "bye", "their"};

    //Initalize root
    trie *root = new trie();
    for(int i=0; i< ARRAY_SIZE(words); i++){
            insertTrie(root, words[i]);
    }

    if(searchTrie(root, "bye")==0){
            cout<<"NOT FOUND\n";
    }else{
            cout<<"FOUND\n";
    }
    cout<<root->isLeaf;

    return 0;
}
