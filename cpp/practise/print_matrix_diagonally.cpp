#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

void printMatrixDiagonal(int mat[MAX][MAX], int n){

    int i=0, j=0;
    bool up = true;
    int cnt =0;

    while (cnt<n*n) {

      if(up){
        while (i>=0 && j<n) {
          std::cout <<mat[i][j] << ' '; cnt++;
          j++; i--;
        }
        if(j==n)
          j--, i+=2;
        else
          i++;

      }else{  //down

          while (j>=0 && i<n) {
            std::cout <<mat[i][j] << ' '; cnt++;
            j--; i++;
          }
          if(i==n)
            j+=2,i--;
          else
            j++;
      }
      up=!up;
   }
}

int main(){

  int mat[MAX][MAX] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16}
                      };

  int n = 4;
  printMatrixDiagonal(mat, n);

  return 0;

}
