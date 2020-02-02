#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define HT 1000
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

Node* newNode(int key){

    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
void calc(Node *root, int path[], bool vis[], int idx, int K){

    if(root == NULL)
        return;

    path[idx] = root->key;
    vis[idx] = false;
    idx++;

    if( root->right == NULL && root->left == NULL  && idx-K-1 >=0 && vis[idx-K-1]==false ){
        cout<<path[idx-K-1]<<"."<<endl;
        vis[idx-K-1] = true;
        return;
    }

    calc(root->left, path, vis, idx, K);
    calc(root->right, path, vis, idx, K);

}

int printKDistantfromLeaf(Node *root, int K){

    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    int lf = calc(root->left, K);
    int rt = calc(root->right, K)

    if(lf+1 == K || rt+1 == K){
        cout<<root->key<<". "<<endl;
        break;
    }
    else{
        return le
    }
}

int main(){

        // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout << "Nodes at distance 2 are: "<<endl;
    printKDistantfromLeaf(root, 2);

    return 0;

}
