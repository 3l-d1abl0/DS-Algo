#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>


using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};

// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void printNodeDown(struct node *root, int K){

    if(root == NULL )
        return;
//cout<<root->data<<"<--> "<<K<<endl;
    if(K==0){
        cout<<root->data<<"--> "<<K<<endl;
        //cout<<"Here"<<endl;
        return ;
    }

    printNodeDown(root->left, K-1);
    printNodeDown(root->right, K-1);
}

int printkdistanceNode(struct node *root, struct node *target, int K){


    if(root == NULL)
        return -1;
    //cout<<" :: "<<root->data<<" <"<<K<<">"<<endl;

    if(root == target){
        //cout<<"root ::"<<K<<endl;
        printNodeDown(root, K);
        return 0;
    }

    int dl= printkdistanceNode(root->left, target, K);

    if(dl !=-1){

        if(dl+1 == K)
            cout<<root->data<<endl;
        else
            printNodeDown(root->right, K-dl-2);

        return 1+dl;
    }

    dl = printkdistanceNode(root->right, target, K);

    if(dl != -1){

            if(dl+1 == K)
                cout<<root->data<<endl;
            else
                printNodeDown(root->left, K-dl-2);

        return 1+dl;
    }
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
