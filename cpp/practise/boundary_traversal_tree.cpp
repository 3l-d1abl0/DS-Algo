#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *left, *right;
    Node(int x){
        data =x;
        left=right= NULL;
    }
};

void printLeft(Node * root){

        if(root->left){
                cout<<root->data<<" ";
                printLeft(root->left);
        }else if(root->right){
                cout<<root->data<<"  ";
                printLeft(root->right);
        }
}

void printLeaves(Node *root){

    if(root){

        printLeaves(root->left);

        if(root->left== NULL && root->right==NULL)
            cout<<root->data<<"     ";

        printLeaves(root->right);

    }

}

void printRight(Node *root){

    if(root->right){
            printRight(root->right);
            cout<<root->data<<"  ";
    }else if(root->left){
            printRight(root->left);
            cout<<root->data<<" ";
    }

}

void BoundaryTraversal(Node *root){

    cout<<root->data<<"  ";
    printLeft(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    printRight(root->right);
}

int main(){

    Node *start = new Node(20);
    start->left = new Node(8);
    start->right = new Node(22);
    start->right->right = new Node(25);

    start->left->left = new Node(4);
    start->left->right = new Node(12);

    start->left->right->left = new Node(10);
    start->left->right->right = new Node(14);

    BoundaryTraversal(start);

    return 0;
}

