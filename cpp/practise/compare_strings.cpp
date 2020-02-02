#include<bits/stdc++.h>

using namespace std;


#define lli long long int



pair<lli,lli> calDec(int N, char A[], char B[]){

    int base =1;
    lli val_a =0;
    lli val_b =0;

    for(int i=N-1; i>=0; i--){
        if(A[i]=='1')
            val_a +=base;
        if(B[i]=='1')
            val_b +=base;

        base = base*2;
    }

    return make_pair(val_a, val_b);
}

void binToDec(char A[], char B[], int N, long long int &aVal, long long int &bVal){

    aVal =0, bVal=0;
    int base = 1;

    for (int i=N-1;i>=0;i--)
    {
        if (A[i] == '1')
            aVal += base;

        if (B[i]=='1')
            bVal += base;

        base = base * 2;
    }
}


int main(){

    int N,Q,i;

    scanf("%d %d", &N,&Q);
    //printf("%d %d\n",N,Q);
    char A[N];
    char B[N];

    long long int aVal =0;
    long long int bVal =0;

    cin>>A>>B;

    //printf("%s %s\n",A,B);
    //cout<<A<<" "<<B<<endl;

    binToDec(A,B,N,aVal,bVal);

    //printf("%d %d\n",aVal, bVal);

    while(Q--){

        scanf("%d", &i);

        int p= N-i;
        //cout<<"B:"<<p<<" "<<B[p]<<endl;
        if(B[i-1]=='0'){
            B[i-1]='1';
            bVal += pow(2,p);
            //cout<<"B = "<<B<<"  bVal = "<<bVal<<endl;
            //printf("B =%s bVal=%d \n",B, bVal);
        }

        if(bVal >=aVal)
            printf("YES\n");
        else
            printf("NO\n");

    }

    /*
    for(int i=0; i<N; i++)
        cout<<B[i];
    cout<<endl;*/

    return 0;
}
