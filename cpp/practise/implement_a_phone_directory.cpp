#include<bits/stdc++.h>

using namespace std;

struct trie{

    bool isLeaf;
    map<char, trie *> children;
    trie(){
        isLeaf = false;
    }
    ~trie(){
        children.clear();
    }

};

void insertTrie(trie *root, string word){

    int len = word.length();
    map<char, trie *>::iterator it;
    trie *temp = root;
    for(int i=0;i<len;i++){

        it = temp->children.find(word[i]);
        if(it==temp->children.end()){
            temp->children[word[i]] = new trie();
        }
        temp=temp->children[word[i]];
    }
    temp->isLeaf=true;
}

void insertWords(trie *root, string contacts[], int n){

    for(int i=0;i<n;i++){
        insertTrie(root, contacts[i]);
    }

}

bool searchTrie(trie *root, string word){

    int len = word.length();
    map<char, trie *>::iterator it;
    for(int i=0;i<len;i++){
        it = root->children.find(word[i]);
        if(it==root->children.end()){
            return false;
        }
        root= root->children[word[i]];
    }

    return (root!=NULL && root->isLeaf==true);
}

void printAllWords(trie *root, string pre){

    if(root->isLeaf==true){
        cout<<"-->\t"<<pre<<endl;
        return;
    }

    map<char, trie *>::iterator it;

    for(it=root->children.begin(); it!=root->children.end(); it++){
            printAllWords(it->second, pre+(char)it->first);
    }

}

bool displayContacts(trie *root, string query_string){
        int len = query_string.length();
        string pre ="";
        map<char, trie*>::iterator it;
        for(int i=0; i<len; i++){

            pre +=query_string[i];

            it = root->children.find(query_string[i]);
            if(it == root->children.end()){
                cout<<"No words found for "<<pre<<endl;
                return 0;
            }
            cout<<"Suggestion on  ==>"<<pre<<endl;
            printAllWords(root->children[query_string[i]], pre);
            root= root->children[query_string[i]];
        }
}

int main(){

    string contacts[]=  {"chandan",  "mittal", "chirag", "shashank","abhinav", "arun", "abhishek" };
    //string contacts[] = {"gforgeeks", "geekquiz"};
    int sz = sizeof(contacts)/sizeof(contacts[0]);

    trie *root = new trie();

    insertWords(root, contacts, sz);

    string query_string = "abhi";

    displayContacts(root, query_string);

//    string cnt = "geekquiz";
//    if(searchTrie(root, cnt))
//       cout<<cnt<<" -> present"<<endl;
//    else
//        cout<<cnt<<" -> Not Present"<<endl;

    return 0;
}
