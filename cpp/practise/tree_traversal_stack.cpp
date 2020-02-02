#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;

    Node(int num){
        data=num;
        right = NULL;
        left = NULL;
    }
};

void iterativePreorder(Node *root){

    if (root==NULL)
        return;

    stack<Node *> st;

    while(1){
        while(root){
            cout<<root->data<<" ";
            st.push(root);
            root=root->left;
        }

        if(st.empty())
            break;
        root= st.top();
        st.pop();

        root=root->right;
    }
}

void iterativeInorder(Node *root){

    if(root==NULL)
        return;
    stack<Node *> st;
    while(true){

        while(root){
            st.push(root);
            root= root->left;
        }

        if(st.empty())
            break;
        root=st.top();  st.pop();
        cout<<root->data<<" ";
        root= root->right;
    }
}

void iterativePostorder(Node *root){

  if(root==NULL)
    return ;

  stack<Node *>st;

  do{

    while(root){

        if(root->right)
            st.push(root->right);

        st.push(root);
        root=root->left;
    }

    root = st.top();   st.pop();

    if(root->right && root->right == st.top() ){

        st.pop();
        st.push(root);
        root=root->right;
    }else{//LeafNode
        cout<<root->data<<" ";
        root=NULL;
    }

  }while(!st.empty());

}

///////////////////////////////////////
void iterative_preorder(Node *root){

    stack<Node *> st;
    st.push(root);

    while(!st.empty()){

        Node *temp = st.top();
        st.pop();
        cout<<temp->data<<" ";

        if(temp->right)
            st.push(temp->right);

        if(temp->left)
            st.push(temp->left);
    }

}

void iterative_inorder(Node *root){

    stack<Node *>st;

    bool flag= true;

    Node *curr = root;
    while(flag){

        if(curr){
            st.push(curr);
            curr= curr->left;
        }else{

            if(!st.empty()){

            curr = st.top();
            cout<<curr->data<<" ";
            st.pop();
            curr = curr->right;
            }else{
                flag=false;
            }
        }


    }
}

void iterative_postorder(Node *root){

    stack<Node *>s1;
    stack<Node *>s2;

    s1.push(root);

    while(!s1.empty()){
        Node * temp = s1.top();
        s1.pop();
        s2.push(temp);


        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);


    }

    while(!s2.empty()){
        Node * temp = s2.top();
        cout<<temp->data<<" ";
        s2.pop();
    }
}

void iterative_postorder_onestack(Node * root){

    if(root==NULL)
        return ;

    stack<Node *> st;

    do{

        while(root!=NULL){

            if(root->right)
                st.push(root->right);
            st.push(root);
            root=root->left;

        }

        root = st.top();
        st.pop();


        if(root->right && !st.empty() && root->right == st.top()){
            st.pop();
            st.push(root);
            root= root->right;
        }else{
            cout<<root->data<<" ";
            root= NULL;
        }


    }while(!st.empty());
}

int main(){

    /* Constructed binary tree is
                10
              /   \
            8      2
          /  \    /
        3     5  4


    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(4);

    cout << "\nPreorder : "<<endl;
    iterativePreorder(root);
    cout<<"\nInorder : "<<endl;
    iterativeInorder(root);
    cout<<"\nPostORder : "<<endl;
    iterativePostorder(root);
    */

    /*
                20
            /       \
            8       22
           / \     /
          4   12  21
             /  \
            10   14


    */

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(4);
    root->left->right = new Node(12);

    root->right->left = new Node(21);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);


    cout<<"Iterative Preorder :: "<<endl;
    iterative_preorder(root); cout<<endl;

    cout<<"Iterative Inorder :: "<<endl;
    iterative_inorder(root); cout<<endl;

    cout<<"Iterative PostOrder :: "<<endl;
    iterative_postorder(root); cout<<endl;

    cout<<"Iterative PostOrder "<<endl;
    iterative_postorder_onestack(root);


    return 0;
}
