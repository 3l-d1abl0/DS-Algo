#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<utility>
#include<queue>

using namespace std;

struct Node{

    int key;
    struct Node *right, *left;
    int hd;

};

struct Node *newNode(int key){

    struct Node *root =new Node;
    root->key = key;
    root->right = root->left = NULL;
    return root;
}

void getBottomView(struct Node *root){

    int hd=0;

    queue< struct Node *  > q;
    pair< int , int> pr;
    map<int, int> mp;

    q.push( root );
    struct Node *temp;

    cout<<"Starts !! "<<endl;

    while(!q.empty()){

    try{

        temp = q.front();
        q.pop();

        //mp.insert( make_pair(temp->hd, temp->key) );
        mp[temp->hd] = temp->key;

        if(temp->left != NULL){
            temp->left->hd = temp->hd-1;
            q.push(temp->left);
        }

        if(temp->right != NULL){
            temp->right->hd = temp->hd+1;
            q.push(temp->right);
        }

    }catch (exception& e){
        cout << e.what() << '\n';
    }

    }
    cout<<"end"<<endl;

    map<int, int>::iterator it;


    for(it = mp.begin(); it!= mp.end(); it++){

        cout<<it->second<<" ";
    }
    cout<<endl;

}

int main(){

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

    getBottomView(root);

    return 0;
}

