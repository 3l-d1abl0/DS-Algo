#include<bits/stdc++.h>

using namespace std;

int T;
int X,Y,Z;
int mat[101][101][101];

int xx[]={-1,0,1,0,0,0};
int yy[]={0,1,0,-1,0,0};
int zz[]={0,0,0,0,-1,1};

bool limit(int i, int j, int k) {
	if(i < 0 || j < 0 || k<0 || i >=X || j >=Y || k>=Z)
		return false;
	else
	  return true;
}
struct Node{
    int x,y,z;
};

int dfs(Node coor, int cnt){

    mat[coor.x][coor.y][coor.z]=1;

    if(coor.x ==0 || coor.x==X-1 || coor.y==0 || coor.y==Y-1 || coor.z==0 || coor.z==Z-1 ) return -1;
    if(cnt!=-1) cnt+=1;


		for(int i=0; i<=5; i++){
			//cout<<"i="<<i<<endl;

			if( limit(coor.x+xx[i], coor.y+yy[i], coor.z+zz[i]) && mat[coor.x+xx[i]][coor.y+yy[i]][coor.z+zz[i]]==0 ){
				Node newx;
				newx.x = coor.x+xx[i]; newx.y=coor.y+yy[i]; newx.z=coor.z+zz[i];
				//cout<<"Calling dfs.."<<endl;
				int temp = dfs(newx, cnt);
				if(cnt!=-1)
				 cnt=temp;
			}
		}


    return cnt;
}


int main(){

    cin>>T;
    while(T--){
        cin>>X>>Y>>Z;
				queue<Node> Q;
        for(int i=0; i<Z; i++){
            for(int j=0; j<X; j++){
                for(int k=0; k<Y; k++){
                    cin>>mat[j][k][i];
                    if(mat[j][k][i]==0){
											Node coor;
                        coor.x =j; coor.y =k; coor.z =i;
                        Q.push(coor);
                    }
                }//k
            }//j
        }//i

				////////////////
				long long int count =0;
				while(!Q.empty()){

						Node coor = Q.front();
						if(mat[coor.x][coor.y][coor.z]==0){
							//cout<<"dfs = "<<coor.x<<" "<<coor.y<<" "<<coor.z<<endl;
						 	int val= dfs(coor, 0);
						 	if(val!=-1) count+=val;
						}
						Q.pop();
				}

				cout<<count<<endl;
				///////////////
    }

    return 0;
}
