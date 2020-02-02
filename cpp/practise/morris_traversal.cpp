#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;

    Node(int num){
        data=num;
        right = NULL;
        left=NULL;
    }
};

void morris_preorder(Node *root){

  if(root==NULL)
    return ;

  Node *current = root;
  while(current){

      if(current->left==NULL){
          cout<<current->data<<" ";
          current=current->right;
      }else{

          Node *pre = current->left;

          while (pre->right!=NULL && pre->right!=current) {
            pre=pre->right;
          }

          if(pre->right==NULL){
            cout<<current->data<<" ";
            pre->right=current;
            current=current->left;
          }else{
            //pre->right=current
            pre->right=NULL;
            current=current->right;

          }

      }
  }

}

void morris_inorder(Node *root){

    if(root==NULL)
        return ;
    Node * current = root;
    while(current){

        if(current->left==NULL){

            cout<<current->data<<" ";
            current = current->right;
        }else{

            //rightmost node on the left child
            Node *pre = current->left;

            while(pre->right!=NULL && pre->right!=current)
                pre= pre->right;

            if(pre->right==NULL){
                    pre->right= current;
                    current= current->left;
            }else{
                    pre->right = NULL;
                    cout<<current->data<<" ";
                    current= current ->right;
            }

        }
    }
}

int main(){

    /* Constructed binary tree is
                10
              /   \
            8      2
          /  \    /
        3     5  4
    */

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(4);

    cout<<"Morris Inorder :: "<<endl;
    morris_inorder(root);
    cout<<"\nMorris Preorder: "<<endl;
    morris_preorder(root);


    return 0;
}
