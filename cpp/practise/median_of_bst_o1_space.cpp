#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct Node{

    int data;
    Node *left, *right;

    Node(int num){
        data=num;
        right=left=NULL;
    }

};

int count_morris(Node *root){

    if(root==NULL)
        return 0;

    Node *curr = root;
    Node *pre =NULL;

    int cnt = 0;

    while(curr!=NULL){

        if(curr->left == NULL){
                    cnt++;  cout<<curr->data<<"  ";
                    curr=curr->right;
        }else{

                    pre=curr->left;

                    while(pre->right !=NULL && pre->right!=curr)
                        pre=pre->right;

                    if(pre->right=NULL){    //link
                        pre->right =curr;
                        curr=curr->left;
                    }else{      //unlink
                        pre->right = NULL;
                        cout<<curr->data<<"  "; cnt++;
                        curr=curr->right;
                    }

        }

    }

    return cnt;

}

void in_order(Node *root){

    if(root==NULL)
        return;

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
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

    in_order(root); cout<<endl;
    int cnt = count_morris(root);
    cout<<"Count :: "<<cnt<<endl;
    return 0;
}
