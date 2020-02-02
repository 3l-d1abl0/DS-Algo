#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>

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
void preOrder(struct Node *root){

    if(root == NULL)
        return ;

    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void adjust(struct Node *root, int val){

    if(root->left){
        root->left->key += val;
        adjust(root->left, val);
    }else if(root->right){
        root->right->key +=val;
        adjust(root->right, val);
    }
}


void convert(struct Node *root){

    if(root == NULL || (root->right == NULL && root->left ==NULL ) )
        return ;

    convert(root->left);
    convert(root->right);

    int left_data =0, right_data =0;

    if(root->left)
        left_data = root->left->key;

    if(root->right)
        right_data = root->right->key;

    if(right_data + left_data > root->key)
        root->key += (right_data + left_data) - root->key;

    if(right_data + left_data < root->key)
        adjust(root, root->key - (right_data + left_data));
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

    preOrder(root);
    cout<<endl<<"----------"<<endl;
    convert(root);
    preOrder(root);
    cout<<endl<<"----------"<<endl;
    return 0;
}
