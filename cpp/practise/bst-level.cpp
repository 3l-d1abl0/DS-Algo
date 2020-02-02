
#include<bits/stdc++.h>

using namespace std;

struct bst{

    int data;
    bst *left;
    bst *right;

    bst(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};

//Insertion in Binary Search Tree
bst *insert(bst *root, int data, int lvl){
    //cout<<"data = "<<data<<endl;

    if(root == NULL){
        root = new bst(data);

        //cout<<root->data<<endl;

        if(root == NULL){
            cout<<"ERROR"<<endl;
            return root;
        }else
            cout<<lvl<<" ";
    }else{
        if(data<root->data){
            root->left = insert(root->left, data, lvl+1);
        }else{
            root->right = insert(root->right, data, lvl+1);
        }

    }

    return root;
}

void solve(int arr[], int sz){

    bst *root = NULL;
    for(int i =0; i<sz; i++){
        root = insert(root, arr[i], 1);
    }
}

int main(){

    int arr [] = {12 ,28 ,5 ,26, 3, 18, 24, 6, 22, 15 ,26 ,20};
    //int arr [] = { 15, 6, 2, 10, 9, 7, 13};

    int sz = sizeof(arr)/sizeof(arr[0]);

    bst *root = NULL;
    bst *tmp = NULL;

    /*for(int i=0; i<sz; i++){
        root = insert(root, arr[i]);
    }*/

    solve(arr, sz);


    return 0;
}
