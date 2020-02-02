#include<bits/stdc++.h>
using namespace std;

int Solve (vector<int> arr) {
   // write code here
    int nxtmx =2;
    sort (arr.begin(), arr.end());

    vector<int>::iterator it;
    for(it = arr.begin() ; it != arr.end(); it++){

        if(*it >nxtmx)
            nxtmx+=2;
        else if(*it == nxtmx)
            nxtmx+=2;

    }
	return nxtmx;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i_arr=0; i_arr<n; i_arr++)
        {
        	cin >> arr[i_arr];
        }

        int out_;
        out_ = Solve(arr);
        cout << out_;
        cout << "\n";
    }
}
