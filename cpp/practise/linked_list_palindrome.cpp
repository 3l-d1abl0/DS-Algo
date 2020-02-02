#include<bits/stdc++.h>

using namespace std;

struct node{

    int data;
    node *next;

    node(int num){
        data=num;
        next=NULL;
    }
};


void printList(node *head){

    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void rev(node **head){

    node *curr = *head;
    node *prev = NULL;
    node *next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }

    *head = prev;
}

bool compare(node * p1, node *p2){

    while(p1!= NULL && p2!=NULL){
            if(p1->data != p2->data)
                return false;
            p1= p1->next;
            p2=p2->next;
    }
    return true;
}

bool isPalindrome(node *curr){

    node **head = &curr;

    node *slow_ptr = curr, *fast_ptr = curr;
    node *prev =NULL;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    node *mid_ptr=NULL;
    if(fast_ptr!=NULL){ //odd length
        mid_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        prev->next = NULL;
        //mid_ptr->next=NULL;
    }

    //cout<<"Reversing .... "<<endl;
    rev(&slow_ptr);
    //cout<<"reversed .."<<endl;
    bool res = compare(slow_ptr, *head);

    rev(&slow_ptr);

    if(mid_ptr==NULL){  //list was even
        prev->next = slow_ptr;
    }else{
        prev->next = mid_ptr;
        mid_ptr->next = slow_ptr;
    }

    return res;
}

int main(){

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(6);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(3);
    head->next->next->next->next->next = new node(2);
    head->next->next->next->next->next->next = new node(1);

    printList(head);
    if(isPalindrome(head)){
        cout<<"\nPalindrome !"<<endl;
    }else{
        cout<<"\nNot a Palindrome !"<<endl;
    }
    printList(head);
    return 0;
}
