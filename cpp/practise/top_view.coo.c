#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct Node{

    int key;
    struct Node *right, *left;

};

struct Node *newNode(int key){

    struct Node *root =new Node;
    root->key = key;
    root->right = root->left = NULl;

    return root;
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

    return 0;
}
