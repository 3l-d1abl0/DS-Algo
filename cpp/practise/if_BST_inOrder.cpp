
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<queue>

using namespace std;

struct Node{

    int key;
    struct Node *right, *left;
};

struct Node *newNode(int key){

    struct Node *root = new Node;
    root->key=key;
    root->left = root-> right = NULL;

    return root;
}

void printLevelOrder(struct Node *root){

    if(root== NULL)
        return ;

    queue <struct Node *>qq;
    qq.push(root);

    struct Node *node;

    while(!qq.empty()){

        node = qq.front();
        qq.pop();
        printf("%d ", node->key);

        if(node->left !=NULL)
            qq.push(node->left);
        if(node->right !=NULL)
            qq.push(node->right);


    }
}
static int idx = 0;

void isBSTArr(struct Node *node, int arr[]){

    if(node == NULL)
        return ;

    isBSTArr(node->left, arr);

    arr[idx] = node->key;
    idx++;

    isBSTArr(node->right, arr);
}

bool isBST(struct Node *root){

    static struct Node *prev = NULL;

    if(root){

        if( isBST(root->left) == false )
            return false;

        printf("KEY :: %d ", root->key);

        if(prev!= NULL)
            printf("Prev :: %d\n", prev->key);
        else
            printf("\n");

        if(prev != NULL && root->key < prev->key){
            printf("Key : %d prev: %d \n", root->key, prev->key);
            return false;
        }
        prev = root;

        return isBST(root->right);
    }

    return true;
}


int main(){

//    Node *root = newNode(50);
//    root->left =newNode(30);
//    root->right =  newNode(60);
//
//    root->left->left = newNode(20);
//    root->left->right = newNode(40);
//    root->right->left = newNode(55);
//    root->right->right = newNode(65);
//
//    root->left->right->left = newNode(35);
//    root->left->right->right = newNode(45);
//    root->left->right->right = newNode(50);
//
//    root->left->right->left->left = newNode(31);
//    root->left->right->left->right = newNode(36);
//    root->left->right->right->left = newNode(41);
//    root->left->right->right->left = newNode(45);
//    root->left->right->right->right = newNode(46);
//    root->left->right->right->right = newNode(51);


    Node *root = newNode(40);
    root->left =newNode(35);
    root->right =  newNode(45);

    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->right->left = newNode(44);
    root->right->right = newNode(50);

    root->left->right->left = newNode(22);
    root->left->right->right = newNode(30);

    root->left->right->left->left = newNode(10);
    root->left->right->left->right = newNode(2);
    root->left->right->right->left = newNode(9);
    root->left->right->right->right = newNode(150);



    //printLevelOrder(root);

    //int arr[100];

    printf("\n is BST : %d", isBST(root) );
    //isBSTArr(root, arr);

    //for(int i=1; i<idx ; i++){
    //    if(arr[i]<= arr[i-1]){
    //        cout<<"FALSE\n";
    //        return 0;
    //    }
    //}
    //cout<<"TRUE";

    return 0;
}
