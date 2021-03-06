#include<cstdio>
#include<iostream>
#include<cstdlib>
#define sd(n) scanf("%d",&n)
typedef long long LL;
typedef struct ll
{
    int leftc;
    int rightc;
    struct ll * left;
    struct ll * right;
}node;
node * insert(node * root, unsigned int n, int level){
    if(level==-1)return root;
    unsigned int x=((n>>level)&1);
    if(x)
    {
        root->rightc++;
        if(root->right==NULL)
        {
            root->right=(node *)malloc(sizeof(node));
            root->right->leftc=root->right->rightc=0;
        }
        root->right=insert(root->right,n,level-1);
    }
    else
    {
        root->leftc++;
        if(root->left==NULL)
        {
            root->left=(node *)malloc(sizeof(node));
            root->left->leftc=root->left->rightc=0;
        }
        root->left=insert(root->left,n,level-1);
    }
    return root;
}
unsigned int query( node * root, unsigned int n, int level, unsigned int k)
{
    if(level==-1 || root==NULL)return 0;
    unsigned int p=((n>>level)&1);
    unsigned int q=((k>>level)&1);
    if(q)
    {
        if(p==0)return root->leftc+query(root->right,n,level-1,k);
        else return root->rightc+query(root->left,n,level-1,k);
    }
    else
    {
        if(p==0)
            return query(root->left,n,level-1,k);
        else
            return query(root->right,n,level-1,k);
    }
}
int main()
{
    int t;
    sd(t);
    while(t--)
    {
        node * root;
        root=(node *)malloc(sizeof(node));
        root->left=root->right=NULL;
        root->leftc=root->rightc=0;
        root=insert(root,0,20);
        unsigned int n,i,j,p=0,x,q,k;
        long long int ans=0;
        scanf("%u%u",&n,&k);
        for(i=0; i<n; i++)
        {
            scanf("%u",&x);
            q=p^x;
            ans+=(LL)(query(root,q,20,k));
            root=insert(root,q,20);
            p=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
