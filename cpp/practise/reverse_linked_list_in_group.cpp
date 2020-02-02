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
void printList(Node *head){

    while(head){
            cout<<head->data<<"  ";
            head=head->next;
    }

    cout<<endl;
}

Node *rev(Node *head){

    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *revG(Node *head, int K){

    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    int cnt =0;
    //cout<<curr->data<<endl;
    while(curr!=NULL && cnt<K){
            next=curr->next;
            curr->next = prev;
            prev= curr;
            curr= next;
            cnt++;
    }

    if(curr!=NULL)
    head->next = revG(curr, K);

    return prev;

}

int main(){

    Node *list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(5);

    printList(list);
    //rev(&list);

    int K=3;
    Node *head = revG(list, K);
    //Node *head = rev(list);

    printList(head);

    return 0;
}
