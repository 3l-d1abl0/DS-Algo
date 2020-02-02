#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[1000010];
class node
{
     public:
      node *lt,*rt;
      int sub;
      node()
      {
           lt=NULL;
           rt=NULL;
           sub=0;
   }
};
void insert(node *root,ll val)
{
     for(int i=5;i>=0;i--)
     {
           if(val>>i&1)
           {
                  if(root->rt==NULL)
                  {
                        root->rt=new node();
        }
        root=root->rt;
        root->sub++;
     }
     else
     {
                 if(root->lt==NULL)
        {
              root->lt=new node();
        }
        root=root->lt;
        root->sub++;
     }
  }
}
ll query(node *root,ll val,ll K)
{
 ll ret=0;
         for(int i=5;i>=0;i--)
         {
               int v=val>>i&1;
      int k=K>>i&1;
      node *temp;
      if(v==1 && k==0)
      {     cout<<"v=1 && k=0"<<endl;
            temp=root->lt;
        if(temp!=NULL)
        {
            ret+=temp->sub;
        cout<<"ad ledt subtree "<<endl;
        }
        if(root->rt!=NULL)
        {
          root=root->rt;
         cout<<"go to rt "<<endl;
        }
        else
        {
         cout<<"direct ret "<<endl;
                  return ret;
        }
      }
      else if(v==1 && k==1)
      { cout<<"v=1 && k=1"<<endl;
              if(root->lt!=NULL)
        {
        cout<<"only option go to lt "<<endl;
           root=root->lt;
        }
        else
        {
        cout<<"return ret "<<endl;
         return ret;
           }
      }
      else if(v==0 && k==0)
      {
          cout<<"v=0 && K=0"<<endl;
              temp=root->rt;
              if(temp!=NULL)
              {
                 cout<<"add values on rt subtree "<<endl;
                   ret+=temp->sub;
          }
          if(root->lt!=NULL)
          {
            cout<<"go to lefct "<<endl;
                 root=root->lt;
          }
          else
          {
          cout<<"else  return ret ="<<ret<<endl;
          return ret;
           }
      }
      else
      {         cout<<"v=0 && k=1"<<endl;
               if(root->rt!=NULL)
               {
                       cout<<"tru and go to rt "<<endl;
                        root=root->rt;
                }else{
                        cout<<"elset return ret  ="<<ret<<endl;
                        return ret;
                }
      }
      if(i==0)
      {
           ret+=root->sub;
           cout<<"i=0    ret = "<<ret<<endl;
       }
   }
   return ret;
}
int main()
{
    int n;
    cin>>n;
    ll k;
    cin>>k;
    node *root=new node();
    for(int i=1;i<=n;i++)
    {
       scanf("%lld",&a[i]);
    }
    insert(root,0);
  //  cout<<" inserted "<<endl;
    int pre=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
             cout<<pre<<" ^ "<<a[i]<<endl;
             pre=pre^a[i];
             cout<<"Querying ... "<<pre<<endl;
             ans+=query(root,pre,k);

            cout<<"INserting .."<<pre<<endl<<endl;
            insert(root,pre);
    }
    cout<<ans<<endl;
}
