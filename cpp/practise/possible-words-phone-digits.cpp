#include<bits/stdc++.h>

using namespace std;

char keypad [10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keyCombo(int num[], int key_no, int key_sz, char output[]){
    //cout<<key_no<< " ";
    if(key_no==key_sz){
        cout<<output<<endl;
        return ;
    }

    for(int i=0; i<strlen(keypad[num[key_no]]); i++){

        output[key_no]= keypad[num[key_no]][i];
        keyCombo(num,key_no+1, key_sz, output);

        if(num[key_no] == 0 || num[key_no]==1)
            return;
    }

}

int main(){

    int num [] = { 2,3,0};

    int sz = sizeof(num)/sizeof(num[0]);
    //cout<<"sz = "<<sz<<endl;
    char output[sz+1];
    output[sz]='\0';

    //keyCombo(num, key_no, sz, output);
    keyCombo(num, 0, sz, output);

    return 0;
}
