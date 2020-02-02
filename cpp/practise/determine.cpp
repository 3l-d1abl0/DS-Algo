#include<bits/stdc++.h>


using namespace std;

int Q[4];
int decc[4];

int f[4];
int c[4];

int main(){

int T;
    cin>>T;

    while(T--){


        cin>>Q[0]>>Q[1]>>Q[2]>>Q[3];
        cin>>decc[0]>>decc[1]>>decc[2]>>decc[3];
        cin>>f[0]>>f[1]>>f[2]>>f[3];
        long long int ft = f[0]+f[1]+f[2]+f[3];
        cin>>c[0]>>c[1]>>c[2]>>c[3];
        long long int ct = c[0]+c[1]+c[2]+c[3];

        //cal Score
        long long int ansF =0;
        long long int ansC =0;
        for(int i=0; i<4; i++){

            ansF+= Q[i] - ( (f[i]*decc[i] < Q[i]/2) ? f[i]*decc[i] : Q[i]/2);
            ansC+= Q[i] - ( (c[i]*decc[i] < Q[i]/2) ? c[i]*decc[i] : Q[i]/2);
        }

        if(ansF> ansC)
            cout<<"Flash"<<endl;
        else if(ansF < ansC)
            cout<<"Cisco"<<endl;
        else{
            if(ft<ct)
                cout<<"Flash"<<endl;
            else if(ct<ft)
                cout<<"Cisco"<<endl;
            else
                cout<<"Tie"<<endl;
        }
    }


    return 0;
}
