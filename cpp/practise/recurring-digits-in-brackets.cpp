#include<bits/stdc++.h>

using namespace std;

string getBracket(int num, int den){

    int quotient = num/den;
    int remainder= num%den;

    string decimalPart="";
    map<int, int> mp;

    if(remainder==0){
        return to_string(quotient);
    }

    while(remainder!=0 && mp.find(remainder)==mp.end() ){

        mp[remainder]=decimalPart.length();

        remainder *=10;
        decimalPart = decimalPart+to_string(int(remainder/den));
        remainder = remainder%den;
        
    }

    if(remainder==0){
        return quotient+"."+decimalPart;
    }else{
        string returnAns = to_string(quotient)+".";
        for(int i=0; i<mp[remainder]; i++)
            returnAns+=decimalPart[i];
        returnAns +="("+decimalPart.substr(mp[remainder])+")";

        return returnAns;
    }
}


int main(){


    //int num =50; int den=22;
    //int num= 50; int den=10;
    //int num =94; int den=36;
    int num = 5000; int den = 22;

    cout<<getBracket(num, den)<<endl;


    return 0;
}