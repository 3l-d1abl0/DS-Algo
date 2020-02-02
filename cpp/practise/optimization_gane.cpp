#include<bits/stdc++.h>

using namespace std;

int main() {

	long long int t;
	cin>>t;
	while(t--)
	{
	   // cout<<"T ::"<<t<<endl;
		long long int n,arr[100050]={0},i,j,pow1,sum=0;

		cin>>n;

		for(i=0;i<n;i++)
			cin>>arr[i];

		for(i=0;i<100050;i++)
		{
		    //cout<<"I :: "<<i<<endl;
			if(arr[i])
			{
				long long int x = arr[i];
				while(x!=1 && x!=0)
				{
					int pow1 = log(arr[i])/log(2);

					x-=pow(2,pow1);
					//cout<<"x ::"<<x<<endl;

					/*if(x<0){
                        cout<<"Breaking.. "<<endl;
                        break;
					}*/

					arr[pow1+i]+=1;
                    //cout<<"----"<<endl;
				}

				if(x==0)
                    arr[i]=0;

				//cout<<" "<<sum<<"+"<<arr[i]<<endl;
				sum+=arr[i];


			}

			/*if(i>10){
                cout<<"break.!"<<endl;
                break;
			}*/
		}

		cout<<sum<<endl;

	}


	return 0;
}
