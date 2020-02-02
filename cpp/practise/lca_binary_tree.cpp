#include<bits/stdc++.h>


using namespace std;

struct Node{

    struct Node *left, *right;
    int data;

    Node(int key){
        left = NULL;
        right = NULL;
        data = key;
    }
};

Node *findLca(Node * root, Node *n1, bool *v1, Node *n2, bool *v2){

    if(root== NULL)
        return NULL;

    if(root == n1){
        *v1 = true; cout<<"v1 true"<<endl;
        return root;
    }
    if(root==n2){
        *v2 = true; cout<<"v2 true"<<endl;
        return root;
    }

    Node *left = findLca(root->left, n1, v1, n2, v2);
    Node *right = findLca(root->right, n1, v1, n2, v2);

    if(left != NULL && right != NULL)
        return root;

    if(left == NULL)
        return right;
    else
        return left;

}

bool find(Node * start, Node *n){

    if(start == NULL)
        return false;

    if(start == n || find(start->left, n) || find(start->right, n))
        return true;

    return false;
}
Node *findLcaTree(Node *start, Node *n1, Node *n2){

    bool v1 = false;
    bool v2 = false;

    Node *lca = findLca(start, n1, &v1, n2, &v2);

    if(v1 && v2){
        return lca;
    }else if(v1 && find(lca, n2)){
        return lca;
    }else if(find(lca, n1) && v2){
        return lca;
    }else
        return NULL;
}



int main(){

    Node *start = new Node(20);
    start->left = new Node(8);
    start->right = new Node(22);
    start->right->right = new Node(25);

    start->left->left = new Node(4);
    start->left->right = new Node(12);

    start->left->right->left = new Node(10);
    start->left->right->right = new Node(14);

//                                20
//                        8                  22
//                4           12                25
//                          10    14


    Node *lca = findLcaTree(start, start, start->left->right->right);
    if(lca)
        cout<<lca->data;
    else
        cout<<"Nope "<<endl;
    return 0;

}
