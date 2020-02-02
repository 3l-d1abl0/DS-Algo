#include<bits/stdc++.h>


using namespace std;

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9,10};

    int sz = sizeof(arr)/sizeof(arr[0]);

    int XoR=0;
    for(int i=0; i<sz; i++){

        for(int j=i+1; j<sz;j++){
            int aa = arr[i]^arr[j];
            cout<<arr[i]<<" ^"<<arr[j]<<" = "<<aa<<endl;
            XoR= max(XoR, aa);
        }
        XoR=0;
        cout<<"---"<<endl;
    }

    cout<<"Max XoRR :: "<<XoR<<endl;

return 0;
}
