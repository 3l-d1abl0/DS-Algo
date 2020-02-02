#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *right, *left;

    Node(int num){
        data = num;
        right = left = NULL;
    }

};

void pre_order(Node *root){
    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void pre_iterative(Node *root){

    if(root == NULL)
        return ;

    stack<Node * > s;
    s.push(root);

    while(!s.empty()){

        Node *tmp = s.top();    s.pop();
        cout<<tmp->data<<" ";

        if(tmp->right)
            s.push(tmp->right);

        if(tmp->left)
            s.push(tmp->left);
    }

}

void in_order(Node *root){

    if(root==NULL)
        return ;

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

void in_iterative(Node *root){

    if(root==NULL)
        return ;

    stack<Node *> s;
    Node *curr = root;
    bool flag=true;
    while(flag==true){

            while(curr!=NULL){
                s.push(curr);
                curr= curr->left;
            }

            if(!s.empty()){
                curr = s.top(); s.pop();
                cout<<curr->data<<" ";
                curr= curr->right;
            }else{
                flag= false;
            }
    }
}

void post_order(Node *root){

    if(root==NULL)
        return ;

    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";

}

void post_iterative(Node *root){

    if(root==NULL)
        return ;

    stack<Node * > s1;
    stack<Node * > s2;

    s1.push(root);

    while(!s1.empty()){
        Node *tmp = s1.top();
        s2.push(tmp);   s1.pop();

        if(tmp->left)
            s1.push(tmp->left);

        if(tmp->right)
           s1.push(tmp->right);
    }

    while(!s2.empty()){
        Node *tmp = s2.top();
        s2.pop();
        cout<<tmp->data<<" ";
    }

}

void postorder_oneStack(Node *root){

    if(root==NULL)
        return;

    stack<Node *> s;
    do{

        while(root!=NULL){

            if(root->right)
                s.push(root->right);
            s.push(root);
            root= root->left;
        }

        root = s.top();
        s.pop();

        if(root->right && !s.empty() && root->right == s.top()){
            s.pop();
            s.push(root);
            root= root->right;
        }else{
            cout<<root->data<<"  ";
            root= NULL;
        }

    }while(!s.empty());
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(12);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right->left = new Node(2);

    //pre_order(root);
    cout<<"Preorder :: ";
    pre_iterative(root);
    cout<<endl;

    //in_order(root); cout<<endl;
    cout<<"Inorder :: ";
    in_iterative(root);
    cout<<endl;

    post_order(root);
    cout<<"PostOrder :: ";
    //post_iterative(root);
    postorder_oneStack(root);

    return 0;
}
