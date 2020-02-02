#include<bits/stdc++.h>

using namespace std;

#define MAX_LEN 10000

bool checkIn(char *str1, char *str2, char *str3){

    if( !(*str1||*str2||*str3) ){
        return true;
    }

    if(*str3 == '\0')
        return false;

    return ( (*str3 == *str1) && checkIn(str1+1 , str2, str3+1) ) || ( (*str3 == *str2) && checkIn(str1, str2+1, str3+1) );
}

void checkInterLeave(char *str1, char *str2, char *str3){

    /*int l1 = strlen(str1);
    int l2 = strlen(str2);
    int l3 = l1+l2;
    char str3[l1+l2];*/

    cout<<str1<<" "<<str2<<endl;

    cout<<str3<<endl;

    if(checkIn(str1, str2, str3)){
        cout<<"Interleave"<<endl;
    }else{
        cout<<"Doens\'t Interleave"<<endl;
    }

}

void checkInterleaveDP(char *str1, char *str2, char *str3){

    int len1 = strlen(str1); cout<<"len1 = "<<len1<<endl;
    int len2 = strlen(str2); cout<<"len2 = "<<len2<<endl;
    int len3 = strlen(str3); cout<<"len3 = "<<len3<<endl;

    if(len1+len2 != len3){
        cout<<"Doesn't Interleave !"<<endl;
        return;
    }
    /* Check if str1[0..i-1] and str2[0..j-1] interleaves str3[0...i+j-1]
        len1+len2 == len3
    */

   bool dp[len1+1][len2+1];

   memset(dp, false, sizeof(dp)*sizeof(bool));

    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){

            if(i==0 && j==0)
                dp[i][j] = true;

            //if str1 is null/0
            if(i==0){
                if(str2[j-1] == str3[i+j-1])
                    dp[i][j] = dp[i][j-1];
            }

            else if(j==0){
                if(str1[i-1]==str3[i+j-1])
                    dp[i][j] = dp[i-1][j];
            }

            else if(str1[i-1]==str3[i+j-1] && str2[j-1]==str3[i+j-1]){
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }

            else if(str1[i-1]==str3[i+j-1] && str2[j-1]==str3[i+j-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(str1[i-1]!=str3[i+j-1] && str2[j-1]==str3[i+j-1]){
                dp[i][j] = dp[i][j-1];
            }

        }
    }

    if(dp[len1][len2])
        cout<<"Interleave";
    else
        cout<<"Doesn't Interleave !";
}

int main(){

    char str1[MAX_LEN];
    char str2[MAX_LEN];
    char str3[MAX_LEN];

    //scanf("%s %s", str1, str2);
    //scanf("%s", str3);

    str1 = 'XXY'; str2='XXZ'; str3='XXZXXXY';
    //str1 = 'XY'; str2 ='WZ'; str3='WZXY';

    /*test("XXY", "XXZ", "XXZXXXY"); 
    test("XY", "WZ", "WZXY"); 
    test("XY", "X", "XXY"); 
    test("YX", "X", "XXY"); 
    test("XXY", "XXZ", "XXXXZY");*/

    //checkInterLeave(str1, str2, str3);
    cout<<"==="<<endl;
    checkInterleaveDP(str1, str2, str3);

    return 0;
}
