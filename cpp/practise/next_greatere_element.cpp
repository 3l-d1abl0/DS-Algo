#include<bits/stdc++.h>

using namespace std;

int arr[65535];
int aux[65535];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);   aux[i]=-1;
    }

    stack<int >st;

    for(int i=0; i<n; i++){


            while( !st.empty() && arr[i]>arr[st.top()]){
                        aux[st.top()] = arr[i];
                        st.pop();
            }
            st.push(i);

    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<aux[i]<<endl;
    }

    return 0;
}
