#include<bits/stdc++.h>

using namespace std;

const int P1=101;
const int P2=103;

const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;

const int N = 1e5 +5;
long long POW1[N], POW2[N];
long long INVMOD1 = 940594066;
long long INVMOD2 = 601941753;

long long inverseMod(int x, long long y, long long MOD){
    long long res =1;
    x = x%MOD;

    while(y>0){

        if(y&1)
            res = (res*x) %MOD;
        
        y = y>>1;
        x = (x*x)%MOD;
    }
    return res;
}

void calc_pow(){
    POW1[0] =1; POW2[0]=1;
    for(int i=1; i<N; i++){
        POW1[i] = (POW1[i-1]*P1)%MOD1; //cout<<POW1[i]<<" ";
        POW2[i] = (POW2[i-1]*P2)%MOD2;  //cout<<POW2[i]<<endl;
    }
}

bool checkSubstringOfLength(string a, int alen, string b, int blen, int n){
    cout<<a<<" "<<alen<<" "<<b<<" "<<blen<<" "<<n<<endl;
    long long hash1=0, hash2=0;
    set<int> hashSet1, hashSet2;

    //Calculate hash for the substring containing first n characters
    for(int i=0; i<n ; i++){
        hash1= ( hash1 + (a[i]-'a'+1)*POW1[i] )%MOD1;
        hash2= ( hash2 + (a[i]-'a'+1)*POW2[i] )%MOD2;
    }
    cout<<"a hash1 = "<<hash1<<endl;
    cout<<"a hash2 = "<<hash2<<endl;

    //Insert hashes in the set
    hashSet1.insert(hash1);
    hashSet2.insert(hash2);
    for(int i = n; i<alen; i++){
        hash1= ( hash1 + (a[i]-'a'+1)*POW1[i] )%MOD1;   //adding the next character
        //hash1= ( hash1 - ((a[i-n]-'a'+1)*POW1[i-n])*INVMOD1 )%MOD1; //removing the first char of the the previous substring
        hash1= ( (hash1 - (a[i-n]-'a'+1)*POW1[i-n] +MOD1)*INVMOD1 )%MOD1; //removing the first char of the the previous substring

        hash2= ( hash2 + (a[i]-'a'+1)*POW2[i])%MOD2;    //adding the next character
        //hash2= ( hash2 - ((a[i-n]-'a'+1)*POW2[i-n])*INVMOD2 )%MOD2; //removing the first char of the the previous substring
        hash2= ( (hash2 - (a[i-n]-'a'+1)*POW2[i-n] +MOD2)*INVMOD2 )%MOD2;

        cout<<"a hash1 = "<<hash1<<endl;
        cout<<"a hash2 = "<<hash2<<endl;

        hashSet1.insert(hash1);
        hashSet2.insert(hash2);
    }

    cout<<"B ::: "<<endl;
    //Calculate substring hashes for string b

    hash1=0; hash2=0;

    for(int i=0; i<n; i++){
        hash1= ( hash1 + (b[i]-'a'+1)*POW1[i] )%MOD1;
        hash2= ( hash2 + (b[i]-'a'+1)*POW2[i] )%MOD2;
    }

            cout<<"b hash1 = "<<hash1<<endl;
        cout<<"b hash2 = "<<hash2<<endl;
    if (hashSet1.find(hash1) != hashSet1.end() && hashSet2.find(hash2) != hashSet2.end() ){
        cout<<"TRUE"<<endl;
        return true;
    }



    for(int i=n; i<blen; i++){
        hash1= ( hash1 + (b[i]-'a'+1)*POW1[i] )%MOD1;   //adding the next character
        //hash1= ( hash1 - ((b[i-n]-'a'+1)*POW1[i-n])*INVMOD1 )%MOD1; //removing the first char of the the previous substring
        hash1= ( (hash1 - (b[i-n]-'a'+1)*POW1[i-n] +MOD1)*INVMOD1 )%MOD1;

        hash2= ( hash2 + (b[i]-'a'+1)*POW2[i])%MOD2;    //adding the next character
        //hash2= ( hash2 - ((b[i-n]-'a'+1)*POW2[i-n])*INVMOD2 )%MOD2; //removing the first char of the the previous substring
        hash2= ( (hash2 - (b[i-n]-'a'+1)*POW2[i-n] +MOD2)*INVMOD2 )%MOD2;

                cout<<"b hash1 = "<<hash1<<endl;
        cout<<"b hash2 = "<<hash2<<endl;
    
        if (hashSet1.find(hash1) !=hashSet1.end() && hashSet2.find(hash2)!= hashSet2.end() ){
            cout<<"TrUe"<<endl;
            return true;
        }
    }

    cout<<"FALSE"<<endl<<endl;
    return false;
}



int main(){

    calc_pow(); //calculating pow for P1 and P2
    //INVMOD1 = inverseMod(P1, MOD1-2, MOD1);
    //cout<<"INVMOD1 "<<INVMOD1<<endl;
    //cout<<"INVMOD2 "<<INVMOD2<<endl;
    //INVMOD2 = inverseMod(P2, MOD2-2, MOD2);

    string a, b;
    a = "abcba"; b = "acab";
    int alen= a.size(); int blen = b.size(); 
    /*  abcba, acab
        abcdaaab, xtzbcddabb
    */

   int start =0, end = min(alen, blen);
   int ans =0;
   while(start <= end){

    cout<<start<<" "<<end<<endl;
    int mid = start + (end - start)/2;
    cout<<"mid ="<<mid<<endl;
    if(checkSubstringOfLength(a, alen, b, blen, mid)){
           start = mid+1;
           ans = max(ans, mid);
           cout<<"TRUE- "<<mid<<endl;
    }else{
           end = mid-1;
    }

   }
    cout<<MOD1<<" "<<MOD2<<endl;
    cout<<ans<<endl;
    return 0;
}