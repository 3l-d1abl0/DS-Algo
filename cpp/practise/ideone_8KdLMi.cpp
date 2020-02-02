#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,arr[100050]={0},i,j,pow1,sum=0;
		
		cin>>n;
		
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		for(i=0;i<100050;i++)
		{
			if(arr[i])
			{
				long long int x = arr[i];
				while(x!=1 && x!=0)
				{
					int pow1 = log(arr[i])/log(2);
					
					x-=pow(2,pow1);
					
					arr[pow1+i]+=1;
					
				}
				
				if(x==0)
				{
					arr[i]=0;
				}
				sum+=arr[i];
				
			}
		}
		
		cout<<sum<<endl;
		
	}
	
	
	return 0;
}