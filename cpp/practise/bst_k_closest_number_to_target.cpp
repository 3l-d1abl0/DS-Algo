#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *left, *right;
    Node(int x){
        data =x;
        left=right= NULL;
    }
};

void inOrder(Node *root){

    if(root==NULL) return;

    inOrder(root->left);

    cout<<root->data<<"  ";

    inOrder(root->right);

}

void Kvalues(Node *root,int target,int K, queue<int > &klist){

    if(root==NULL) return;

    Kvalues(root->left, target, K, klist);

    if(klist.size()<K){
        klist.push(root->data);
    }else{

        if(   abs(target- klist.front())  > abs(target-root->data) ){
            klist.pop();
            klist.push(root->data);
        }else{
            return ;
        }
    }

    Kvalues(root->right, target, K, klist);
}

queue<int> closestKvalues(Node *root, int target, int K){

        //list<int > klist = new list<int>[K];
        queue<int > klist ;

        Kvalues(root, target, K, klist);

        return klist;
}

int main(){

    //https://stackoverflow.com/questions/37770216/finding-the-k-closest-numbers-to-a-target-number-in-a-binary-search-tree
    //https://discuss.leetcode.com/topic/41089/inorder-one-linkedlist-java-solution-beat-85

    Node *start = new Node(20);
    start->left = new Node(8);
    start->right = new Node(22);
    start->right->right = new Node(25);

    start->left->left = new Node(4);
    start->left->right = new Node(12);

    start->left->right->left = new Node(10);
    start->left->right->right = new Node(14);

    inOrder(start);

    int K =3;
    int target = 20;
    queue<int > ll = closestKvalues(start, target, K);

    //cout<<endl<<ll.size()<<endl;
    while(!ll.empty()){
        cout<<ll.front()<<"  ";
        ll.pop();
    }
    return 0;
}
