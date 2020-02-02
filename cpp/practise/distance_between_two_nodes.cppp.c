#include<bits/stdc++.h>

using namespace std;

struct Node
{
    struct Node *left, *right;
    int key;

    Node(int data){
        key=data;
        left = NULL;
        right = NULL;
    }
};

Node *getLCA(Node *root, int a1,int a2){

    if(root==NULL)
        return NULL;

    if(root->key== a1 || root->key == a2)
        return root;

    Node *left = getLCA(root->left, a1, a2);
    Node *right = getLCA(root->right, a1, a2);

    if(left !=NULL && right != NULL)
        return root;
    else if(left==NULL)
        return right;
    else
        return left;
}


int findDistance(Node * root, int a1, int a2){

    Node *lca = getLCA(root, a1, a2);

    cout<<"LCA : "<<lca->key<<endl;
}

int main(){

    //       1
    //    2       3
    //  4   5   6  7
    //           8

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    printf("Distance Between %d and %d : %d \n",5,5,findDistance(root, 5,6));

    return 0;
}
