#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int key){

    struct Node *root = new Node;
    root->data = key;
    root->left = root->right = NULL;

   // return root;
}

void preOrder(struct Node *root){

    stack<struct Node *>st;

    while(1){

            while(root){
                    cout<<root->data<<" ";
                    st.push(root);
                    root = root->left;
            }

            if(st.empty()) break;

            root = st.top();    st.pop();
            root= root->right;
    }
}

void preOrder1(struct Node *root){

    if(root == NULL)
        return;

    stack<struct Node *>st;
    st.push(root);

    while(!st.empty()){

            root = st.top();
            st.pop();

            cout<<root->data<<" ";

            if(root->right)
                st.push(root->right);

            if(root->left)
                st.push(root->left);

    }
}

void inOrder(struct Node *root){

    stack<struct Node *> st;

    while(1){

            while(root){
                st.push(root);
                root = root->left;
            }

            if(st.empty())
                break;
            root= st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->right;
    }

}

void postOrder(struct Node *root){

    stack<struct Node *> s1;
    stack<struct Node *>s2;

    s1.push(root);
    while(!s1.empty()){

            root = s1.top();
            s1.pop();

            s2.push(root);

            if(root->left)
                s1.push(root->left);

            if(root->right)
                s1.push(root->right);
    }
    while(!s2.empty()){
                root =s2.top();
                s2.pop();

                cout<<root->data<<" ";
    }
}

int main(){

    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->right->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->left->right->left = newNode(2);

    preOrder(root); cout<<endl;
    //preOrder1(root);
    inOrder(root);cout<<endl;
    postOrder(root);

    return 0;
}
