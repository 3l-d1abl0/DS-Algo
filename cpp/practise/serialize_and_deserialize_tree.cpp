#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *left, *right;
    Node(int x){
        data =x;
        left=NULL;
        right = NULL;
    }
};

void inorder(Node *root){

    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);

}

void serialize(Node *root,int arr[], int *idx){

    if(root==NULL){
        arr[(*idx)]=-1;
        (*idx)++;
        return;
    }

    arr[(*idx)]=root->data;     (*idx)++;
    serialize(root->left, arr, idx);
    serialize(root->right, arr, idx);
}

Node *deserialize(int arr[], int cnt, int *idx){

    if(arr[(*idx)]==-1 || (*idx)==cnt){
        (*idx)++;
        return NULL;
    }

    Node *root = new Node(arr[(*idx)]);  (*idx)++;
    root->left = deserialize(arr, cnt, idx);
    root->right = deserialize(arr, cnt, idx);

    return root;
}

int main(){

    int arr[100];
     Node *root = new Node(20);
     root->left = new Node(8);
     root->right = new Node(22);
     root->left->left = new Node(4);
     root->left->right = new Node(12);
     root->left->right->left = new Node(10);
     root->left->right->right = new Node(14);

    cout<<"INORDER : "<<endl;
     inorder(root);

    int idx =0;
    serialize(root, arr, &idx);

    cout<<"\n Serialized Array :: "<<idx<<endl;
    for(int i=0;i <idx;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    int cnt=0;
    Node *droot = deserialize(arr, idx, &cnt);

    cout<<"INORDER :  Deseralize :: "<<endl;
     inorder(droot);

    return 0;
}
