#include<bits/stdc++.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

struct trie{

    bool isLeaf;
    //char ch;
    map<char, trie*> children;

    trie(){
        isLeaf = false;
        //ch='-1';
    }
};

vector<trie*> children_list;

void insertTrie(trie * root, char *word){

    int len =strlen(word);
    trie *temp = root;

    map<char, trie*>::iterator it;
    cout<<"Length ::"<<len<<endl;
    int i;
    for(i=0; i<len; i++){

        it = temp->children.find(word[i]);
        if(it == temp->children.end()){
                temp->children[word[i]] = new trie();
                children_list.push_back(temp->children[word[i]] );
        }
        temp = temp->children[word[i]];
    }
    cout<<"i= "<<i<<endl;
    temp->isLeaf = true;
}

bool searchTrie(trie *root, string word){

    int len = word.length();
    trie *temp = root;
    map<char, trie *>::iterator it;
    for(int i=0; i<len; i++){

        it = temp->children.find(word[i]);
        if(it== temp->children.end()){
            return false;
        }
        temp = temp->children[word[i]];
    }

    return (temp!=NULL && temp->isLeaf );   //Node Exists and is Leaf Node

}



//Not Complete
int prefixSearch(trie *root, string word){

        int len = word.length();
        trie *temp = root;
        map<char, trie*>::iterator it;
        int sz;

        for(int i=0; i<len; i++){

            it = temp->children.find(word[i]);
            if(it== temp->children.end()){
                return 0;
            }

            temp = temp->children[word[i]];
            sz = temp->children.size();
        }

        return sz;
}


bool del(trie *root, string word, int idx){

    if(idx == word.length()){

        if(root->isLeaf== false)
            return false;

        root->isLeaf = false;
        return root->children.size() ==0;
    }else{
            map<char, trie *>::iterator it;

            //look for the character in children Map
            it = root->children.find(word[idx]);
            if(it == root->children.end()){ //If Character does not exists, return false
                return false;
            }

            bool shouldDeleteCurrentNode = del(root->children[word[idx]], word, idx+1);

            if(shouldDeleteCurrentNode){
                root->children.erase(word[idx]);

                return root->children.size()==0;
            }

            return false;
    }

}

bool deleteWord(trie *root, string word){
    del(root, word,0);
}

/*
void display_trie(trie *root, char str[], int idx){

	if(root->isLeaf){
		str[idx] = '\0';
		cout<<str<<endl;
		//return;
	}

	map<char, trie*>::iterator it;

	for(it = root->childrens.begin(); it!= root->childrens.end(); it++){

		str[idx] = it->first;
		//cout<<it->first<<endl;
		display_trie(it->second, str, idx+1);
	}
}*/

int main(){

    //char words [][10] = { "the", "a", "there","thereat", "answer", "any","by", "bye", "their"};
    //char words[][10] = {"foo", "bar", "baz", "barz"};

    char words[][10] =  {"chandan",  "mittal", "chirag", "shashank","abhinav", "arun", "abhishek" };

    //Initalize root
    trie *root = new trie();
    for(int i=0; i< ARRAY_SIZE(words); i++){
            insertTrie(root, words[i]);
    }

    	char str[30];

//	display_trie(root, str, 0);

//    if(!searchTrie(root, "foo")){
//            cout<<"NOT FOUND\n";
//    }else{
//            cout<<"FOUND\n";
//    }
//    if(!searchTrie(root, "fooz")){
//            cout<<"NOT FOUND\n";
//    }else{
//            cout<<"FOUND\n";
//    }
//    if(!searchTrie(root, "bar")){
//            cout<<"NOT FOUND\n";
//    }else{
//            cout<<"FOUND\n";
//    }
//    if(!searchTrie(root, "baz")){
//            cout<<"NOT FOUND\n";
//    }else{
//            cout<<"FOUND\n";
//    }
//    if(!searchTrie(root, "barz")){
//            cout<<"NOT FOUND\n";
//    }else{
//            cout<<"FOUND\n";
//    }
//    if(!searchTrie(root, "bbb")){
//            cout<<"NOT FOUND\n";
//    }else{
//            cout<<"FOUND\n";
//    }


//    if(!searchTrie(root,"chandan")){
//        cout<<"NOT FOUND\n";
//    }else{ cout<<"FOUND\n";  }
//
//    if(!searchTrie(root,"arun")){
//        cout<<"NOT FOUND\n";
//    }else{ cout<<"FOUND\n";  }
//
//    if(!searchTrie(root,"abhi")){
//        cout<<"NOT FOUND\n";
//    }else{ cout<<"FOUND\n";  }

    //cout<<root->isLeaf;

   printf("no of words with prefix abhi are %d\n",prefixSearch(root,"abhi"));
//	printf("no of words with prefix ch are %d\n",prefixSearch(root,"ch"));
//	printf("no of words with prefix a are %d\n ",prefixSearch(root,"a"));

    //Deletion : cases :
    //"abc","xy","xyz","abb""xyzb", "word"
    //1. word not in trie -> qwert
    //2. neither prefic nor suffix -> "word"
    //3.  is prefix of some other node ->  "xyz"
    //4. a part is suffix of some other key -> "xyz(b)"
    //5. some part is shared by other keys ->  abc  => (ab) -> b -> c


    //{"abc", "abb", "xy", "xyz", "xyzb", "word" }

    //char words[][10] =  {"chandan",  "mittal", "chirag", "shashank","abhinav", "arun", "abhishek" };

    if(!searchTrie(root,"abhinav")){
        cout<<"NOT FOUND\n";
    }else{ cout<<"FOUND\n";  }

    if(!searchTrie(root,"abhishek")){
        cout<<"NOT FOUND\n";
    }else{ cout<<"FOUND\n";  }


    deleteWord(root, "abhinav");

            if(!searchTrie(root,"abhinav")){
        cout<<"NOT FOUND\n";
    }else{ cout<<"FOUND\n";  }

        if(!searchTrie(root,"abhishek")){
        cout<<"NOT FOUND\n";
    }else{ cout<<"FOUND\n";  }

    for (int i=0; i<children_list.size(); ++i) {
        delete children_list[i];
    }

    return 0;
}
