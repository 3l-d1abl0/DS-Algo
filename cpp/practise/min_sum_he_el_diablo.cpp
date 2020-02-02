#include <bits/stdc++.h>

using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int main()
{
    int t,n,k, num;
    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &n, &k);
        vector<int > arr;
        for(int i=0; i<n;i++){
            scanf("%d", &num);
            arr.push_back(num);
        }

        int minn = arr[0];
        for(int left=0; left<n; left++){
            for(int right=left; right<n; right++){

                vector<int> sub_min; vector<int> sub_max;
                int sub_min_sum=0;
                for(int i=0; i<n;i++){
                    if(i>=left && i<=right){
                        sub_min.push_back(arr[i]);
                        sub_min_sum += arr[i];
                    }else{
                        sub_max.push_back(arr[i]);
                    }
                }

                sort(sub_min.begin(), sub_min.end());
                sort(sub_max.begin(), sub_max.end(), myfunction );

                minn = min(minn, sub_min_sum);
                for(int i=1; i<=k; i++){
                    if(i>sub_min.size() || i>sub_max.size()) break;

                    sub_min_sum -= sub_min[sub_min.size()-i];
                    sub_min_sum += sub_max[sub_max.size()-i];
                    minn = min(minn, sub_min_sum);

                }


            }
        }

        printf("%d\n", minn);


    }

    return 0;
}
