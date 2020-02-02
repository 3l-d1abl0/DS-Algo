    # include <bits/stdc++.h>
    # define s(x) scanf("%d",&x)
    # define l(x) scanf("%lld",&x)
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define ll long long
    #define ms(a,b) memset((a),(b),sizeof(a))
    #define inf 1000000007
    #define f(i,n) for(i=0;i<n;i++)
    #define fa(i,a,b) for(i=a;i<b;++i)
    #define p(x) printf("%d ",x)
    #define pl(x) printf("%lld ", x)
    #define pf(x) printf("%lf ", x)
    #define pn() printf("\n")
    #define pt() printf("test \n")
    #define ps(m) printf("%s\n",m)
    # define vi vector<ll>
    # define vpi vector<pair<ll,ll> >
    # define yes 100005
    ll n,m,k;
    vi prime;
    ll gcd(ll a,ll b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    //ll power(ll a,ll b)
    //{
    //    if(b==0)
    //        return 1;
    //    ll temp=power(a,b/2);
    //    temp=(temp*temp);
    //    if(b&1)
    //        return (temp *a);
    //    return temp;
    //}
    void sieve()
    {
        ll i,j,p=sqrt(yes);
        ll visited[p+2];
        for(i=2;i<p;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                prime.pb(i);
                for(j=i*i;j<p;j+=i)
                    visited[j]=1;
            }
        }
    }
    ll a[yes],fib[yes];
    void multiply(ll F[2][2], ll M[2][2])
    {
        ll x,y,z,w;
       x =  (F[0][0]*M[0][0])%inf + (F[0][1]*M[1][0])%inf;
       y =  (F[0][0]*M[0][1])%inf + (F[0][1]*M[1][1])%inf;
       z =  (F[1][0]*M[0][0])%inf + (F[1][1]*M[1][0])%inf;
       w =  (F[1][0]*M[0][1])%inf + (F[1][1]*M[1][1])%inf;
      F[0][0] = x%inf;
      F[0][1] = y%inf;
      F[1][0] = z%inf;
      F[1][1] = w%inf;
    }
    void power(ll F[2][2], ll p)
    {
      if( p == 0 || p == 1)
          return ;
      ll M[2][2] = {{1,1},{1,0}};
      power(F, p/2);
      multiply(F, F);
      if (p%2)
         multiply(F, M);

    }
    ll func(ll p)
    {

        ll F[2][2] = {{1,1},{1,0}};

          power(F, p-1);
        pl(F[0][0]%inf);


    }
    /* Optimized version of power() in method 4 */
    ll seg_tree[4*yes+10];
    ll construct(ll ss,ll se,ll si)
    {
        if (ss==se)
        {
            seg_tree[si] = a[ss];
            return seg_tree[si];
        }
        ll mid = (ss+se)/2;
        seg_tree[si] = gcd(construct( ss, mid, si*2+1),
                     construct( mid+1, se, si*2+2));
        return seg_tree[si];
    }
    ll findgcd(ll ss,ll se,ll qs,ll qe,ll si)
    {
        if (ss>qe || se < qs)
            return 0;
        if (qs<=ss && qe>=se)
            return seg_tree[si];
        ll mid =(ss+se)/2;
        return gcd(findgcd(ss, mid, qs, qe, si*2+1),
                   findgcd(mid+1, se, qs, qe, si*2+2));
    }
    int main()
    {
        ll t,p,q,r,i,j,x,y,u,ans;
        t=1;
        //l(t);
        while(t--)
        {
            l(n);
           // l(m);
           cin>>p;
           ans=p;
            f(i,n)
            {
                l(p);
                if(p>ans)
                    ans=gcd(ans,p);
                else
                    ans=gcd(p,ans);
            }


    //        f(i,1)
    //        {
    //            l(p);
    //            l(q);
    //            p--;
    //            q--;


                func(ans);

                pn();
           // }
        }
        return 0;
    }
