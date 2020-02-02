#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

void in_order(Node * root, vector<int >&arr){

    if (root == NULL)
        return ;

    in_order(root->left, arr);

    arr.push_back(root->data);

    in_order(root->right, arr);
}

void BSTtoHeap(Node *root, vector<int>arr, int *i){

    if(root == NULL)
        return ;

    BSTtoHeap(root->left, arr, i);

    BSTtoHeap(root->right, arr, i);

    //cout<<":: "<<arr[*i]<<" i= "<<*i<<endl;
    root->data = arr[(*i)++];

}

void convertToMaxHeapUtil(Node * root){

    //array to store node vals
    vector<int > arr;

    in_order(root, arr);

    vector<int >::iterator it;

    /*for(it = arr.begin(); it != arr.end(); it++){
        cout<<*it<<" ";
    }*/
    int i=0;
    BSTtoHeap(root, arr, &i); //PostOrder with array Insertion

}

void postorderTraversal(Node *root){

    if(root == NULL)
        return ;

    postorderTraversal(root->left);

    postorderTraversal(root->right);

    cout<<root->data<<" ";
}

int main(){

    // BST formation
    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMaxHeapUtil(root);


    cout << "Postorder Traversal of Tree:" << endl;
    postorderTraversal(root);

    return 0;

}
