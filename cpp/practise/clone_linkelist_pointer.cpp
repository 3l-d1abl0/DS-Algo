#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;
    Node *random;
    Node(int x){
        data= x;
        next = NULL;
        random = NULL;
    }
};

void printList(Node *start){

    Node *ptr = start;

    while(ptr!=NULL){
        cout<<"data : "<<ptr->data<<" arbit : "<<ptr->random->data<<endl;
        ptr= ptr->next;
    }
}

Node *clone(Node *start){
    cout<<"Clone :: "<<endl;
    Node *ptr = start;

    while(ptr!=NULL){

        Node *dup = new Node(ptr->data);
        dup->next = ptr->next;
        ptr->next = dup;

        ptr = ptr->next->next;
    }

    //cout<<"Dup :: "<<endl;

    ptr = start;
    while(ptr){
        ptr->next->random = ptr->random->next;
        ptr= ptr->next->next;
    }

    //printList(start);

    ptr = start;
    Node *cl = start->next;
    Node *ret = start->next;

    while(ptr && cl){
        ptr->next = ptr->next->next;
        cl->next = (cl->next)?cl->next->next:cl->next;

        ptr= ptr->next;
        cl= cl->next;
    }
    //cout<<"Return"<<endl;
    return ret;
}

int main(){

    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);


    start->random = start->next->next;
    start->next->random = start->next->next->next->next;
    start->next->next->random = start->next->next->next;
    start->next->next->next->random = start;
    start->next->next->next->next->random = start->next;

    cout<<"Original List :: "<<endl;
    printList(start);

    Node *clone_ll = clone(start);
    cout<<"Clone :: "<<endl;
    printList(clone_ll);


    return 0;
}
