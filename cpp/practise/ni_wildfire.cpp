// Name:
// Summary:

#include <iostream>
#include<vector>
#include<queue>

using namespace std;

// Remove additional cin/cout before submission.
long long int FindMinimumNumberOfCandles(int num_wildfire, int arr_num_candles[],vector<int > mp[])
{
    /* Write your code here. */
    bool visited[num_wildfire];
    for (int i=0; i< num_wildfire; i++){
        visited[i]=false;
    }

    int cnt=0;
    for (int i=0; i< num_wildfire; i++){
        //
        if(visited[i]==true)
            continue;

         queue <int> q;
        q.push(i);
        visited[i]= true;
        int minn = arr_num_candles[i];

            while(!q.empty()){

                int start= q.front();
                q.pop();

                //cout<<"Start :: "<<start<<endl;

                //for(int j=0;  j<mp[start].size();  j++){
                    for (auto j : mp[start]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j] = true;

                            minn = min(minn, arr_num_candles[ j  ]) ;
                        }
                }//for

            }//while

            cnt +=minn;

        //
    }


    return cnt;
}

// Do not modify main() function.
int main()
{

    int num_wildfire, num_strings, i;


    cin>>num_wildfire;

    int arr_num_candles[num_wildfire];
    vector<int> mp[num_wildfire];

    for (int i=0; i< num_wildfire; i++){
        cin>>arr_num_candles[i];
    }


    cin>>num_strings;
    //int arr_stringConnection[num_strings][2];

    int x,y;
    for (i = 0; i < num_strings; i++){
    	cin>>x>>y;
    	x--; y--;
    	mp[x].push_back(y);     mp[y].push_back(x);
    }

    cout<<FindMinimumNumberOfCandles(num_wildfire, arr_num_candles, mp)<<endl;
}

