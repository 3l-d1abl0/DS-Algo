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

    //head points to the kth Node
    head->next = curr;
    //current & next point to same things//At this Point
    cnt =1;
    while(cnt<=K-1 && curr!=NULL){
        curr= curr->next;
        cnt++;
    }


    if(curr!=NULL)
    curr->next = revG(curr->next, K);

    return prev;

}

int main(){

    Node *list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(5);
    list->next->next->next->next->next = new Node(6);
    list->next->next->next->next->next->next = new Node(7);
    list->next->next->next->next->next->next->next = new Node(8);
    list->next->next->next->next->next->next->next->next = new Node(9);
    list->next->next->next->next->next->next->next->next->next = new Node(10);
    list->next->next->next->next->next->next->next->next->next->next = new Node(11);
    list->next->next->next->next->next->next->next->next->next->next->next = new Node(12);
    list->next->next->next->next->next->next->next->next->next->next->next->next = new Node(13);

    printList(list);
    //rev(&list);

    int K=5;
    Node *head = revG(list, K);

    printList(head);

    return 0;
}

