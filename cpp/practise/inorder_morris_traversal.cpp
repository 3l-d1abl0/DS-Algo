#include<iostream>
#include<cstring>

using namespace std;

struct Node{

    int data;
    Node *right, *left;

    Node(int num){
        data = num;
        right = left = NULL;
    }

};

void inorder(Node *root){

    if(root==NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

void in_morris(Node *root){

    if(root==NULL)
        return ;

    Node *pre=NULL;
    Node *curr= root;

    while(curr!=NULL){

                if(curr->left!=NULL){

                        pre = curr->left;

                        while(pre->right!=NULL && pre->right!=curr)
                            pre=pre->right;

                        if(pre->right ==NULL){  //linking
                            pre->right = curr;
                            curr= curr->left;
                        }else{  //unlink
                            pre->right=NULL;
                            cout<<curr->data<<"  ";
                            curr= curr->right;
                        }

                }else{  //curr->left=NULL

                        cout<<curr->data<<"  ";
                        curr=curr->right;
                }
    }

}

int main(){
//                   10
//                /      \
//            8            2
//          /     \      /
//       3        5  12
//                /
//            2
//  3 8 2 5 10 12 2
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(12);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right->left = new Node(2);

    inorder(root);
    cout<<endl;
    in_morris(root);

    return 0;
}
