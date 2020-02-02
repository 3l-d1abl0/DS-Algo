#include<bits/stdc++.h>

using namespace std;

int main(){

    int M,N;

    cin>>M>>N;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<M;i++){

		for(int j=0;j<N;j++){

			for(int ir=0; ir<=i; ir++)
			{
				sum = 0;
                    for(int ic=0; ic<=j; ic++)
                        sum += arr[k][l];
                    tmp[k] = sum;
			}
		}
	}


    return 0;
}
