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
void inOrder(struct Node *root){

    if(root == NULL)
        return ;

    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

void inOrder_iterative(struct Node * root){

    if(root == NULL)
        return ;

    stack<struct Node *> s;
    struct Node *curr = root;
    int flag =0;

    while( flag == 0){

        if( curr != NULL){
            s.push(curr);
            curr = curr->left;
        }else{

                if(!s.empty()){

                        struct Node *temp = s.top();
                        printf("%d ", temp->key);
                        s.pop();

                        curr= temp->right;

                }else{
                    flag=1;
                }

        }

    }

}


int main(){

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    inOrder(root);
    cout<<endl<<endl;
    inOrder_iterative(root);

    return 0;
}
