#include<bits/stdc++.h>

using namespace std;


struct Node{

    int key;
    Node *left;
    Node *right;

    Node(int data){
        key = data;
        left = NULL;
        right = NULL;
    }

};


void inOrder(Node *root){

    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);

}

Node* prune(Node *root, int k){

    if(root == NULL) return NULL;

    root->left = prune(root->left, k-root->key);
    root->right = prune(root->right, k-root->key);

    if(root->left == NULL && root->right== NULL){
        if(root->key< k){
            delete root;
            return NULL;
        }
    }

    return root;

}


int main(){

    int k = 45;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);


    cout<<"Before Pruning :"<<endl;
    inOrder(root);


    prune(root, k);

    cout<<"After Pruning :"<<endl;
    inOrder(root);


    return 0;
}
