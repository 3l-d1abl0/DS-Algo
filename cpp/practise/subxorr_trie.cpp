#include<bits/stdc++.h>
#define MSB 32
using namespace std;

struct node{
    int left_c;
    int right_c;
    node *left;
    node *right;

    node(){
        left_c=0; right_c=0;
        left=NULL; right=NULL;
    }
};

void insert_num(node *root, unsigned num){

    for(int i=MSB-1; i>=0; i--){
        unsigned int bit = ((num>>i)&1);
        if(bit ==1){
            root->right_c++;
            if(root->right==NULL)
                root->right = new node;
            root = root->right;
        }else{
            root->left_c++;
            if(root->left == NULL)
                root->left = new node;
            root = root->left;
        }

    }

}

int query_num(node *root, unsigned int num, unsigned int K, int level){

    if(level ==-1|| root == NULL) return 0;

        unsigned int kk = ((K>>level)&1);
        unsigned int nn = ((num>>level)&1);

        if(kk==0){
                if(nn==0){
                    return query_num(root->left, num,K, level-1);
                }else{  //nn==1
                    return query_num(root->right, num, K, level-1);
                }
        }else{  //kk==1
            if(nn==0){
                    return root->left_c + query_num(root->right, num, K, level-1);
            }else{  //nn==1
                    return root->right_c+ query_num(root->left, num, K, level-1);
            }
        }

}

int main(){

    int t;
    scanf("%d", &t);
    while(t--){

    unsigned int N,K,num, pre_xor;
     scanf("%u %u", &N,&K);
     //cout<<N<<K<<endl;
    pre_xor =0;
    node *root = new node;
    insert_num(root, pre_xor);
    long long int ans =0;
     for(int i=0; i<N;i++){
            scanf("%u",&num);
            pre_xor = pre_xor ^num;
            ans+= query_num(root, pre_xor,K, MSB-1);
            insert_num(root, pre_xor);
     }
        printf("%lld\n", ans);
    }

    return 0;
}
