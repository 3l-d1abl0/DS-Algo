#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(){

	int T,N,K;
	int catchCount;
	char xx;
	pair<char,int> ct;

	cin>>T;
	while(T--){

        cin>>N>>K;

		catchCount=0;
		for(int i=0; i<N; i++){

            stack<pair<char,int> >pot;

            for(int j=1; j<=N; j++){

				cin>>xx;
                if(pot.empty())
                    pot.push(make_pair(xx, j));
                else{

                    ct = pot.top();
                    if(ct.first == xx)
                        pot.push(make_pair(xx, j));
                    else{

                        if(abs( (j) - ct.second)<=K){
                            pot.pop();
                            catchCount++;
                        }else
                            pot.push(make_pair(xx, j));

                    }


                }
            }//j//for

		}
		cout<<catchCount<<endl;
	}

	return 0;
}
