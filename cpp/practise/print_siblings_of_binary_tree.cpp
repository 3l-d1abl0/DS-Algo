#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

void printCousins(Node *root, Node * target){

    if (root == target) {
        cout << "No Nodes !!!" << endl;
        return;
    }

    queue<Node *>q;

    q.push(root);
    bool found = false;

    while(!q.empty() && found ==false){

        int sz = q.size();
        while(sz--){

            Node *tmp = q.front();
            q.pop();

            if(tmp->left == target || tmp->right == target){
                found=true;
            }else{
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }

            //sz--;
        }

    }//While

    if(found){

        cout<<"Cousin Nodes :: "<<endl;

        int sz = q.size();

        if(sz==0)
            cout<<"No Cousin "<<endl;
        else{

            for(int i=0; i<sz; i++){
                Node * tmp = q.front();
                q.pop();

                cout<<tmp->data<<" : ";
            }
        }

    }else{
        cout<<"Element Not Found !!"<<endl;
    }

    cout<<endl;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    //            1
    //        2       3
    //      4   5   6    7
    //           15   8
    //
    //
    //

    Node* x = new Node(43);

    printCousins(root, x);
    printCousins(root, root);
    printCousins(root, root->right);
    printCousins(root, root->left);
    printCousins(root, root->left->right);

    return 0;

}
