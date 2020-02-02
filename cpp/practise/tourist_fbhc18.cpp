#include<bits/stdc++.h>

using namespace std;

int main(){

    fstream myfile("input.txt",std::ios_base::in);
    ofstream output;
    output.open("output.txt");


    int T,N,K;
    long long int V;

    string att[80];


    //scanf("%d", &T);
    myfile >> T;

    long long int cnt =0;

    for(int i=1; i<=T; i++){


        //scanf("%d %d %d", &N, &K, &V);
        myfile >> N >> K >> V;
        //cout<<N<<" "<<K<<" "<<V<<endl;

        for(int j=0; j<N; j++){
            myfile>>att[j];
        }

        cnt = K*(V-1);

        int idx = cnt%N;

        int last_ele = (K<N-idx)?K:N -idx;

        int first_ele = K- last_ele;

        //cout<<first_ele<<" "<<last_ele<<endl;

        output<<"Case #"<<i<<":";
        //cout<<"Case #"<<i<<":";

        for(int j=0; j<first_ele; j++){
            output<<" "<<att[j];
            //cout<<" "<<att[j];
        }

        while(last_ele--){
            output<<" "<<att[idx];
            //cout<<" "<<att[idx];
            idx++;
        }
        output<<"\n";
        //cout<<"\n";


    }

    return 0;
}
