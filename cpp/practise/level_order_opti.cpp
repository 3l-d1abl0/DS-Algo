#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

struct Node {

    int key;
    struct Node * right, *left;

};
struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key =key;
    root->left = root->right = NULL;

    //return NULL;
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

    struct Node *root = newNode(1);
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
