#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next, *random;
    Node(int x){
        data =x;
        next=random= NULL;
    }
};

void print_r(Node *root){

    while(root){
        cout<<root->data<<endl;
        root = root->next;
    }
}

Node* dup(Node *root){

    Node *ori = root;
    Node *tmp = NULL;

    //Add New Node Between
    while(ori){
            tmp = ori->next;
            ori->next = new Node(ori->data);
            ori->next->next = tmp;

            ori= tmp;
    }

    //print_r(root);

    //Set the Random Pointer
    ori = root; tmp = root->next;
    while(ori){
            ori->next->random = ori->random->next;
            ori = ori->next->next;
    }

    //Sergreate
    ori= root; tmp = root->next;
    Node *dup= tmp;
    while(ori && tmp){

            ori->next = ori->next->next;
            ori = ori->next;

            if(tmp->next){
                tmp->next = tmp->next->next;
                tmp= tmp->next;
            }
    }

    return dup;
}

int main(){

    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    //Set Random Pointers // 1-3 // 2-1 //3 4- 5// 5- 2
    start->random = start->next->next;
    start->next->random = start;

    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;

    start->next->next->next->next->random = start->next;

    cout<<"Original List ::"<<endl;
    print_r(start);

    Node *second = dup(start);
    cout<<"Duplicate List :: "<<endl;
    print_r(second);

    return 0;
}
