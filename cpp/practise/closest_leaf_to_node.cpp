#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    struct Node* left, *right;

    /*Node(int key){
        this->key = key;
        this->left = this->right = NULL;
    }*/
};

// Utility function to create a new node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

void lookDown(Node *root, int lvl, int *minDis){

    if(root== NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        if(lvl < *minDis){
            *minDis = lvl;
            return;
        }
    }
    lookDown(root->left, lvl+1, minDis);
    lookDown(root->right, lvl+1, minDis);
}

int otherSubtree(Node *root, Node *x, int *minDis){

    if(root==NULL)
        return -1;

    if(root==x)
        return 0;

    int r = otherSubtree(root->right, x, minDis);
    if(r!=-1){
        lookDown(root->left, r+2, minDis);
        return r+1;
    }

    int l = otherSubtree(root->left, x, minDis);
    if(l!=-1){
        lookDown(root->right, l+2, minDis);
        return l+1;
    }

    return -1;
}

int minimumDistance(Node *root, Node *x){

    //look for leaf down below the given Node
    int minDis = INT_MAX;
    lookDown(x, 0, &minDis);

    //look for leaf on Other Sub Tree
    otherSubtree(root, x, &minDis);

    return minDis;
}

int main(){

        // Let us create Binary Tree shown in above example
    Node *root  = newNode(1);
    root->left  = newNode(12);
    root->right = newNode(13);

    root->right->left   = newNode(14);
    root->right->right  = newNode(15);

    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);

    root->right->left->left->left  = newNode(1);
    root->right->left->left->right = newNode(2);
    root->right->left->right->left  = newNode(3);
    root->right->left->right->right = newNode(4);
    root->right->right->left->left  = newNode(5);
    root->right->right->left->right = newNode(6);
    root->right->right->right->left = newNode(7);
    root->right->right->right->right = newNode(8);

    Node *x = root->right;

    cout << "The closest leaf to the node with value "
         << x->key << " is at a distance of "
         << minimumDistance(root, x) << endl;

    return 0;

    return 0;
}
