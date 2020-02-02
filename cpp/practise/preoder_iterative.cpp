#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

struct Node {

    int key;
    struct Node * right, *left;

};
struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key =key;
    root->left = root->right = NULL;

    //return NULL;
}
void printLevelOrderNewLine(struct Node *root){
    if(root == NULL)
        return;

    queue<struct Node *> qq;
    qq.push(root);
    struct Node *temp;
    while(!qq.empty()){

        int node_num = qq.size();
        cout<<"SZ :: "<<node_num<<endl;
        if(node_num ==0)
            return;
        for(int i=0;i<node_num; i++){

                temp = qq.front();
                qq.pop();
                printf("%d ", temp->key);
                if(temp->left!= NULL)
                    qq.push(temp->left);

                if(temp->right!= NULL)
                qq.push(temp->right);

        }
        cout<<endl;
    }
}

void preorder_iterative(struct Node *root){

    if(root == NULL)
        return;

    stack<struct Node *> s;
    s.push(root);

    while(!s.empty()){

        struct Node *temp = s.top();
        printf("%d ", temp->key);

        s.pop();

        if(temp->right)
            s.push(temp->right);

        if(temp->left)
            s.push(temp->left);
    }

}


void pre_order(Node *root){

    if(root==NULL)
        return;

    cout<<root->key<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
int main(){

    /*
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    */

    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->right->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->left->right->left = newNode(2);

    pre_order(root);

//    printLevelOrder(root);
    cout<<endl<<endl;
    preorder_iterative(root);

    return 0;
}
