#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    struct Node* left, *right;

    Node(int key){
        this->key = key;
        this->left = this->right = NULL;
    }
};

class Solution{

private:
    void graphbuild(Node *, Node *, Node *);
    unordered_map<Node *, vector<Node *>> gr;
    Node *startingNode;
public:
    pair<Node *, int> findClosestLeaf(Node *, Node *);
};

void Solution::graphbuild(Node *root, Node *parent, Node *x){

    if(root==NULL)
        return;
    if(root==x) //
        startingNode = x;

    if(parent){
        gr[parent].push_back(root);
        gr[root].push_back(parent);
    }

    graphbuild(root->right, root, x);
    graphbuild(root->left, root, x);

}

pair<Node *, int> Solution::findClosestLeaf(Node *root, Node * x){

    gr.clear();

    //Build the Graph From the Tree
    graphbuild(root, NULL, x);

    //BFS over the created Graph
    queue<Node *> q;
    q.push(startingNode);
    q.push(NULL);

    unordered_set<Node *> visited;
    int dist =0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            Node *curr = q.front(); q.pop();

            if(curr==NULL){
                q.push(NULL); dist++;
                continue;
            }

            visited.insert(curr);

            if(curr->left==NULL && curr->right==NULL)
                return make_pair(curr, dist);

            for (Node *node : gr[curr])
                if(visited.count(node)==0) q.push(node);

        }
    }

    make_pair(NULL, 0);
}

int main(){

        // Let us create Binary Tree shown in above example
    Node *root  = new Node(1);
    root->left  = new Node(12);
    root->right = new Node(13);

    root->right->left   = new Node(14);
    root->right->right  = new Node(15);

    root->right->left->left   = new Node(21);
    root->right->left->right  = new Node(22);
    root->right->right->left  = new Node(23);
    root->right->right->right = new Node(24);

    root->right->left->left->left  = new Node(1);
    root->right->left->left->right = new Node(2);
    root->right->left->right->left  = new Node(3);
    root->right->left->right->right = new Node(4);
    root->right->right->left->left  = new Node(5);
    root->right->right->left->right = new Node(6);
    root->right->right->right->left = new Node(7);
    root->right->right->right->right = new Node(8);

    Node *x = root->right;

    Solution sol;
    pair<Node *, int> Leaf =sol.findClosestLeaf(root, x);
    cout<<"Nearest Leaf :: "<<Leaf.first->key<<" Dist :: "<<Leaf.second<<endl;

    return 0;
}

