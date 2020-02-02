#include<bits/stdc++.h>
using namespace std;

int main(){

	int T;
	int N, K;
	char charc;
	
	pair<char,int> pp;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int cnt =0;
		for(int i=0; i<N; i++){

				stack<pair<char, int> >st;

				for(int j=0; j<N; j++){
						cin>>charc;
						if(st.empty()){
							st.push(make_pair(charc, j+1));
						}else{
							pp = st.top();
							if(pp.first!=charc){
								//cout<<pp.first<<" "<<charc<<endl;
								if(abs( (j+1) -pp.second)<=K){
									st.pop(); cnt++;
									//cout<<j+1<<" "<<pp.second<<" -> "<<(j+1)-pp.second<<" Size :: "<<st.size()<<endl;
								}else{
									st.push(make_pair(charc, j+1));
								}
							}else{
								st.push(make_pair(charc, j+1));
							}
						}
				}
				//st.clear();
		}
		cout<<cnt<<endl;
	}

	return 0;
}
