#include <iostream>
using namespace std;

#define MOD 1000000007
bool isPrime[1000000];
int valid[2000][2000];
int ar[2000][2000];
int F[2000][2000];
 int n, m;

void seive () {
    for ( int i = 2; i <= 200000; i ++ ) {
        if ( ! isPrime[i] ) {
            for ( int j = i + i; j <= 200000; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}


int vis[3000][3000];

void print_index ( int i, int j) {
    //cout <<i <<"^"<< j << endl;
    vis[i][j] = 1;
    if (i == 0 and j == 0 )  {
        return;
    }
    if (valid[i-1][j -1]  == 0 and !vis[i-1][j-1]) {
        print_index ( i - 1, j - 1) ;
    }
     if (valid[i-1][j]  == 0 and !vis[i-1][j] ) {
        print_index ( i - 1, j ) ;
    }
     if (valid[i][j -1] == 0 and !vis[i][j-1] ) {
        print_index ( i , j - 1) ;
    }
}

void karo ( int i, int j ) {
    cout << i << " "<<j << endl;
    if ( i== n and j == m ) return;
    if ( vis[i+1][j+1] and !valid[i+1][j+1] ) karo(i+1, j+1);
    else if ( vis[i+1][j] and !valid[i+1][j] ) karo(i+1, j);
    else if ( vis[i][j+1] and !valid[i][j+1] ) karo(i, j+1);
}
int main()
{

    cin >> n >> m;
    for ( int i = 0; i <= n; i++ )
        for ( int j = 0; j <= m; j++ )
            valid[i][j] = 1;
    seive();
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= m; j++ ) {
            int x; cin >> x;
            valid[i][j] = isPrime[x];
        }


    /*
    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= m; j++ ) {
            cout << valid[i][j] <<" ";
        }
        cout <<endl;
    }*/

   // for ( int j = 1; j <= m; j++ ) ar[1][j] = !valid[1][j];

    ar[0][0] = 1;
    valid[0][0] = 0;


    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            long acc = 0;

            if ( valid[i][j] == 1) continue;
            if ( valid[i-1][j-1] ==  0) {
                acc += ar[i-1][j-1];
            }
            if ( valid[i-1][j] == 0 ) {
                acc += ar[i-1][j];
            }
            if ( valid[i][j-1] == 0 ) {
                acc += ar[i][j-1];
            }
            acc %= MOD;
            ar[i][j] = acc;

        }
    }
    cout <<ar[n][m]<<endl;
    if (ar[n][m] == 0 ) return 0;
    print_index(n,m);

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            cout<<valid[i][j]<<"  ";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }

    karo(1,1);
    return 0;

}

//http://ideone.com/OspjDM
