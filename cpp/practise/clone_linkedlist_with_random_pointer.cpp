#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;
    Node *random;

    Node(int num){
        data = num;
        next = NULL;
        random = NULL;
    }
};


void print(Node * start){

    Node *ptr = start;
    while(ptr){

        cout<<"Data = "<<ptr->data<<" Random = "<<ptr->random->data<<endl;
        ptr= ptr->next;
    }

}

Node *clone(Node *start){

    Node * curr = start, *temp;

    while(curr){
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr=temp;
    }

    curr= start;
    //point the random
    while(curr){
        curr->next->random = curr->random->next;

        curr->next = curr->next?curr->next->next:curr->next;
    }

    //Segregate the two list
    Node *original = start , *cpy = start->next;
    temp =cpy;

    while(original && cpy){

        original->next = original->next?original->next->next:original->next;
        cpy->next = cpy->next?cpy->next->next:cpy->next;

        original = original->next;
        cpy = cpy->next;
    }
    return temp;
}

int main(){

    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    //Adding Random Pointers
    //1->3
    start->random = start->next->next;
    //2->1
    start->next->random = start;
    //3 & 4 ->5
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;
    //5 -> 2
    start->next->next->next->next->random = start->next;

    cout<<"Original :: "<<endl;
    print(start);

    cout<<"Cloned :: "<<endl;
    Node *cloned = clone(start);
    print(cloned);

    return 0;
}
