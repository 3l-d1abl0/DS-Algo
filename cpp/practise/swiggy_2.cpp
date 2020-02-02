#include<bits/stdc++.h>

using namespace std;

int mat[1002][1002];
int N,M;

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};

struct Node{
  int x; int y;
};

bool mark(Node coor) {
	if(coor.x == -1 && coor.y == -1)
    return true;
	else
    return false;
}

bool limit(int x, int y) {

	if(x < 0 || y < 0 || x >= N || y >= M)
    return false;
	else
    return true;
}


int main(){
  cin>>N>>M;
  queue<Node> Q;

  Node coor;
  for(int i=0; i<N; i++)
    for(int j=0; j<M;j++){
      cin>>mat[i][j];
      if(mat[i][j]==2){
        coor.x = i; coor.y = j;
        Q.push(coor);
      }
    }
    coor.x=-1; coor.y=-1;
    Q.push(coor);
    int ans=0;
    //===================================
	while(!Q.empty()) {

		bool flag = false;

		while(!mark(Q.front())) {

			coor = Q.front();

      for(int i=0; i<=3; i++){

        if( limit(coor.x+x[i], coor.y+y[i]) && mat[coor.x+x[i]][coor.y+y[i]]==1 ){

          if(!flag){
            flag=true;
            ans++;
          }
          mat[coor.x+x[i]][coor.y+y[i]]=2;
          Node newx;
          newx.x = coor.x+x[i]; newx.y=coor.y+y[i];
          Q.push(newx);
        }//if

      }//for

			Q.pop();
		}//while mark

		Q.pop();

		if(!Q.empty()) {
			coor.x = -1; coor.y = -1;
			Q.push(coor);
		}
	}//while

 bool flag= true;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(mat[i][j]==1){
        flag=false;
        break;
      }
    }
  }

 if(flag==true)
  cout<<ans<<endl;
else
  cout<<"0"<<endl;

    //===================================
  return 0;
}
