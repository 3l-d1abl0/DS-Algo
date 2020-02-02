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

void postorder(struct Node *root){

    if(root == NULL)
        return ;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

void postorder_iterative(struct Node *root){

    if(root == NULL)
            return ;

    stack<struct Node *> s1;
    stack<struct Node *> s2;

    s1.push(root);

    while(!s1.empty()){

        struct Node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty()){
        struct Node * tmp = s2.top();
        printf("%d ", tmp->key);
        s2.pop();

    }
}

int main(){

//    struct Node *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->right->left->right = newNode(8);
//    root->right->right->right = newNode(9);

    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->right->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->left->right->left = newNode(2);


//    printLevelOrder(root);
    //postorder(root);
    cout<<endl<<endl;
    postorder_iterative(root);
    cout<<"+++++"<<endl;

    return 0;
}
