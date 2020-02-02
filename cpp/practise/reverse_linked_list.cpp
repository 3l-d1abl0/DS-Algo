#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;
    Node(int x){
        data =x;
        next=NULL;
    }
};

Node *rev(Node **head){

    Node *prev = NULL;
    Node * curr = *head;
    Node *next;

    while(curr){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }

    *head = prev;

}

void printList(Node *head){

    while(head){
            cout<<head->data<<"  ";
            head=head->next;
    }

    cout<<endl;
}

void revRev(Node *prev, Node *curr, Node ** head){

    if(curr->next == NULL){

        curr->next = prev;
        *head = curr;
        return;
    }

    Node * next = curr->next;
    curr->next= prev;
    revRev(curr, next, head);
}

void recursiveRev(Node **head){
        revRev(NULL,*head,head);
}

int main(){

    Node *list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(5);

    printList(list);
    //rev(&list);

    recursiveRev(&list);

    printList(list);

    return 0;
}
