#include<bits/stdc++.h>

using namespace std;

struct tst{

    bool isLeaf;
    char data;
    struct tst *left;
    struct tst *mid;
    struct tst *right;

    tst(char *word){
        isLeaf = false;
        data = *word;
        left = mid = right = NULL;
    }
};

tst *insert_tst(tst *root, char *word){

    //base case if root is NULL
    if(root== NULL){
        root = new tst(word);
    }

    if(*word < root->data ){    //left
        root->left = insert_tst(root->left, word);
    }else if(*word > root->data){   //right
        root->right = insert_tst(root->right, word);
    }else{  //mid
        if(*(word+1)){  //NOT NULL
            root->mid = insert_tst(root->mid, word+1);
        }else{
            root->isLeaf = true;
        }
    }

    return root;
}

void traverse_tst(tst *root, char *buffer, int length){

    if(root){

        traverse_tst(root->left, buffer, length);

        buffer[length] = root->data;
        if(root->isLeaf){
            buffer[length+1] = '\0';
            cout<<buffer<<endl;
        }

        traverse_tst(root->mid, buffer, length+1);

        traverse_tst(root->right, buffer, length);

    }

}

bool search_tst(tst *root, char *word){

        if(root==NULL)
            return 0;

        if(*word < root->data)
            search_tst(root->left, word);

        else if(*word > root->data)
            search_tst(root->right, word);

        else{
                if(*(word+1) == '\0')
                    return root->isLeaf;
                else
                    return search_tst(root->mid, word+1);
        }
}

int main(){

    char words[][10] = {"boats", "boat", "bat", "bats", "stages" };
    //char words[][10] = {"cat", "cats", "up", "bug" };
    int wsz = sizeof(words)/sizeof(words[0]);
    tst *root = NULL;
    int MAX_LEN =-1;
    for(int i=0;i<wsz;i++){
        root = insert_tst(root, words[i]);
        MAX_LEN = MAX_LEN>strlen(words[i])?MAX_LEN:strlen(words[i]);
    }

    char buffer[MAX_LEN];
    traverse_tst(root, buffer, 0);
    cout<<"----------"<<endl;

    printf("bat :: %s\n",search_tst(root, "bat")?" Found ":" Not Found");
    printf("batman ::  %s\n",search_tst(root, "batman")?" Found ":" Not Found");
    printf("boats :: %s\n",search_tst(root, "boats")?" Found ":" Not Found");


    return 0;
}
