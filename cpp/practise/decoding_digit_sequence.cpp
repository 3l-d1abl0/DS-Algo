#include<bits/stdc++.h>

using namespace std;

int countRec(char *digits, int n){

    if (n==0 || n==1)
        return 1;

    int cnt = 0;

    if(digits[n-1] > '0')
        cnt = countRec(digits, n-1);

    if(digits[n-2]=='1' || (digits[n-2]=='2' && digits[n-1] < '7'))
        cnt+= countRec(digits, n-2);

    return cnt;
}

int countDP(char *digits, int n){

    int *cnt = new int[n+1];

    cnt[0] =1; cnt[1] =1;

    for(int i=2; i<=n; i++){

        if(digits[i-1]> '0')
            cnt[i] += cnt[i-1];

        if(digits[i-2]=='1' || (digits[i-2]=='2' && digits[i-1]<'7'))
            cnt[i] += cnt[i-2];
    }

    return cnt[n];
}

int main(){

    //char digits[] = "1234";
    char digits[] = "121";
    int n = strlen(digits);
    cout << "Count is : " << countRec(digits, n)<<endl;
    cout <<"Count DP : "<< countDP(digits, n);
    return 0;
}


//https://www.geeksforgeeks.org/find-all-possible-interpretations/
//https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
//https://stackoverflow.com/questions/15586047/given-an-encoded-message-count-the-number-of-ways-it-can-be-decoded
