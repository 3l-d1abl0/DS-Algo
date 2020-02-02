#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

struct Node{
    int key;
    struct Node *right, *left;
};

struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key = key;
    root-> right = root->left = NULL;

    return root;
}

int height(struct Node *root){

    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh)+1;
}

void printOrder(struct Node *root, int i){

    if(root== NULL)
        return;

    if(i==0){
        printf("%d ",root->key);
        return ;
    }else{
        printOrder(root->left, i-1);
        printOrder(root->right, i-1);
    }

}

void printLevelOrder(struct Node *root){

    int h = height(root);

    for(int i=0; i< h ; i++){
        printOrder(root, i);
    }


}

int main(){

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    printLevelOrder(root);

    return 0;
}
