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

void inOrder(bst *root){

    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

//Insertion in Binary Search Tree
bst *insert(bst *root, int data){
    //cout<<"data = "<<data<<endl;

    if(root == NULL){
        root = new bst(data);

        //cout<<root->data<<endl;

        if(root == NULL){
            cout<<"ERROR"<<endl;
            return root;
        }
    }else{
        if(data<root->data){
            root->left = insert(root->left, data);
        }else if(data>root->data){
            root->right = insert(root->right, data);
        }

    }

    return root;
}

//Finding a Node with a data
bst *find(bst *root, int data){

    if(root==NULL)
        return NULL;

    if(data <root->data){
        return find(root->left, data);
    }else if(data>root->data){
        return find(root->right, data);
    }

    return root;
}

bst *findItr(bst *root, int data){

    if(root == nullptr)
        return nullptr;

    while(root){

        if(root->data == data){
            return root;
        }else if(root->data > data){
            root = root->left;
        }else{
            root = root->right;
        }
    }

    return nullptr;

}

bst *getMinRec(bst *root){

    if(root == NULL)
        return NULL;

    if(root->left == NULL)
        return root;
    else
        return getMinRec(root->left);
}

bst *getMinItr(bst *root){

    if(root==NULL)
        return NULL;

    while(root->left!=NULL)
        root=root->left;

    return root;

}

bst *getMaxRec(bst *root){

    if(root==NULL)
        return NULL;

    if(root->right==NULL)
        return NULL;
    else
        return getMaxRec(root->right);
}

bst *getMaxItr(bst *root){

    if(root==NULL)
        return NULL;

    while(root->right!=NULL)
        root=root->right;

    return root;
}

//delete From binary Treee
// Look for inorder Successor and replace with root and delete it

bst *deleteFromBST(bst *root, int data){

    if(root == NULL)
        return NULL;

    if(root->data> data)
        root->left = deleteFromBST(root->left, data);
    else if(root->data< data)
        root->right = deleteFromBST(root->right, data);
    else{
        cout<<"DEL "<<data<<endl;

        if(root->left == NULL && root->right ==NULL){
             delete root;
        }else if(root->left == NULL || root->right == NULL){

            bst *tmp = root;
            root = (root->left) ? root->left : root->right;
            delete tmp;
        }else{

            bst *tmp = getMinRec(root->right);
            root->data = tmp->data;
            root->right = deleteFromBST(root->right, tmp->data);
        }

    }

    return root;
}

int main(){

    int arr [] = {12 ,28 ,5 ,26, 3, 18, 24, 6, 22, 15 ,26 ,20};

    int sz = sizeof(arr)/sizeof(arr[0]);

    bst *root = NULL;
    bst *tmp = NULL;

    for(int i=0; i<sz; i++){
        root = insert(root, arr[i]);
    }

    cout<<"InOrder :: ";inOrder(root);
    cout<<endl;


    tmp = find(root, 12);
    if(tmp){
        cout<<"FOUND"<<endl;
    }else{
        cout<<"NOT FOUND"<<endl;
    }

    tmp = findItr(NULL, 50);
    if(tmp){
        cout<<"ITR FOUND"<<endl;
    }else{
        cout<<"ITR NOT FOUND"<<endl;
    }

    /*
    tmp = getMinItr(root);
    if(tmp)
        cout<<"MIN: "<<tmp->data<<endl;
    else
        cout<<"NULL: "<<endl;

    tmp = getMinRec(root);
    if(tmp)
        cout<<"MIN: "<<tmp->data<<endl;
    else
        cout<<"NULL: "<<endl;

    tmp = getMaxItr(root);
    if(tmp)
        cout<<"MAX: "<<tmp->data<<endl;
    else
        cout<<"NULL: "<<endl;

    tmp = getMaxRec(root);
    if(tmp)
        cout<<"MIN: "<<tmp->data<<endl;
    else
        cout<<"NULL: "<<endl;

    */


    cout<<"Deleting ...24"<<endl;
    deleteFromBST(root, 24);

    tmp = find(root, 24);
    if(tmp){
        cout<<"FOUND "<<tmp->data<<endl;
    }else{
        cout<<"NOT FOUND"<<endl;
    }

    cout<<"InOrder :: ";inOrder(root);
    cout<<endl;

    return 0;
}
