#include<bits/stdc++.h>

using namespace std;

struct node{

    int data;
    node *next;

    node(int num){
        data=num;
        next = NULL;
    }
};

void printList(node *num1){

    while(num1!=NULL){
        cout<<num1->data<<"  ";
        num1= num1->next;
    }
    cout<<endl;
}

node *addSameSize(node *num1, node *num2, int *carry){

    if(num1==NULL){
        cout<<"NUll returning"<<endl;
        return NULL ;
    }

        node *result;
        result->next = addSameSize(num1->next, num2->next, carry);

        int sum = num1->data+num2->data+*carry;
        //pintf("%d %d %d %d \n", sum, num1->data, num2->data,*carry);
        cout<<sum<<" "<<num1->data<<" "<<num2->data<<" "<<*carry<<endl;
        *carry = sum/10;
        cout<<"----"<<endl;
        sum = sum%10;
        cout<<"______"<<endl;
        result->data = sum;
        cout<<"result :: "<<result->data<<endl;

        return result;
}

void addNum(node *num1, int sz1, node *num2, int sz2, node **result){
    int carry =0;

    if(sz1==sz2){
        cout<<"++++++++++++"<<endl;
        *result = addSameSize(num1, num2, &carry);
    }else{

    }

    if(carry){
            node *tp = new node(carry);
            tp->next = *result;
            *result = tp;
    }
}

int main(){

    int ar1[]={9,9,9};  int sz1 = sizeof(ar1)/sizeof(ar1[0]);
    int ar2[]={0,1,8};    int sz2 = sizeof(ar2)/sizeof(ar2[0]);

    //simply prepare the list
    node *num1 = new node(9);
    num1->next = new node(9);
    num1->next->next = new node(9);

    node *num2 = new node(0);
    num2->next = new node(1);
    num2->next->next = new node(8);

    node *result = NULL;

    if(sz1==0)
        printList(num2);
    else if(sz2==0)
        printList(num1);
    else{
            cout<<"--------"<<endl;
        addNum(num1, sz1, num2, sz2, &result);
        printList(result);
    }

    return 0;
}
