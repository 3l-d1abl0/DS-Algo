#include<bits/stdc++.h>

using namespace std;

struct bst{

    int data;
    bst *left;
    bst *right;

    bst(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};

void inOrder(bst *root){

    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

bst *insert(bst *root, int val){

    if(root==NULL){

        root = new bst(val);
        if(root == NULL){
            cout<<"ERROR : "<<endl;
            return root;
        }

    }else{
        if(root->data > val){
            root->left = insert(root->left, val);
        }else{
            root->right = insert(root->right, val);
        }
    }

    return root;

}

bst *searchBST(bst *root, int val){

    if(root==nullptr)
        return root;

    if(val < root->data){
        return searchBST(root->left, val);
    }else if(val > root->data){
        return searchBST(root->right, val);
    }else{
        return root;
    }

}

/*void swap(bst **a, bst **b){

    bst *c = *a;
    *a = *b;
    *b = c;

}*/

void swap(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;
}


void customInOrder(bst *root, bst **first, bst **middle, bst **last, bst **prev){

    if(root){

        customInOrder(root->left, first, middle, last, prev);
        //
        if(*prev && root->data < (*prev)->data){

            if( *first == nullptr){
                *first = *prev;
                *middle = root;
            }else{
                *last = root;
            }

        }
        *prev = root;
        //
        customInOrder(root->right, first, middle, last, prev);

    }

}

void bstCorrect(bst *root){

    bst *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    customInOrder(root, &first, &middle, &last, &prev);

    if(first && last){
        swap( &(first->data), &(last->data));
    }else if(first && middle){
        swap( &(first->data), &(middle->data));
    }

}

void testCase(int arr[], int sz, bst *root, int cases){

    bst *p1 = nullptr;
    bst *p2 = nullptr;

    for(int i=0; i<cases; i++){

        cout<<"Test Case #"<<i<<endl;

        int val1 = arr[rand()%sz];
        int val2 = arr[rand()%sz];

        p1 = searchBST(root, val1);
        p2 = searchBST(root, val2);

        if(p1 && p2){
            //cout<<p1->data<<endl;
            //cout<<p2->data<<endl;

            swap(&(p1->data), &(p2->data));
            inOrder(root); cout<<endl;


            bstCorrect(root);
            inOrder(root);
            cout<<endl;
        }

    }

}

int main(){


    bst* root = NULL;

    int arr[] = { 10, 5, 15, 3, 7, 8, 20, 25 };

    int i, size = sizeof( arr ) / sizeof( *arr );


    for( i = 0; i < size; ++i )
        root = insert( root, arr[i] );


    printf( "Original tree\n");
    inOrder( root );


    int test_Cases_sz = 10;

    testCase( arr, size, root, test_Cases_sz );

    return 0;


}
