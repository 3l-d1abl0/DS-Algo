#include<bits/stdc++.h>

using namespace std;

int longestPalSubstr(char *str){

    int len = strlen(str);

    bool tb[len][len];
    memset(tb, 0, sizeof(tb));

    int maxLen =1;
    for(int i=0; i<len; i++)
        tb[i][i]=true;

    int beg =0;
    //Looking for Len 2 substrings
    for(int i=0; i<len-1; i++){
        if(str[i]==str[i+1]){
            tb[i][i+1]=true;

            beg =i; maxLen=2;
        }
    }

    //looking for Len 3 Substrings
    for(int k =3; k<len;k++){

        for(int i=0; i<len-k+1; i++){

            int j= i+k-1;

            if(str[i]==str[j] && tb[i+1][j-1]){
                tb[i][j]=true;

                if(k>=maxLen){
                    beg=i;
                    maxLen = k;

                }
            }
        }//for
    }//for

    printf("Longest Palindrome Substring : ");
    for(int i=beg; i<beg+maxLen; i++)
        cout<<str[i];
    cout<<endl;

    return maxLen;

}

int longPalSubstr(char *str){

    int len = strlen(str);
    int maxLen =1;
    int beg =0;

    for(int i=1; i<len;i++){

        //checking for Odd Length Chars
        int lf=i-1, rt=i+1;
        while(lf>=0 && rt<len && str[lf]==str[rt] ){

            if(rt-lf+1 > maxLen){
                beg = lf;
                maxLen = rt-lf+1;
            }
            lf--; rt++;
        }

        //Checking for Even Length
        lf=i-1; rt=i;
        while(lf>=0 && rt<len && str[lf]==str[rt]){

            if(rt-lf+1 > maxLen){
                beg=lf;
                maxLen = rt-lf+1;
            }
            lf--; rt++;
        }//while

    }//for

    printf("Longest Palindrome Substring : ");
    for(int i=beg; i<beg+maxLen; i++)
        cout<<str[i];
    cout<<endl;

    return maxLen;

}

int main(){

    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", longestPalSubstr( str ) );
    printf("\nLength is: %d\n", longPalSubstr( str ) );
    return 0;
}
