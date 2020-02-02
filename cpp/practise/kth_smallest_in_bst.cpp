#include<iostream>
#include<cstring>


using namespace std;

struct Node{

    int data;
    Node *left, *right;

    Node(int num){
        data= num;
        left= right = NULL;
    }
};

void in_order(Node *root){

    if(root==NULL)
        return ;

    in_order(root->left);
    cout<<root->data<<"  ";
    in_order(root->right);

}

Node *kth_morris(Node *root, int K){

    if(root==NULL)
        return NULL;

    int ctr=0;

    Node *curr = root;
    Node *pre = NULL;
    Node *kth = NULL;

    while(curr!=NULL){

        if(curr->left!=NULL){

            pre = curr->left;

            while(pre->right!=NULL && pre->right!=curr)
                pre=pre->right;

            if(pre->right==NULL){   //link
                    pre->right = curr;
                    curr=curr->left;
            }else{  //unlink
                pre->right=NULL;
                cout<<curr->data<<"  ";
                ctr++;
                if(ctr==K){
                    kth = curr;
                    cout<<" Found ";
                }
                curr=curr->right;
            }
        }else{
            cout<<curr->data<<" ";
            ctr++;
            if(ctr==K){
                kth = curr;
                cout<<" Found ";
            }
            curr = curr->right;
        }

    }

    return kth;
}

int main(){

//                   50
//                /        \
//            40          60
//          /     \         /   \
//       30      45   55   70
//
    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->right = new Node(45);
    root->right->left = new Node(55);
    root->right->right = new Node(70);

    //in_order(root);
    int K=4;
    cout<<endl<<"[ "<<K<<" ] = "<<kth_morris(root, K)->data<<endl;
    return 0;
}
