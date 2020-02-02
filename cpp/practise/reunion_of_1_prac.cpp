#include<bits/stdc++.h>

using namespace std;


int main(){

    int N, K;

    cin>>N>>K;

    char arr[N];

    int st[N];
    int ed[N];

    st[0]=-1; st[N-1]=-1;
    ed[0]=-1; ed[N-1]=-1;
    int maxx=0;
    int cnt=0;

    cin>>arr;
    cout<<endl<<arr<<endl;

    for(int i=0; i<N; i++){
        st[i]=0; ed[i]=0;

        if(arr[i]=='1'){
                cnt++;

            if(i==0){
                st[i]=i;
            }else{
                if(arr[i-1]=='1'){
                    st[i]= st[i-1];
                }else{
                    st[i]=i;
                }
            }

        }else{
            maxx=(cnt>maxx)?cnt:maxx;
            cnt=0;

            cout<<"i = "<<i<<endl;
            if(arr[i-1]=='1' && i!=0){
                    cout<<"ii -> "<<i<<endl;
                ed[i-1]= i-1;
                ed[st[i-1]] = i-1;
            }
            cout<<st[i-1]<<" : "<<ed[i-1]<<endl;


        }
    }

    if(arr[N-1]=='1'){
        maxx=(cnt>maxx)?cnt:maxx;
            ed[N-1]= N-1;
            ed[st[N-1]] = N-1;
    }

    cout<<"Maxx :: "<<maxx<<endl;


    int q, idx;
    for(int i=0; i<K; i++){

        cin>>q;

        if(q==1){
            cout<<maxx<<endl;
        }else{
            cin>>idx;
            idx--;
            if(arr[idx]=='1')
                continue;

            if(idx==0){
                if(arr[idx+1]=='1'){
                    st[idx]=idx;
                    ed[idx] = ed[idx+1];

                    st[ ed[idx] ] = idx;

                    maxx = (maxx> (ed[idx]-st[idx]+1))?maxx: (ed[idx]-st[idx]+1);

                }else{
                    st[idx]=idx;    ed[idx]=idx;
                    maxx= (maxx>1)?maxx:1;
                }

            }else if(idx==N-1){
                if(arr[idx-1]=='1'){
                    st[idx]= st[idx-1];
                    ed[idx]= idx;

                    ed[st[idx] ]=idx;

                    maxx = (maxx> (ed[idx]-st[idx]+1))?maxx: (ed[idx]-st[idx]+1);

                }else{
                    st[idx]=idx;    ed[idx]=idx;
                    maxx= (maxx>1)?maxx:1;
                }
            }else{
                cout<<"else : idx :: "<<idx<<endl;
                int ll=0;
                if(arr[idx-1]=='1'){
                    ll= ed[idx-1]-st[idx-1]+1;
                    cout<<"left : "<<st[idx-1]<<" : "<<ed[idx-1]<<endl;
                }

                int rl=0;
                if(arr[idx+1]=='1'){
                    rl= ed[idx+1]-st[idx+1]+1;
                    cout<<"right : "<<st[idx+1]<<" : "<<ed[idx+1]<<endl;
                }
                cout<<ll<<" : "<<rl<<endl;
                if(ll!=0 && rl!=0){
                    maxx= (maxx> ll+rl+1)?maxx: ll+rl+1;
                    st[ ed[idx+1] ] = st[idx-1];
                    ed[ st[idx-1] ] = ed[idx+1];
                    cout<<"double :: "<<maxx<<endl;
                }else if(ll!=0){
                    maxx= (maxx> ll+1)?maxx: ll+1;
                    ed[ st[idx-1] ]= idx;
                    ed[idx] = idx;
                    st[idx]= st[idx-1];
                    cout<<"only Left"<<endl;

                }else if(rl!=0){
                    maxx= (maxx> rl+1)?maxx: rl+1;
                    st[idx] = idx;
                    st[ ed[idx+1] ] = idx;

                    ed[idx] = ed[idx+1];
                    cout<<"only Right"<<endl;
                }else{
                    maxx= (maxx> 1)?maxx:1;
                    st[idx]=idx;
                    ed[idx]=idx;
                    cout<<"here :: "<<maxx<<endl;
                }

            }

            arr[idx]='1';

            cout<<arr<<endl;
        }


    }//KLoop

    return 0;
}
