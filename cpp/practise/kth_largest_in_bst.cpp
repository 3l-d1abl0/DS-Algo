#include<iostream>
#include<cstring>
#include<cstring>

using namespace std;

struct Node{

    int data;
    Node *left, *right;

    Node(int num){
        data=num;
        left=right=NULL;
    }

};

void in_order(Node *root){

    if(root==NULL)
        return;

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}

Node *kth(Node *root, int K, int &cnt){

    if(root== NULL)
        return NULL;

    kth(root->right, K, cnt);

    cnt++;

    if(cnt==K){
        return root;
    }

    kth(root->left, K, cnt);

}

void kthLargest(Node *root, int K){

    int cnt=0;
    cout<<"Kth Largest :: "<<kth(root, K, cnt)->data<<endl;

}
int main(){

//                   50
//                /        \
//            40          60
//          /     \         /   \
//       30      45   55   70
//
    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->right = new Node(45);
    root->right->left = new Node(55);
    root->right->right = new Node(70);

    in_order(root);
    //utilize reverse inorder
    int K=4;cout<<endl;
    kthLargest(root,K);

    return 0;
}
