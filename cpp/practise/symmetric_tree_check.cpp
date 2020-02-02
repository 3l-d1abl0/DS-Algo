//check if a tree is symmetric
#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left = NULL;
        right=NULL;
    }

};

//       1
//    /     \
//   2      2
//  / \     / \
//3   4  4   3

//            1
//        /     \
//       2      2
//        \        \
//         3         3

bool Mirror(Node *a, Node *b){

    if(a==NULL && b==NULL)
        return true;

    if(a && b && a->data == b->data){
        return Mirror(a->left, b->right) && Mirror(a->right, b->left);
    }else
    return false;

}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    //root->left->left = new Node(3);
    root->left->right = new Node(3);
    //root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout<<Mirror(root, root)<<endl;
    return 0;
}
