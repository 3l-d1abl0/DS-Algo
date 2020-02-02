#include<bits/stdc++.h>

using namespace std;

#define MAX_LEN 10000


void process(char* str, int idx, char* str1, char* str2){

    if(*str1 =='\0' && *str2 == '\0'){
        cout<<str<<endl;
    }


    if(*str1){
        str[idx] = *str1;
        process(str, idx+1, str1+1, str2);
    }


    if(*str2){
        str[idx] = *str2;
        process(str, idx+1, str1, str2+1);
    }
}

void interLeave(char* str1, char*str2){

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    char* str = new char[n1+n2];

    cout<<"str :: "<<str<<endl;

    process(str, 0, str1, str2);

}


int main(){

    char str1[MAX_LEN];
    char str2[MAX_LEN];

    scanf("%s %s", str1, str2);

    interLeave(str1, str2);

    return 0;
}
