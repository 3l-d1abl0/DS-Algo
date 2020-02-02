#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#include<queue>

using namespace std;

struct Node {
    int key;
    struct Node *right, *left;
};

struct Node *createBST(int arr[], int st, int en){
    if(st> en)
        return NULL;

    int mid = (st + en)/2;

    struct Node *root = new Node;
    root->key = arr[mid];

    root->left = createBST(arr, st, mid-1);
    root->right = createBST(arr, mid+1, en);

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

int main(){

    int arr[] ={1,2,3,4,5,6,7,8,9,10};

    int sz = sizeof(arr)/sizeof(int);

    struct Node *root = createBST(arr, 0, sz-1);

    printLevelOrder(root);

    return 0;
}
