#include<bits/stdc++.h>

using namespace std;


int main(){

    int N,x;

    cin>>N,x;
    int arr[N];
    bool tf[N];
    for(int i=0; i<N; i++){

        cin>>arr[i];
        tf[i] = false;

        if(arr[i]!=-1){
            arr[i]--;
        }

    }

    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int M;
    int ctr =0;

    cin>>M;
    cout<<"M = "<<M<<endl;

    tf[0] = true;

    for(int i=0; i<M; i++){

        cin>>x; x--;

        cout<<"x= "<<x<<endl;

        int par = arr[x]; cout<<"par = "<<par<<endl;
        bool stat = tf[x]; cout<<"stat = "<<stat<<endl;

        if(par ==-1){
            cout<<"1"<<endl;
        }else{

            while(par!=-1 && stat == false){

                par = arr[par]; cout<<"par "<<par<<endl;
                stat = tf[par]; cout<<" stat tf["<<par<<"] = "<<stat<<endl;
            }

            if(par==-1){
                cout<<par<<" <==> "<<stat<<endl;
                ctr ++;
                tf[x] = true;
                for(int j=0; j<N;j++){

                    cout<<tf[j]<<" ";
                }
                cout<<"================================="<<endl;
            }

        }

    }

    cout<<ctr<<endl;

    return 0;
}
