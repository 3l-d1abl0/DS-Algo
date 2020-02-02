#include<bits/stdc++.h>

using namespace std;

struct Node{

    Node *left, *right;
    int key;

    Node(int num){
        key = num;
        right = NULL;
        left = NULL;
    }

};

void printKDown(Node *target, int k){

    if(target==NULL || k < 0)
        return;

    if(k==0){
        cout<<target->key<<endl;
        return;
    }
    cout<<"Down"<<endl;
    printKDown(target->left, k-1);
    printKDown(target->right, k-1);
}

int k_distance_from_node(Node *root, Node *target, int k){

    if(root= NULL)
        return -1;

    if(root== target){
        printKDown(target, k);
        return 0;
    }


}

int main(){


    /* Constructed binary tree is
              10
            /   \
          8      2
        /  \    /
      3     5  4
    /  \     \
   6   1     9
  */

  Node *root = new Node(10);
  root->left = new Node(8);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->left->left = new Node(6);
  root->left->left->right = new Node(1);
  root->left->right = new Node(5);
  root->left->right->right = new Node(9);
  root->right->left = new Node(4);

  Node *target = root->left;    //8
  cout<<"Target :: "<<target->key<<endl;
  int k = 2;
  k_distance_from_node(root, target, k);


    return 0;
}
