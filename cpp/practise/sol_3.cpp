#include<bits/stdc++.h>

using namespace std;

int arr[102][102][102];
int X,Y,Z;

bool isvalid(int i, int j, int k) {
	if(i < 0 || j < 0 || k<0 || i >=X || j >=Y || k>=Z) return false;
	else return true;
}
struct c{
    int x,y,z;
};

int dfs(c temp, int val){
    //cout<<temp.x<<" "<<temp.y<<" "<<temp.z<<" = "<<arr[temp.x][temp.y][temp.z]<<endl;
    arr[temp.x][temp.y][temp.z]=1;

    if(temp.x ==0 || temp.y==0 || temp.z==0 || temp.x==X-1 || temp.y==Y-1 || temp.z==Z-1 )
        return -1;

    if(val!=-1)
        val+=1;

    if(isvalid(temp.x+1, temp.y, temp.z) && arr[temp.x+1][temp.y][temp.z] == 0) {
        temp.x++;
        int vv = dfs(temp, val);
        if(val!=-1)
            val=vv;
        temp.x--;
    }

    if(isvalid(temp.x-1, temp.y, temp.z) && arr[temp.x-1][temp.y][temp.z] == 0) {
        temp.x--;
        int vv = dfs(temp, val);
        if(val!=-1)
            val=vv;
        temp.x++;
    }

    if(isvalid(temp.x, temp.y+1, temp.z) && arr[temp.x][temp.y+1][temp.z] == 0) {
        temp.y++;
        int vv = dfs(temp, val);
        if(val!=-1)
            val=vv;
        temp.y--;
    }

    if(isvalid(temp.x, temp.y-1, temp.z) && arr[temp.x][temp.y-1][temp.z] == 0) {
        temp.y--;
        int vv = dfs(temp, val);
        if(val!=-1)
            val=vv;
        temp.y++;
    }

    if(isvalid(temp.x, temp.y, temp.z-1) && arr[temp.x][temp.y][temp.z-1]==0){
        temp.z--;
        int vv= dfs(temp, val);
        if(val!=-1)
            val=vv;
        temp.z++;
    }

    if(isvalid(temp.x, temp.y, temp.z+1) && arr[temp.x][temp.y][temp.z+1] == 0){
        temp.z++;
        int vv= dfs(temp, val);
        if(val!=-1)
            val=vv;
        temp.z--;
    }
    //cout<<"val = "<<val<<endl;
    return val;
}

void solve(queue<c> Q){

    long ans =0;
    while(!Q.empty()){
        c tt= Q.front();
        if(arr[tt.x][tt.y][tt.z]==0){
         //cout<<"=>"<<tt.x<<" "<<tt.y<<" "<<tt.z<<" = "<<arr[tt.x][tt.y][tt.z]<<endl;
         int v= dfs(Q.front(), 0);
         if(v!=-1)
            ans+=v;
        }
        Q.pop();
    }

    cout<<ans<<endl;
}

int main(){

    int T;

    int val;
    cin>>T;
    queue<c> Q;
    c temp;

    while(T--){

        cin>>X>>Y>>Z;

        for(int i=0; i<Z; i++){
            for(int j=0; j<X; j++){
                for(int k=0; k<Y; k++){
                    cin>>val;
                    arr[j][k][i]=val;
                    if(val==0){
                        temp.x =j;
                        temp.y =k;
                        temp.z =i;
                        Q.push(temp);
                    }
                }
            }

        }

        //temp.x=-1; temp.y=-1; temp.z=-1;
        //Q.push(temp);

        solve(Q);
    }

    return 0;
}
