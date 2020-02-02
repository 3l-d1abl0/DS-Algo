#include<bits/stdc++.h>

using namespace std;


struct node{
    int left;
    int right;
};

int n, k;
int q, idx;

int main(){

    cin>>n>>k;
    char str[n];

    node arr[n];

    int cnt=0, maxlen=0;

    cin>>str;

    for(int i=0; i<n; i++){
        arr[i].left=0; arr[i].right=0;

        if(str[i]=='1'){
                cnt++;

            if(i==0)
                arr[i].left=i;
            else{

                if(str[i-1]=='1')
                    arr[i].left= arr[i-1].left;
                else
                    arr[i].left=i;
            }

        }else{
            maxlen=(maxlen>cnt)?maxlen:cnt;
            cnt=0;

            if(str[i-1]=='1' && i!=0){
                    //cout<<"ii -> "<<i<<endl;
                arr[i-1].right = i-1;
                arr[ arr[i-1].left ].right = i-1;
            }

        }
    }
    //end of str
    if(str[n-1]=='1'){
        maxlen=(maxlen>cnt)?maxlen:cnt;
            arr[n-1].right = n-1;
            arr[ arr[n-1].left ].right = n-1;
    }



    for(int i=0; i<k; i++){

        cin>>q;

        if(q==1)
            cout<<maxlen<<endl;

        else{

            cin>>idx;   idx--;

            if(str[idx]=='1')
            continue;

            if(idx==0){//start
                if(str[idx+1]=='1'){
                    arr[idx].left=idx;
                    arr[idx].right = arr[idx+1].right;
                    arr[ arr[idx].right ].left = idx;

                    maxlen = (maxlen> arr[idx].right-arr[idx].left+1)?maxlen: arr[idx].right-arr[idx].left+1;

                }else{
                    arr[idx].left=idx;      arr[idx].right=idx;
                    maxlen= (maxlen>1)?maxlen:1;
                }

            }else if(idx==n-1){ //end
                if(str[idx-1]=='1'){
                    arr[idx].left= arr[idx-1].left;
                    arr[idx].right = idx;

                    arr[ arr[idx].left ].right = idx;

                    maxlen = (maxlen> arr[idx].right-arr[idx].left+1)?maxlen: arr[idx].right-arr[idx].left+1;

                }else{
                    arr[idx].left = idx;    arr[idx].right = idx;
                    maxlen= (maxlen>1)?maxlen:1;
                }

            }else{//mid

                int ll=0;
                if(str[idx-1]=='1'){
                    ll= arr[idx-1].right-arr[idx-1].left+1;
                }

                int rl=0;
                if(str[idx+1]=='1'){
                    rl= arr[idx+1].right-arr[idx+1].left+1;
                }

                if(ll!=0 && rl!=0){
                    maxlen= (maxlen> ll+rl+1)?maxlen: ll+rl+1;
                    arr[ arr[idx+1].right ].left = arr[idx-1].left;
                    arr[ arr[idx-1].left ].right = arr[idx+1].right;
                }else if(ll!=0){
                    maxlen= (maxlen> ll+1)?maxlen: ll+1;
                    arr[ arr[idx-1].left ].right = idx;
                    arr[idx].right = idx;
                    arr[idx].left = arr[idx-1].left;
                }else if(rl!=0){
                    maxlen= (maxlen> rl+1)?maxlen: rl+1;
                    arr[idx].left = idx;
                    arr[ arr[idx+1].right ].left = idx;
                    arr[idx].right = arr[idx+1].right;
                }else{
                    maxlen= (maxlen> 1)?maxlen:1;
                    arr[idx].left = idx;
                    arr[idx].right = idx;
                }

            }

            str[idx]='1';
        }


    }

    return 0;
}
