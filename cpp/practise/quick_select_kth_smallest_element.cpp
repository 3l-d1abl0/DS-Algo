#include<bits/stdc++.h>

using namespace std;


int part(int arr[], int start, int endd){

    int pvt = endd, pval = arr[pvt];
    cout<<"pvt_ele :: "<<pvt<<" :: "<<pval<<endl;
    int l= start, r=endd;

    while(l<r){

        while( arr[l]<=pval && l<=endd)
            l++;

        while( arr[r]>pval && r>=start)
            r--;

        if(l<r)
            swap(arr[l], arr[r]);

            for(int i=0; i<7;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }

    swap(arr[pvt], arr[r]);
    cout<<"Returning = "<<r<<endl;
    for(int i=0; i<7;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    return r;
}

int randomPartition(int arr[], int l, int r){
    int n = r-l+1;
    int rnd = rand(); cout<<"RND = "<<rnd<<" n= "<<n<<endl;
    int pivot = rnd % n;
    cout<<"pvt "<<pivot<<" "<<arr[pivot]<<endl;
    cout<<l+pivot<<" == "<<r<<endl;
    swap(arr[l + pivot], arr[r]);
    return part(arr, l, r);
}

int kthSmallest(int arr[], int left, int right, int K){

        cout<<"left :: "<<left<<"  right :: "<<right<<endl;

        if(K>=left && K<= right){

            //int pos = part(arr, left, right);
             int pos = randomPartition(arr, left, right);
            cout<<"POS  :: "<<pos<<endl;
            if(pos == K){
              //for(int i=left; i<=right; i++)
                cout<<"POS:: "<<pos<<" :: "<<arr[pos]<<" ";
                return arr[pos];
            }

            if(pos > K)
                return kthSmallest(arr, left, pos-1, K);

            return kthSmallest(arr, pos+1, right, K);
        }

        return INT_MAX;
}


int main(){

    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 5;

    cout<<"K= "<<k<<endl;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);

    cout<<endl<<"Array ::"<<endl;
    sort(arr, arr+n);

    for(int i=0; i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}
