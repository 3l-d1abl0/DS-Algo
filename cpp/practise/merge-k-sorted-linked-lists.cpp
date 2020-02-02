#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int num){
        this->data = num;
        next = NULL;
    }
};

void printList(Node *head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
}

Node* merge(Node *a, Node *b){

    Node *result = NULL;

    if(a == NULL)
        return b;

    if(b == NULL)
        return a;

    if(a->data < b->data){
        result = a; result->next = merge(a->next, b);
    }else{
        result = b; result->next = merge(a, b->next);
    }

    return result;
}

Node* mergeKList(Node* arr[], int last){

    while(last!=0){

        int start=0; int end = last;

        while(start<end){

            arr[start] = merge(arr[start], arr[end]);
            start--; end--;

            if(start>=end) last=end;
        }
    }
    //0th index has the result
    return arr[0];

}

int main(){

    int k = 3; // Number of linked lists 
    int n = 4; // Number of elements in each list 

    Node *arr[k];

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(55);
    arr[2]->next->next = new Node(60);
    arr[2]->next->next->next = new Node(76);

    Node *head = mergeKList(arr, k-1);
    cout<<"Printing .. "<<endl;
    printList(head);

    return 0;
}