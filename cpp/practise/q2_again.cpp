#include <bits/stdc++.h>

using namespace std;

int main(){

	int T,N;
	int arr[10002];

	cin>>T;

	while(T--){

		cin>>N;
		vector<int> v;
		int x;
		//cout<<"N = "<<N<<endl;
		for (int i = 0; i < N; ++i)
		{
			cin>>arr[i];
			//v.push_back(x);
		}

		//sort (v.begin(), v.end()); 
		sort(arr, arr+N);
		//cout<<"Sorted"<<endl;

		int next =2;

		//for(vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
		for(int i=0; i<N; i++)
		{
			if(arr[i] >next)
			{
				//*it = next;
				arr[i]=next;
				next+=2;
			}else if(arr[i] == next){
				next+=2;
			}
		}
		cout<<next<<endl;
	}

	return 0;
}