#include<bits/stdc++.h>

using namespace std;

void search(int mat[4][4],int len, int num){

    int row =0;
    int col =len-1;

    while(row<len && col>=0){

        if(mat[row][col]==num){
            cout<<"Found at : "<<row<<" "<<col<<endl;
            return;
        }

        if(num>mat[row][col]){
            row++;
        }else{
            col--;
        }
    }


    cout<<"Not Found !!!"<<endl;
    return ;

}

int main(){


    int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}};
    int len =4;
    search(mat, len, 29);

    return 0;
}
