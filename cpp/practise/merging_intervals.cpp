#include<bits/stdc++.h>

using namespace std;

struct Interval{
    int start, end;
};

bool newComp(Interval i1, Interval i2){
    return (i1.start < i2.start);
}
void mergeIntervals(Interval arr[], int n){

    if(n<=0)
        return;

    sort(arr, arr+n, newComp);

    //for(int i=0; i<n;i++)
        //cout<<arr[i].start<<"  "<<endl;

    stack<Interval> st;

    st.push(arr[0]);
    Interval topOne;

    for(int i=1; i<n;i++){
            topOne = st.top();

            if(arr[i].start < topOne.end){
                    if(arr[i].end > topOne.end){
                            st.pop();
                            topOne.end = arr[i].end;
                            st.push(topOne);
                    }
            }else{
                st.push(arr[i]);
            }
    }

    while(!st.empty()){
            Interval temp = st.top();
            st.pop();

            cout<<"[ "<<temp.start<<" , "<<temp.end<<" ]"<<endl;

    }

}


int main(){

     Interval arr[] =  { {6,8}, {1,9}, {2,4},{11,19}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);

    return 0;
}
