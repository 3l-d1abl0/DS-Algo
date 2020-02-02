#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

int arr[105];

bool myfunction (int i,int j) { return (i>j); }

int findMin(int N, int K){

    int ans = INT_MAX;

    for(int L=0; L<N; L++){
        for(int R=0; R<N; R++){

                int minArrSum =0;
                vector<int> minArr;
                vector<int > maxArr;

                for(int i=0; i<N;i++){
                    if(i>=L && i<=R){ minArr.push_back(arr[i]); minArrSum+=arr[i]; }
                    else{ maxArr.push_back(arr[i]);  }
                }

                sort(minArr.begin(), minArr.end());
                sort(maxArr.rbegin(), maxArr.rend());

//                cout<<"Min Array "<<endl;
//                for(vector<int>:: iterator it = minArr.begin(); it!=minArr.end(); it++)
//                    cout<<(*it)<<" ";
//                cout<<"minSum = "<<minArrSum<<endl;
//
//                cout<<"Max Array "<<endl;
//                for(vector<int>:: iterator it = maxArr.begin(); it!=maxArr.end(); it++)
//                    cout<<(*it)<<" ";

                ans = min(ans, minArrSum);

                for(int i=1; i<=K; i++){

                    if(i>minArr.size() || i>maxArr.size())
                        break;
                    //cout<<"-----------3"<<endl;
                    minArrSum -= minArr[minArr.size()-i];
                    minArrSum +=maxArr[maxArr.size()-i];

                    ans = min(ans, minArrSum);
                    //cout<<"ANS == "<<ans<<endl;
                }

        }
    }
    return ans;
}

int main(){

    int T,N,K;

    cin>>T;
    while(T--){

        cin>>N>>K;
        for(int i=0; i<N; i++)
            cin>>arr[i];


        cout<<findMin(N, K)<<endl;
    }

    return 0;
}


////https://stackoverflow.com/questions/36369818/minimum-contiguous-sum-that-can-be-obtained-by-performing-at-most-k-swaps
