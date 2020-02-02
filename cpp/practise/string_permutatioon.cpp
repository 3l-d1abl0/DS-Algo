#include<bits/stdc++.h>

using namespace std;

char swap_char(char *a, char *b){

    char *temp = a;
    *a = *b ;
    *b = *temp;

}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int idx, int len){

    if(idx == len)
        cout<<str<<endl;
    else{
        for(int i=idx; i<=len; i++){

            swap((str+idx), (str+i));
            //cout<<"::"<<str<<endl;
            permute(str, i+1, len);
            swap((str+idx), (str+i));
            //cout<<"::"<<str<<endl;
        }
    }

}

int main(){

    //string str = "AABC";
    char str[] = "AABC";

    //cout<<str<<endl;

//    int len = str.length();
    int len = strlen(str);

    permute(str, 0, len-1);




    return 0;
}
