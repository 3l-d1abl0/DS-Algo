#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct Node{

    int key;
    struct Node *right, *left;
};

struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key;
    root->left = root-> right = NULL;

    return root;
}
int height(struct Node *root){
    if(root==NULL)
        return 0;
    return 1+ max( height(root->right), height(root->left) );
}

int findDiameter(struct Node *root){

    if(root== NULL)
            return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    int lDia = findDiameter(root->left);
    int rDia = findDiameter(root->right);

    return max(lheight+rheight+1 , max(lDia, rDia));
}

int findDiameterOpti(struct Node *root, int *height){

    int lh= 0, rh =0;

    if(root == NULL){
        *height =0; return 0;
    }

    int lDia = findDiameterOpti(root->left, &lh);
    int rDia = findDiameterOpti(root->right, &rh);

    *height = max(lh, rh)+1;

    return max(lh+rh+1, max(lDia, rDia));
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

    printf("Diameter :: %d \n",findDiameter(root) );

    int height =0;
    printf("Diameter Opti :: %d  \n", findDiameterOpti(root, &height) );

    return 0;
}
