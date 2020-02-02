#include<bits/stdc++.h>

using namespace std;

void nextGreaterElement(int arr[], int sz){
    stack<int> st;

    st.push(arr[0]);

    for(int i=1; i<=sz-1; i++){

        while( !st.empty() && st.top() < arr[i] ){
            cout<<st.top()<<"  -->"<<arr[i]<<endl;
            st.pop();
        }

        st.push(arr[i]);
    }

    while(!st.empty()){
        cout<<st.top()<<" -->  -1"<<endl;
        st.pop();
    }

}

int main(){

    int arr[]={8,9,10,1,7,15,14,21};
    //int arr[]= {11, 13, 21, 3};

	int size=sizeof(arr)/sizeof(arr[0]);
    nextGreaterElement(arr,size);

    return 0;
}
