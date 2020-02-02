#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>


using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};
struct Node *newNode(int key){
    struct Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;

    return node;
}
void getVerticalOrder(Node *root, int h_dist, map <int , vector<int> > &mp){

    if(root==NULL)
        return ;

    mp[h_dist].push_back(root->key);
    //printf("%d\n", root->key);
    getVerticalOrder(root->left, h_dist-1, mp);
    getVerticalOrder(root->right, h_dist+1, mp);

}

void printVerticalOrder(Node *root){
    map<int, vector<int> > mp;
    int h_dist =0;

    getVerticalOrder(root, h_dist, mp);

    map<int, vector<int> >::iterator it;
    for(it= mp.begin(); it!=mp.end(); it++){

            for(int i=0; i<it->second.size(); ++i)
                printf("%d ",it->second[i]);

            printf("\n");
    }
}

int main(){

//    Node *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);

//    root->left->left = newNode(4);
//    root->left->right = newNode(5);

 //   root->right->left = newNode(6);
  //  root->right->right = newNode(7);

   // root->right->left->right = newNode(8);
    //root->right->right->right = newNode(9);


    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    printVerticalOrder(root);


    return 0;
}
