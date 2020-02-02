#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<queue>

using namespace std;

struct Node{

    int key;
    struct Node *right, *left;
};

struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key=key;
    root->left = root-> right = NULL;

    return root;
}

bool isBST(struct Node *node, int MIN, int MAX){

    if(node == NULL)
        return true;

    if(node->key < MIN || node->key >MAX){
        //printf("%d MAX :: %d\n",node->key, MAX);
        return false;
    }

    return isBST(node->left, MIN, node->key -1) && isBST(node->right, node->key+1, MAX);
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

    Node *root = newNode(50);
    root->left =newNode(30);
    root->right =  newNode(60);

    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(55);
    root->right->right = newNode(65);

    root->left->right->left = newNode(35);
    root->left->right->right = newNode(45);

    root->left->right->left->left = newNode(31);
    root->left->right->left->right = newNode(36);
    root->left->right->right->left = newNode(41);
    root->left->right->right->right = newNode(46);


    //Node *root = newNode(40);
    //root->left =newNode(35);
    //root->right =  newNode(45);

    //root->left->left = newNode(20);
    //root->left->right = newNode(25);
    //root->right->left = newNode(44);
    //root->right->right = newNode(50);

    //root->left->right->left = newNode(22);
    //root->left->right->right = newNode(30);

    //root->left->right->left->left = newNode(10);
    //root->left->right->left->right = newNode(2);
    //root->left->right->right->left = newNode(9);
    //root->left->right->right->right = newNode(150);



    printLevelOrder(root);

    printf("\n is BST : %d", isBST(root, INT_MIN, INT_MAX) );


    return 0;
}
