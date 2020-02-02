#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int num){
        this->data = num;
        left = NULL;
        right = NULL;
    }
};

struct Info{
    int sz;
    int min_limit;
    int max_limit;
    bool isBst;
};

Info bstCheck(Node *root, int &mx_sz){

    //if(root->data < min_limit || root->data > max_limit)
    //    return {0, false};

    if(root->data == NULL)
        return {0, INT_MIN, INT_MAX, true};

    if(root->left==NULL && root->right==NULL)
        return {1, root->data, root->data, true};


    Info lf = bstCheck(root->left, mx_sz);
    Info rt = bstCheck(root->right, mx_sz);

    //printf("%d ==> %d %d\n", root->data, lf.isBst, rt.isBst);

    if( lf.isBst==true && rt.isBst==true && root->data > lf.max_limit && root->data < rt.min_limit ){

        mx_sz = mx_sz > lf.sz+rt.sz+1 ? mx_sz : lf.sz+rt.sz+1;
        return {lf.sz+rt.sz+1, min(lf.min_limit, root->data), max(rt.max_limit, root->data), true};

    }


    return{ 0, INT_MIN, INT_MAX, false};

}

int largestBst(Node *root){

    int mx_sz =-1;
    Info ans = bstCheck(root, mx_sz);
    return mx_sz;
}

int main(){
    /*
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->right = new Node(80);
    root->right->right->left = new Node(65);
    */

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    printf("largest BST : %d", largestBst(root));

    return 0;
}
