#include<bits/stdc++.h>

using namespace std;

#define long long long
const long MOD = 1000000007; // modulo
long a,b,c,d;
// map<long, long> F;

// long f(long n) {
// 	if (F.count(n)) return F[n];
// 	long k=n/2;
// 	if (n%2==0) { // n=2*k
// 		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
// 	} else { // n=2*k+1
// 		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
// 	}
// }

void fast_fib(long n,long ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}

int nextPowOfTwo(int n){
    return pow(2, ceil(log(n)/log(2)) );
}

void conST(int arr[], int low, int high, int segTree[], int pos){

    if(low==high){
        segTree[pos]= arr[low];
        return ;
    }

    int mid = low + (high-low)/2;

    conST(arr, low, mid, segTree, 2*pos+1);
    conST(arr, mid+1, high, segTree, 2*pos+2);

    segTree[pos] = __gcd(segTree[2*pos+1], segTree[2*pos+2]);
}

void conSegTree(int arr[], int N, int segTree[], int segLen){

    memset(segTree, 0, segLen*sizeof(int));
    conST(arr, 0, N-1, segTree, 0);

}

int RMQ(int segTree[], int left_query, int right_query, int l, int r, int pos){

        if(left_query<=l && right_query>=r) return segTree[pos];

        if(right_query<l || left_query>r)   return 0;

        int mid = l+(r-l)/2;
        return __gcd(RMQ(segTree, left_query, right_query, l, mid, 2*pos+1), RMQ(segTree, left_query, right_query, mid+1, r, 2*pos+2));
}

int main(){

    int N, Q;
    cin>>N>>Q;
    int arr[N];
    int segLen = 2*nextPowOfTwo(N)-1;
    int segTree[segLen];

    for(int i=0;i<N;i++)
        cin>>arr[i];

    conSegTree(arr, N, segTree, segLen);

    int L,R;
    //F[0]=F[1]=1;
    while(Q--){
        cin>>L>>R;
        //int val = RMQ(segTree,L-1,R-1, 0,N-1,0);
        //printf("%lld\n",RMQ(segTree,L-1,R-1, 0,N-1,0)-1);
        long ans[2]={0};
        //cout<<RMQ(segTree,L-1,R-1, 0,N-1,0)-1<<endl;
        fast_fib(RMQ(segTree,L-1,R-1, 0,N-1,0),ans);
        printf("%lld\n", ans[0]);
    }

    return 0;
}
