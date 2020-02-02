#include<iostream>
#include<cstdio>
//#include<stdlib>
#include<algorithm>

using namespace std;

struct node{
    int data;
    struct node* next;
};

void push(struct node** head, int new_data ){

    struct node* new_node= (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}
//Iterative
int getLength(struct node* head){

    int count =0;

    struct node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}
//Recursive
int getCount(struct node* head){

    if(head==NULL)
        return 0;

    return 1+getCount(head->next);
}

int main(){

    struct node* head = NULL;
    //1->2->1>3>1
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    printf("Length :: %d \n", getLength(head));

    printf("Count :: %d \n", getCount(head));

    return 0;
}
