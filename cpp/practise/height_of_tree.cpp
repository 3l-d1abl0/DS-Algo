#include<bits/stdc++.h>

using namespace std;

struct node{

    int data;
    struct node *left;
    struct node *right;

    node(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root){

    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

int ht(struct node *root){

    if(root==NULL)
        return 0;

    int leftHeight = ht(root->left);
    int rightHeight = ht(root->right);

    return max(leftHeight, rightHeight) +1;

}

int main(){

    struct node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    //root->left->left = new node(4);
    //root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->left->right = new node(8);
    root->right->right->left = new node(10);

    preorder(root);

    cout<<endl;

    cout<<"Height : "<<ht(root);

    return 0;
}
