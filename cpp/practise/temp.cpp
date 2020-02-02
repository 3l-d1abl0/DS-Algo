#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;
	vector<long> A;

	for(int k=0;k<T;k++)
	{
		int N,M;
		long total = 0;
		long C[300][300];

		cin>>N>>M;

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin>>C[i][j];
			}
		}

		for(int i=0;i<N;i++)																	//For each of the remaining n-1 days
		{
		    cout<<"i  ::"<<i<<endl;
			long temp[300],mindex[M],t;																		//Track all the possibilities
			for(int j=0;j<i+1;j++)																//Find the min element from each day from the ramining list
			{
				int count = 0;																	//count all the removed elements
				for(int x=0;x<M;x++)
				{
					if(C[j][x]>1000000)
					{
						count = count + 1;
					}
				}
				t = *min_element(C[j],C[j] + M) + pow(count+1,2) - pow(count,2);			//perfect
				temp[j] = t;
				mindex[j] = distance(C[j],min_element(C[j],C[j]+M));
			}
			total = total + *min_element(temp,temp+i+1);
			cout<<"Total ::"<<total<<endl;
			int z = distance(temp,min_element(temp,temp+i+1));
			int index = mindex[z];
			C[z][index] = 10001111;
			cout<<"C["<<z<<"]["<<index<<"] = "<<C[z][index]<<endl;
		}
		A.push_back(total);
	}
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<": "<<A[i]<<"\n";
	}
	return 0;
}
