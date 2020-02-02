#include<bits/stdc++.h>

using namespace std;

int LCS(char X[], int xlen, int i, char Y[], int ylen, int j){

    if(i==xlen || j== ylen)
        return 0;

    if(X[i] == Y[j])
        return LCS(X, xlen, i+1, Y, ylen, j+1);
    else
        return max( LCS(X, xlen, i+1,Y, ylen, j), (X, xlen, i, Y, ylen, j+1) );
}

void LCSdp(char X[], int xlen, char Y[], int ylen){

    int lc[xlen+1][ylen+1];
    cout<<endl;
    for(int i=0; i<=xlen; i++){

        for(int j=0; j<=ylen; j++){

            if(i==0 || j==0)
                lc[i][j]=0;

            else if(X[i-1]==Y[j-1])
                lc[i][j] = lc[i-1][j-1]+1;
            else
                lc[i][j] = max(lc[i-1][j], lc[i][j-1]);

                cout<<lc[i][j]<<" ";
        }

        cout<<endl;
    }

//    return lc[xlen][ylen];

    int idx  = lc[xlen][ylen];
    char l[idx+1];
    l[idx] = '\0';

    int i= xlen; int j=ylen;
    while(i>0 && j>0){

            if(X[i-1]==Y[j-1]){
                l[idx-1] = X[ i-1];
                i--; j--; idx--;
            }
            else if(lc[i-1][j] > lc[i][j-1]){
                i--;
            }else{
                j--;
            }
    }

    cout<<"LCS = '"<<l<<"'"<<endl;
}

int LCSopti(char X[],int xlen, char Y[], int ylen){

    int L[2][ylen+1];
    bool idx;

    for(int i=0; i<=xlen; i++){
            idx = i&1;
        for(int j=0; j<=ylen ;j++){

                    if(i==0 || j==0)
                        L[idx][j]=0;
                    else if(X[i-1]==Y[j-1]){
                            L[idx][j] = L[1-idx][j-1]+1;
                    }else{
                            L[idx][j] = max(L[1-idx][j], L[idx][j-1]);
                    }

                    //cout<<L[idx][j]<<" ";
            }
            //cout<<endl;
    }

    return L[idx][ylen];
}

int main(){

    char X[] = "AGGTAB";
    //char X[] = "ABCDGH";
    int xlen = strlen(X);
    char Y[] = "GXTXAYB";
    //char Y[] = "AEDFHR";
    int ylen = strlen(Y);


    //cout<<"LCS  = "<<LCS(X, xlen, 0, Y, ylen, 0); O(2^n)
    //cout<<"LCS = "<<LCSdp(X, xlen, Y, ylen);      O(xlen * ylen)
    //LCSdp(X, xlen, Y, ylen);
    cout<<"LCS = "<<LCSopti(X, xlen, Y, ylen)<<endl;    //O(xlen * ylen)

    return 0;
}
