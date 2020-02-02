#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct Node{

    int data;
    Node *left, *right;

    Node(int num){
        data = num;
        left =right=NULL;
    }
};

void pre_order(Node *root){
    if(root==NULL)
        return;

    cout<<root->data<<"  ";
    pre_order(root->left);
    pre_order(root->right);
}

void pre_morris(Node *root){

        if(root==NULL)
            return ;

        Node *curr= root;
        Node *pre= NULL;

        while(curr!=NULL){

                if(curr->left!=NULL){

                        pre = curr->left;

                        while(pre->right!=NULL && pre->right!=curr)
                            pre=pre->right;

                        if(pre->right==NULL){   //link
                            pre->right = curr;
                            cout<<curr->data<<"  ";
                            curr=curr->left;
                        }else{  //unlink
                            pre->right = NULL;
                            curr= curr->right;
                        }
                }else{
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
//  10 8 3 5 2 2 12

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(12);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right->left = new Node(2);

    pre_order(root);
    cout<<endl;
    pre_morris(root);

    return 0;
}
