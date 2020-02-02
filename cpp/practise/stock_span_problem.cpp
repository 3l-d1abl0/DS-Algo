#include<bits/stdc++.h>

using namespace std;

void stockSpan(int pr[], int sz){

    stack<int > st;
    st.push(0);
    cout<<"1,";
    for(int i=1; i<sz;i++){

        while(!st.empty() && (pr[st.top()]<pr[i]) )
            st.pop();

        if(st.empty()){
            cout<<i+1<<"_";
        }else{
            cout<<i-st.top()<<",";
        }

        st.push(i);
    }


}

int main(){

    //int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int arr[] = {10, 4, 5, 90, 120, 80};
    //int arr[]={8,9,10,1,7,15,14,21};
    //int arr[]= {11, 13, 21, 3};

	int size=sizeof(arr)/sizeof(arr[0]);
    stockSpan(arr,size);

    return 0;
}
