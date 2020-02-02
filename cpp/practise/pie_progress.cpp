#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>

using namespace std;

int c[302][302];

long long solve(int N, int M){
        long long tot=0;
        for(int i=0;i <N; i++){

                long long cst = LLONG_MAX;
                int ele_col, ele_row;


                for(int j=0; j<=i; j++){

                            int prev_cnt=0, min_cost = INT_MAX;
                            for(int jj=0; jj<M; jj++){   if(c[j][jj] == INT_MAX) prev_cnt++;     }

                            int min_ele=c[j][0], tmp_col = 0;

                            for(int x=1; x<M;x++){
                                    if(c[j][x]<min_ele){ min_ele = c[j][x]; tmp_col = x;}
                            }
                            long long cost = min_ele - pow(prev_cnt, 2) + pow(prev_cnt+1, 2);
                            if(cost<=cst){
                                cst = cost;
                                ele_row= j; ele_col = tmp_col;
                            }
                }

                tot += cst;
                c[ele_row][ele_col]= INT_MAX;
        }

        return tot;
}


int main(){

    int T, N, M;

    scanf("%d", &T);

    for(int cs=1; cs<=T; cs++){

            scanf("%d %d", &N, &M);
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        scanf("%d",  &c[i][j]);
                }
            }

        printf("Caase #%d: %lld\n", cs, solve(N, M));
    }

    return 0;
}
