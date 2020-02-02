#include<bits/stdc++.h>

using namespace std;

struct Node {

  Node *left, *right;
  int key;

  Node(int num){
      key=num;
      right = NULL;
      left=NULL;
  }

};

Node *LCA(Node *root, int n1, int n2){

  if(root==NULL)
    return NULL;
  //cout<<"Node  : "<<root->key<<endl;
  if(root->key == n1 || root->key ==n2)
    return root;
  //cout<<"___ "<<endl;
  Node *left_node = LCA(root->left, n1, n2 );
  Node *right_node = LCA(root->right, n1, n2 );

  if(left_node && right_node)
    return root;

  return (left_node ==NULL)? right_node: left_node;

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
  cout<<"-------"<<endl;
  cout<<"LCA(1,9) : "<<LCA(root,9,1)->key<<endl;
  cout<<"LCA(1,4) : "<<LCA(root,4,1)->key<<endl;
  cout<<"LCA(1,3) : "<<LCA(root,3,1)->key<<endl;
  cout<<"LCA(2,4) : "<<LCA(root,2,4)->key<<endl;

  cout<<"======"<<endl;

  return 0;
}
