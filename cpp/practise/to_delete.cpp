#include<bits/stdc++.h>

using namespace std;

int main()
{
	int M,N;
	cin>>M>>N;
    int arr[M][N];
    int sum[M][N];
    for(int i=0;i<M; i++){
            int sum2 =0;
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            sum2+=arr[i][j];
            sum[i][j]= sum2;
        }
    }

        int max_sz = INT_MIN;
		for(int i=0;i<M;i++){

		   for(int j=0;j<N;j++){

			for(int k=i;k<M;k++){

				for(int l=j;l<N;l++){
                        int sum1=0;
                        //for(int c=i;c<k+1;c++)
                        //{
                            for(int b=j;b<l+1;b++)
                            {
                                sum1+=(arr[k][b] - arr[i][b]);
                                cout<<arr[k][b]<<" - "<<arr[i][b]<<"=>";
                            }
                            cout<<endl;
                        //}   //
                        if(sum1==0)
                        {
                            cout<<(k-i+1)*(l-j+1)<<"Row :"<<i<<" -> "<<k<<"  Col ::"<<j<<" -> "<<l<<endl;
                            if(max_sz< ((k-i+1)*(l-j+1)) )
                                max_sz= (k-i+1)*(l-j+1);
                        }
				}
			}
		   }
		}
		cout<<max_sz;

		for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
		}

/*
3 3
1 2 3
-3 -2 -1
1 2 3

*/


/*
1
6
1 2 1
2 3 1
4 1 2
10 10 10
15 13 10
15 7 5



10 100 10
6   80      2
9   70      10
13  5      5
14  5      5

*/

	return 0;
}
