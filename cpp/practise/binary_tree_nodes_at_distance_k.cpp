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

void printDownWard(Node *start, int K){

    if(start==NULL) return;

    if(K==0){
        //cout<<"K = o "<<start->data<<endl;
        printf("%d ",start->data);
        return ;
    }
    printDownWard(start->left, K-1);
    printDownWard(start->right, K-1);
}

int NodesAtDistanceK(Node *start, int target, int K){

    if(start==NULL)
        return 0;

    if(target==start->data){
        //cout<<"Found  => "<<start->data<<endl;
        printDownWard(start->left, K-1);
        printDownWard(start->right, K-1);
        return 0;
    }

    int dl = NodesAtDistanceK(start->left, target, K);
    if(dl != -1){

        if(dl+1==K)
            cout<<start->data<<"  ";
        else
            printDownWard(start->right, K-dl-2);

        return dl+1;
    }

    int dr = NodesAtDistanceK(start->right, target, K);
    if(dr !=-1){

        if(dr+1==K)
            cout<<start->data<<" ";
        else
            printDownWard(start->left, K-dr-2);

        return dr+1;
    }

    return -1;
}

int main(){

    Node *start = new Node(20);
    start->left = new Node(8);
    start->right = new Node(22);
    start->right->right = new Node(25);

    start->left->left = new Node(4);
    start->left->right = new Node(12);

    start->left->right->left = new Node(10);
    start->left->right->right = new Node(14);

//                                20
//                        8                  22
//                4           12                25
//                          10    14



    NodesAtDistanceK(start, 8, 3);

    return 0;
}
