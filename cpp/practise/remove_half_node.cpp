#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<utility>
#include<queue>

using namespace std;

struct Node{

    int key;
    struct Node *right, *left;

};

struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key= key;
    root->right = root->left = NULL;
    return root;
}

struct Node *rem(struct Node *root){

    if(root == NULL)
        return NULL;

    root->left = rem(root->left);
    root->right = rem(root->right);

    if(root->left == NULL && root->right == NULL)
        return root;

    if(root->left == NULL){
        struct Node *new_root = root->right;
        free(root);
        return new_root;
    }

    if(root->right == NULL){
        struct Node *new_root = root->left;
        free(root);
        return new_root;
    }

    return root;
}

void printLevelOrder(struct Node *root){

    if(root== NULL)
        return ;

    queue <struct Node *>qq;
    qq.push(root);

    struct Node *node;

    while(!qq.empty()){

        node = qq.front();
        qq.pop();
        printf("%d ", node->key);

        if(node->left !=NULL)
            qq.push(node->left);
        if(node->right !=NULL)
            qq.push(node->right);


    }
}

int main(){

    Node *root = newNode(40);
    root->left =newNode(35);
    root->right =  newNode(45);

    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->right->left = newNode(44);
    root->right->right = newNode(50);

    root->left->right->left = newNode(22);
    root->left->right->right = newNode(30);

    root->left->right->left->left = newNode(10);
    root->left->right->left->right = newNode(2);
    root->left->right->right->left = newNode(9);
    root->left->right->right->right = newNode(150);

    printLevelOrder(root);
    root = rem(root);
    cout<<endl<<endl;
    printLevelOrder(root);

    return 0;
}
