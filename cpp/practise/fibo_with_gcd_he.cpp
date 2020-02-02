#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
/////
void multiply(ll f[][2],ll g[][2])
{
    ll a=(f[0][0]*g[0][0]+f[0][1]*g[1][0])%m;
    ll b=(f[0][0]*g[0][1]+f[0][1]*g[1][1])%m;
    ll c=(f[1][0]*g[0][0]+f[1][1]*g[1][0])%m;
    ll d=(f[1][0]*g[0][1]+f[1][1]*g[1][1])%m;

    f[0][0]=a;
    f[0][1]=b;
    f[1][0]=c;
    f[1][1]=d;
}
void power(ll f[2][2],ll n)
{
    ll g[2][2]={{1,1},{1,0}};
    if(n==0||n==1)
    return;
    power(f,n/2);
    multiply(f,f);

    if(n%2==1)
    multiply(f,g);
}
ll fib(ll n)
{
    ll f[2][2]={{1,1},{1,0}};
    if(n==0)
    return 0;
    power(f,n-1);
    return f[0][0]%m;
}


////
int *st;

// Function to find gcd of 2 numbers.
int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int findGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    int mid = ss+(se-ss)/2;
    return gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}

//Finding The gcd of given Range
int findRangeGcd(int ss, int se, int arr[],int n)
{
    if (ss<0 || se > n-1 || ss>se)
    {
        cout << "Invalid Arguments" << "\n";
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
int constructST(int arr[], int ss, int se, int si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss+(se-ss)/2;
    st[si] = gcd(constructST(arr, ss, mid, si*2+1),
                 constructST(arr, mid+1, se, si*2+2));
    return st[si];
}
int *constructSegmentTree(int arr[], int n)
{
   int height = (int)(ceil(log2(n)));
   int size = 2*(int)pow(2, height)-1;
   st = new int[size];
   constructST(arr, 0, n-1, 0);
   return st;
}

// Driver program to test above functions
int main()
{
    int n,q,l,r;
    int arr[100002];
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    constructSegmentTree(arr,n);
    for(int i=0;i<q;i++){
        cin>>l>>r;
        cout << fib(findRangeGcd(l-1, r-1, arr, n)) << "\n";
    }
    return 0;
}


//http://ideone.com/YYQ2AV
