#include<bits/stdc++.h>

using namespace std;

string modifyString(string str){
    string st ="#";

    for(int i=0; i<str.length(); i++)
        st += str.substr(i,1)+'#';

    return st;
}

int manachersAlgo(string str){

    int n = str.length();
    string modStr = modifyString(str);
    n= 2*n +1;

    //cout<<modStr<<" Length :: "<<n<<endl;


    //array to hold Palindrome length
    vector<int> P(n,0);
    int center =0;
    int rb =0; //right boundary
    int maxLen =0; // max length of palindrome seen till now

    for(int i=0; i<n; i++){

        int mirror_idx = 2*center - i; //center -(i-center)

        //1. Check for the given index and right boundary
        //if the index of element falls under the right boundary
        //check if its mirror on the left has length which falls beyond the left boundary
        //or can form palindrome at current index withing right boundary
        if(i<rb) P[i] = min(rb-i, P[mirror_idx]);

        //2. Expand the palindrome at current idx
        int rt = i + (P[i]+1);
        int lf = i - (P[i]+1);
        while(rt< n && lf>=0 && modStr[lf]==modStr[rt]){
            P[i]++; lf--; rt++;
        }


        //3. Check if center need to be updated, modify right boundary accordingly
        if(i+P[i]> rb){ //if length of palindrome at current index exceeeds the current right_boundary

            center = i; //current index becomes the center
            rb = i+P[i];
        }

        maxLen  = max(P[i], maxLen);

    }

    /*for(int i=0; i<n; i++)
        cout<<P[i]<<" ";
    cout<<endl;*/
    return maxLen;
}


int main(){

    string str ="abababab";

    int len = manachersAlgo(str);
    cout<<"Max. Palindrome Length = "<<len<<endl;

    return 0;
}