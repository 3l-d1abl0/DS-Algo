#include<stdio.h>
#include<cstring>
#include<iostream>

using namespace std;

// Tree Node structure
struct node1
{
    int data;
    struct node1 *left, *right;
};
// Doubly Linked List Node Structure
struct node2{

    int data;
    struct node2 *nxt;
    struct node2 *prev;
};

typedef struct node1 tnode;
typedef struct node2 lnode;


// New Tree Node
tnode* newTNode( int data )
{
    tnode* temp = (tnode *) malloc( sizeof(tnode) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// New Linked List Node
lnode*  newLNode( int data )
{
    lnode* temp = (lnode *) malloc( sizeof(lnode) );
    temp->data = data;
    temp->nxt = temp->prev = NULL;
    return temp;
}

// Vertical sum routine
void vertical_sum(tnode * root , lnode* llnode){
    if(!root)
    return ;
    // Add root's data to current linked list node
    llnode->data+= root->data;

    //If tree has left child
    if(root->left){
        //If some node at this horizontal
        //distance already occured , Simply pass
        //Already created node
        if(llnode->prev){
            vertical_sum(root->left, llnode->prev);
        }
        else{
        // Create new node
        lnode* ltmp = newLNode(0);
        ltmp->nxt = llnode;
        llnode->prev = ltmp;
        vertical_sum(root->left,ltmp);
        }
    }
    // Do similar as above
     if(root->right){
        if(llnode->nxt){
            vertical_sum(root->right, llnode->nxt);
        }
        else{
        lnode* ltmp = newLNode(0);
        ltmp->prev = llnode;
        llnode->nxt = ltmp;
        vertical_sum(root->right,ltmp);
        }
    }



}


int main(){

    tnode *root = newTNode(20);
    root->left = newTNode(8);
    root->left->left  = newTNode(4);
    root->left->right = newTNode(12);
    root->left->right->left  = newTNode(10);
    root->left->right->right = newTNode(14);
    root->right = newTNode(22);
    root->right->right = newTNode(25);

    lnode * llnode = newLNode(0);
    vertical_sum(root, llnode);

    lnode *head = llnode;
    // Find the head of the linked list
    while(head->prev!=NULL)
        head= head->prev;
    // Print linked list
    while(head){
        cout<<head->data<<"   ";
        head = head->nxt;
       }




return 0;
}
