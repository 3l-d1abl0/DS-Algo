#include<bits/stdc++.h>
#define MAX_HEIGHT 10000

using namespace std;


struct Node{
    int key;
    Node *left, *right;

    Node(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

void KDistanceFromLeaf(Node *node, int path[], bool visited[], int len, int k){

    if(node == NULL) return;

    path[len]= node->key;
    visited[len] = false;
    len++;

    if(node->left== NULL && node->right== NULL && len-(k+1) >=0 && visited[len-(k+1)]==false){
        cout<<path[len-(k+1)]<<endl;
        visited[len-(k+1)]= true;
        return;
    }

    KDistanceFromLeaf(node->left, path, visited, len, k);
    KDistanceFromLeaf(node->right, path, visited, len, k);
}

void printKDistantfromLeaf(Node* node, int k){

    int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    KDistanceFromLeaf(node, path, visited, 0, k);

}

int main(){

    //              1
    //            2      3
    //          4  5   6    7
    //                  8
    
    Node * root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8);


    cout << "Nodes at distance 1 are: "<<endl; 
    printKDistantfromLeaf(root, 1); 

    return 0;
}
