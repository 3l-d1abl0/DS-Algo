#include<bits/stdc++.h>

using namespace std;


void bfs(int limit, int num){

    queue<int> q;
    q.push(num);


    while(!q.empty()){

            int seed = q.front();
            q.pop();

            if(seed <= limit){
                cout<<seed<<" ";
                int last_num = seed%10;

                if(last_num ==0){
                    q.push( (seed*10)+(last_num+1) );
                }else if(last_num ==9){
                    q.push(  (seed*10)+(last_num-1)  );
                }else{
                    q.push(  (seed*10)+(last_num+1)  );
                    q.push(  (seed*10)+(last_num-1) );
                }
            }
    }

}


int main(){

    int limit =40;

    for(int i=0; i<=9; i++){
        bfs(limit, i);
    }


    return 0;
}
