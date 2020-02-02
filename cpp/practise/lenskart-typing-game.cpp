#include<bits/stdc++.h>

using namespace std;

int rows, cols;
char mat[100][100];

int d[][2] = { {-1,-1}, {0,-1}, {1,-1},
                {-1,0}, {0,0}, {1,0},
                {-1,1}, {0,1}, {1,1}
              };


bool TypingKeyboard (string w, int idx, int i, int j, int len) {
   
   //cout<<"--> ("<<i<<","<<j<<")"<<endl;
   
   if(idx == len-1)
    return true;
   
   //char curr = w[i];
   
   
   for(int x=0; x<9; x++){
       
       if((d[x][0]+i)>=0 && (d[x][0]+i)<=rows-1 && (d[x][1]+j)>=0 && (d[x][1]+j)<=cols-1){
           
           if( (d[x][0]+i)==i && (d[x][1]+j)==j)
            continue;
           
           //cout<<"==> "<<mat[d[x][0]+i][d[x][1]+j]<<" == "<<w[idx+1]<<endl;
           if(mat[d[x][0]+i][d[x][1]+j] == w[idx+1]){
               
               if(TypingKeyboard(w,idx+1, d[x][0]+i, d[x][1]+j, len))
                    return true;
           }
       }
   }
   
   return false;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> rows >> cols;
    //vector<string> mat(rows);
    
    map<char, vector<pair<int, int>>> charmap;
    
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>mat[i][j];
            charmap[mat[i][j]].push_back(make_pair(i,j));
        }
    }
    
    
    string w;
    cin >> w;
    
    if(charmap[(char)w[0]].size() ==0)
        cout<<"NO"<<endl;
    else{
        vector<pair<int, int>>::iterator it;
        
        for(it= charmap[(char)w[0]].begin(); it!=charmap[(char)w[0]].end(); it++){
            
            if(TypingKeyboard(w, 0, (*it).first, (*it).second, w.length())){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}