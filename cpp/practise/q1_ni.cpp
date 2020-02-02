#include<iostream>

using namespace std;

int arr[1000][1000];

int P[1005];
int T[1005];

int main(){

    int cases;
    int N,K;
    char pt;

    cin>>cases;

    while(cases--){

        cin>>N>>K;
        int tcnt =0, leftOut =0;
        for (int i = 0; i < N; ++i){
        	
        	for (int k = 0; k < 1004; ++k){
        		P[k] = 0; T[k]=0;
        	}
        	//cout<<"Row "<<i<<" :: "<<endl;
        	for (int j = 1; j <= N; ++j){
        		cin>>pt;
        		
        		T[j] = T[j-1];	P[j]=P[j-1];

        		if(pt=='P'){
        			P[j]++;

        			if(T[j]>0){
        				int range =1;
        				if(j-K-1>1)
        					range = j-K-1;
        				if(P[range]<P[j]){
        					T[j]--;	P[j]--;
        				}
        			}
        		}//P
        		else{
        			T[j]++;
        			tcnt++;
        			if(P[j]>0){
        				int range = 1;
        				if(j-K-1>1)
        					range = j-K-1;
        				if(P[range]<P[j]){
        					T[j]--;	P[j]--;
        				}
        			}
        		}
        		//cout<<" . "<<endl;
        	}//for

        	leftOut +=T[N];

        	/*for(int j=0; j<=N; j++)
        		cout<<T[j]<<" ";
        	cout<<endl;
        	cout<<"Left Out :: "<<leftOut<<endl;*/
        }//for

        //cout<<"Total Thief :: "<<tcnt<<endl;
        //cout<<"Left Out :: "<<leftOut<<endl;

        cout<<tcnt-leftOut<<endl;

    }

    return 0;
}
