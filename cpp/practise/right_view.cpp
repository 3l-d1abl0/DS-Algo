#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Node{

    int key;
    struct Node *left, *right;

};

struct Node *newNode(int key){

    struct Node *node = new Node;
    node->key = key;
    node->left= node->right = NULL;
}

void rightView(struct Node *root, int level, int *max_level){

    if(root==NULL)
        return;

    if(*max_level < level){
        printf("%d ", root->key);
        *max_level = level;
    }

    rightView(root->right, level+1, max_level);
    rightView(root->left, level+1, max_level);
}

void printRightView(struct Node *root){

    int max_level = 0;
    rightView(root, 1, &max_level);
             //root//level//max_level
}
void leftView(struct Node *root, int level, int *max_level){

    if(root==NULL)
        return;

    if( *max_level < level){
        printf("%d ", root->key);
        *max_level = level;
    }

    leftView(root->left, level+1, max_level);
    rightView(root->right, level+1, max_level);
}


void printLeftView(struct Node *root){

    int max_level = 0;
    leftView(root, 1, &max_level);
}

int main(){

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->left->right->right = newNode(9);

    root->right->left = newNode(6);
    //root->right->left->right = newNode(8);

    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    //printRightView(root);
    printLeftView(root);

    return 0;
}
