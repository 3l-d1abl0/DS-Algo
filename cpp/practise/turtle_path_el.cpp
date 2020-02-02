#include<bits/stdc++.h>

using namespace std;

#define long long long
const long MOD = 1000000007; // modulo

bool isPrime[100002];
int valid[1002][1002];
long wy[1002][1002];
bool visited[1002][1002];

void sieve(){
    memset(isPrime, true, 100001*sizeof(bool));
    // for (int i = 2; i < 100002; i++)
    //     isPrime[i]=true;

    for(int i=2; i*i<100002; i++){
            if ( isPrime[i] ) {
                for (int j= i + i; j <100002; j += i)
                    isPrime[j] = false;
        }
    }
}

void ways(int N, int M){

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){

             if (i==1 && j==1){
                wy[i][j]=1;
                //cout<<wy[i][j]<<"  ";
                continue;
             }
             long tmp =0;
             if (valid[i][j]){

                if(valid[i-1][j-1]) wy[i][j] += wy[i-1][j-1];

                if(valid[i-1][j]) wy[i][j] += wy[i-1][j];

                if(valid[i][j-1]) wy[i][j] += wy[i][j-1];

                //if(i==N && j==M)
                //cout<<wy[i-1][j-1]<<" "<<wy[i-1][j]<<" "<<wy[i][j-1]<<" = "<<wy[i][j]<<wy[i][j]%M<<endl;
             }

             wy[i][j] %=MOD;
        }

    }
    //return wy[N][M];
}

void mark_visits(int N, int M){

    visited[N][M]= true;
    if (N==0 && M==0) return;
    if (valid[N-1][M-1] && visited[N-1][M-1]==false)mark_visits(N-1,M-1);
    if (valid[N][M-1] && visited[N][M-1]==false)mark_visits(N,M-1);
    if (valid[N-1][M] && visited[N-1][M]==false)mark_visits(N-1,M);

}

void print_path(int i, int N, int j, int M){
     printf("%d %d\n",i,j);

     if(i==N && j==M) return;

     if(visited[i+1][j+1])print_path(i+1, N, j+1, M);
     else if(visited[i+1][j])print_path(i+1, N, j, M);
     else if(visited[i][j+1])print_path(i, N, j+1, M);
}

int main(){

    sieve();

    int N,M,num;

    cin>>N>>M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>num;
            valid[i][j] = (int)isPrime[num];
            //cout<<valid[i][j]<<" ";
        }
        //cout<<endl;
    }

    //cout<<endl;
    ways(N,M);
    if(wy[N][M]==0){
        printf("%d\n",wy[N][M]);
        return 0;
    }else{
        printf("%d\n",wy[N][M]);
    }
    mark_visits(N,M);
    print_path(1,N,1,M);

    return 0;
}
