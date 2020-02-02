#include<bits/stdc++.h>

using namespace std;

void print_arr(int *lps, int psz){

    cout<<endl;
    for(int i=0; i<psz; i++){
        cout<<lps[i]<< "";
    }
    cout<<endl;

}
void print_arr(char *lps, int psz){

    cout<<endl;
    for(int i=0; i<psz; i++){
        cout<<lps[i]<< "";
    }
    cout<<endl;

}

void computeLps(char *pat, int psz, int *lps){

        int len =0, i = 0;
         lps[i]=0;
         i++;
         while(i<psz){

            if(pat[i]==pat[len]){

                len++;  lps[i]= len; i++;
            }else{

                    if(len==0){
                        lps[i++]=0;
                    }else{
                        len = lps[len-1];
                    }
            }
         }
}
bool KMP(char * txt, int stx, char * pat, int psz, int *lps){

    int i=0;    //for text
    int j=0;    //for pat

    while(i<stx){

        if(txt[i]==pat[j]){
            i++, j++;
        }else{
                if(j!=0){
                    j= lps[j-1];
                }else{
                    i++;
                }
        }

        if(j==psz){
            printf("Found pattern at index %d \n", i-j);
            return true;
        }
    }

    return false;
}
int main(){

    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";


    int stx = strlen(txt);
    int psz = strlen(pat);

    int lps[psz];

    computeLps(pat, psz, lps);

    cout<<"Text :: ";
    print_arr(txt, stx);

    cout<<"Pat:: ";
    print_arr(pat,psz);

    if(!KMP(txt, stx, pat, psz, lps )){
        cout<<"Pattern Not Found !!!"<<endl;
    }

    return 0;
}
