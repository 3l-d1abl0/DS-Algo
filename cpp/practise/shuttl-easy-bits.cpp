#include<bits/stdc++.h>

using namespace std;

struct Node{

    int num,qty,sum =0;
    /*bool operator<(Node const &other){
        return num < other.num;
    }*/
};

Node nd[100002];
int N;
bool pflag;

void _merge(int l, int m, int r){

    int sz1 = m-l+1;
    int sz2 = r-m;

    Node L[sz1]; Node R[sz2];

    for(int i=0; i<sz1; i++){
        L[i].num = nd[l+i].num;
        L[i].qty = nd[l+i].qty;
        L[i].sum = nd[l+i].sum;
    }
    for(int j=0; j<sz2; j++){
        R[j].num = nd[m+j+1].num;
        R[j].qty = nd[m+j+1].qty;
        R[j].sum = nd[m+j+1].sum;
    }


    int i=0, j=0, k=l;
    while(i<sz1 && j<sz2){
        if(L[i].num<=R[j].num){
            nd[k].num = L[i].num;
            nd[k].qty = L[i].qty;
            i++;
        }else{
            nd[k].num=R[j].num;
            nd[k].qty=R[j].qty;
            j++;
        }
        if(k==0)
            nd[k].sum = nd[k].qty;
        else
            nd[k].sum = nd[k-1].sum+nd[k].qty;

        if(nd[k].sum>=N && pflag==true){
            cout<<nd[k].num<<endl;
            pflag=false;
        }

        //cout<<"K = "<<nd[k].sum<<endl;
        k++;
    }

    while(i<sz1){
        nd[k].num = L[i].num;
        nd[k].qty = L[i].qty;

        if(k==0)
            nd[k].sum = nd[k].qty;
        else
            nd[k].sum = nd[k-1].sum+nd[k].qty;

        if(nd[k].sum>=N && pflag==true){
            cout<<nd[k].num<<endl;
            pflag=false;
        }
        //cout<<"K = "<<nd[k].sum<<endl;
        i++; k++;
    }
    while(j<sz2){
        nd[k].num = R[j].num;
        nd[k].qty = R[j].qty;

        if(k==0)
            nd[k].sum = nd[k].qty;
        else
            nd[k].sum = nd[k-1].sum+nd[k].qty;

        if(nd[k].sum>=N && pflag==true){
            cout<<nd[k].num<<endl;
            pflag=false;
        }
        //cout<<"K = "<<nd[k].sum<<endl;
        j++; k++;
    }

}

void msrt(int l, int r){

    if(l<r){
        int m = l+(r-l)/2;
        msrt(l, m);
        msrt(m+1, r);
        _merge(l, m, r);
    }
    //cout<<"msrt"<<endl;
}

int bsrch(int r, int l){

	int mid;
    while(r<l){
        mid = r +(l-r)/2;

        if(nd[mid].sum == N )
            return nd[mid].num;
        else if(nd[mid].sum<N && mid!=l && (nd[mid+1].sum>=N) )
            return nd[mid+1].num;
        else if(nd[mid].sum>N && mid!=r && (nd[mid-1].sum<N) )
            return nd[mid].num;

        else if(nd[mid].sum < N)
            r= mid+1;
        else if(nd[mid].sum > N)
            l=mid-1;
    }
    
    //cout<<nd[l]<<" "<<nd[mid]<<" "<<nd[r]<<endl;
    return nd[mid].num;
}

int main(){

    int Q,idx=0;
    int TY, X, Y;
    bool flag = false;
    cin>>Q;
    while(Q--){

        cin>>TY;
        
        if(TY==1){
            cin>>X>>Y;
            //cout<<TY<<" "<<X<<" "<<Y<<endl;
            flag = true;
            nd[idx].num=X;
            nd[idx].qty=Y;
            nd[idx].sum=0;
            idx+=1;
        }else{
            cin>>N;
            //cout<<TY<<" "<<X<<" "<<Y<<endl;

            if(flag==true){
                pflag= true;
                msrt(0, idx-1);
            }else{
                cout<<bsrch(0, idx-1)<<endl;
            }

            flag = false;

            //for(int i=0; i<idx; i++)
             // cout<<nd[i].num<<" "<<nd[i].qty<<" "<<nd[i].sum<<endl;
        }
    }

    return 0;
}