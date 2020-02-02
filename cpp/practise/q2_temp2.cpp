#include <iostream>
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        int i,j;
        for(i=0;i<n;++i)
        cin>>arr[i];
        
        int max=arr[0];
        for(i=1;i<n;++i){
            if(arr[i]>max)
            max=arr[i];
        }
        
        if(max%2!=0)
        {
            cout<<max+1<<endl;
        }
        else
        cout<<max*2<<endl;
    }
    return 0;
}