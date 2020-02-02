#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next, *random;
    Node(int x){
        data =x;
        next=random= NULL;
    }
};

void print_r(Node *root){

    while(root){
        cout<<root->data<<endl;
        root = root->next;
    }
}

Node* dup(Node *root){

        map<Node *, Node *> mp;
        Node *ori = root;
        Node *dup;
        //Get the Counter Part Node;
        while(ori){

                dup = new Node(ori->data);
                mp.insert(pair<Node *, Node *> (ori, dup));
                ori= ori->next;
        }

        //Clone via hash
        map<Node *, Node *>::iterator it;
        ori = root;

        while(ori){

                it = mp.find(ori);
                dup = it->second;   //node

                dup->next = mp.find(ori->next)->second;

                dup->random = mp.find(ori->random)->second;

                ori=ori->next;
        }

        dup->next = NULL;

        return mp.find(root)->second;
}

int main(){

    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    //Set Random Pointers // 1-3 // 2-1 //3 4- 5// 5- 2
    start->random = start->next->next;
    start->next->random = start;

    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;

    start->next->next->next->next->random = start->next;

    cout<<"Original List ::"<<endl;
    print_r(start);

    Node *second = dup(start);
    cout<<"Duplicate List :: "<<endl;
    print_r(second);

    return 0;
}
