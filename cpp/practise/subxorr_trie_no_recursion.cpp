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

int query_num(node *root, unsigned int num, unsigned int K){

        int ans =0;
        for(int i=MSB-1; i>=0; i--){

            unsigned int kk = ((K>>i)&1);
            unsigned int nn = ((num>>i)&1);

            if(kk==0){
                        if(nn==0){
                            if(root->left)
                                root= root->left;
                            else
                                return ans;
                        }else{  //nn==1
                            if(root->right)
                                root = root->right;
                            else
                                return ans;
                        }
            }else{  //kk==1
                    if(nn==0){
                        ans +=root->left_c;
                        if(root->right)
                            root=root->right;
                        else
                            return ans;
                    }else{
                        ans+= root->right_c;
                        if(root->left)
                            root = root->left;
                        else
                            return ans;
                    }
            }
            return ans;
        }//for

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
            ans+= query_num(root, pre_xor,K);
            insert_num(root, pre_xor);
     }
        printf("%lld\n", ans);
    }

    return 0;
}
