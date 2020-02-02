#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *right, *left;


    Node(int key){
        data = key;
        right = left = NULL;
    }
};

struct info{

    bool status;
    int min_val;
    int max_val;
    int sz;
};

info post_traversal(Node *root){

    if(root==NULL){
        return { false, INT_MIN, INT_MAX, 0 };
    }

    if(root->left == NULL && root->right ==NULL){
        return { true, root->data, root->data, 1 };
    }

    info l = post_traversal(root->left);
    info r = post_traversal(root->right);

    if(l.status && r.status && l.max_val< root->data && r.min_val > root->data){ //it makes a Binary Tree

        info root_data;

        root_data.sz = l.sz +1 + r.sz;
        root_data.min_val = root->left == NULL ? root->data: l.min_val;
        root_data.max_val = root->right == NULL ? root->data: r.max_val;

        root_data.status = true;

        return root_data;
    }

    //Its not a bst with current root

    return {false, 0,0, max(l.sz, r.sz)};

}

void largestBST(Node *root){

    info largest_bst = post_traversal(root);

    cout<<"latgest_bst ="<<largest_bst.sz<<endl;

}

int main(){


    Node *root = new Node(40);
    root->left = new Node(35);
    root->right = new Node(45);

    root->left->left = new Node(20);
    root->left->right = new Node(25);

    root->left->right->left = new Node(22);
    root->left->right->right = new Node(30);

    root->right->left = new Node(44);
    root->right->right = new Node(50);
    root->right->right->left = new Node(49);
    root->right->right->right = new Node(55);


    largestBST(root);



    return 0;
}
