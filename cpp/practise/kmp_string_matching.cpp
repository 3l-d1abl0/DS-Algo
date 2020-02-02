#include<bits/stdc++.h>

using namespace std;

void print_vec(vector<int> table){

    int len = table.size();

    vector<int>::iterator ptr;

    for(ptr=table.begin(); ptr!=table.end(); ptr++)
        cout<<*ptr<<" ";

    cout<<endl;

}

vector<int> prefix_calculate(string ptr){

    int str_len = ptr.length();

    vector<int > table(str_len);

    int len = 0; table[len] =0; //[0]=0

    int i=1;

    while(i<str_len){

        if(ptr[len] == ptr[i]){
            len++;
            table[i] = len;
            i++;
        }else{

            if (len==0) table[i++]=0;
            else len = table[len-1];
        }
    }

    return table;

}

bool KMP(string str, string pat){

    int str_len = str.length();
    int pat_len = pat.length();

    int str_idx =0;
    int pat_idx =0;

    vector<int> table = prefix_calculate(pat);
    print_vec(table);

    while(str_idx<str_len){

        cout<<str[str_idx]<<" "<<pat[pat_idx]<<endl;

        if(str[str_idx]==pat[pat_idx]){
            str_idx++; pat_idx++;

            if(pat_idx==pat_len){
                cout<<"Pattern Found at "<<str_idx-pat_idx<<endl;
                return true;
            }
        }else{
                if (pat_idx==0)
                        str_idx++;
                else
                    pat_idx = table[pat_idx-1];
        }

    }

    return false;

}

int main(){

    /*
    string tar = "san and linux training";
    string pat = "lin";
    */

    string str = "san and linux training";
    string pat = "lin";
    //string pat = "abcdabca";


    if(!KMP(str, pat)){
        cout<<"Pattern Not Found !!!"<<endl;
    }


    return 0;
}
