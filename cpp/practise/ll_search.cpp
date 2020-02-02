#include<iostream>
#include<cstdio>
//#include<cstdlib>
#include<algorithm>

struct node{

    int data;
    struct node *next;
};

void push(struct node **head, int data){

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next= (*head);

    (*head) = new_node;
}

bool ele_search(struct node * head, int target){

    struct node * curr= head;
    while(curr!=NULL){
        if(curr->data== target)
            return true;
        curr = curr->next;
    }

    return false;
}

bool rec_search(struct node * head, int target){

    struct node *curr = head;

    if(head==NULL)
        return false;
    else if(head->data==target)
        return true;
    else
        rec_search(head->next, target);
}

using namespace std;
 int main(){

    struct node *head = NULL;

    //1->2->1>3>1
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    if(ele_search(head, 22)){
        printf("FOUND\n");
    }else{
        printf("NO\n");
    }

    if(rec_search(head, 22)){
        printf("*FOUND\n");
    }else{
        printf("*NO\n");
    }


    return 0;
 }
