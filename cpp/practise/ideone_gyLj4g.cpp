#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t;
	cin>>t;
	int i;
	int j;
	for(i=0;i<t;i++){
		int N,P;
		cin>>N;
		cin>>P;
		vector<int> milk(N);
		for(j=0;j<N;j++){
			cin>>milk[j];
		}
		vector<int> apple(N);
		for(j=0;j<N;j++){
			cin>>apple[j];
		}
		P = P - 1;
		int maxApple = 0;
		for(j=0;j<N;j++){
			if(P - 1 < 0 || P == 0){
				P += milk[j];
			}
			else{
				maxApple += apple[j];
				P--;
			}
		}
		cout<<maxApple<<"\n";
	}
	return 0;
}
