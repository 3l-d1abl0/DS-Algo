#include<bits/stdc++.h>

using namespace std;

stack<int> st;

void insert_bottom(int num){

    if(st.empty()){
        st.push(num);
    }else{

        int tp = st.top();
        st.pop();

        insert_bottom(num);

        st.push(tp);
    }
}

void reverse(){


    if(st.size()>0){
        int tp = st.top();
        st.pop();
        reverse();


        insert_bottom(tp);
    }
}


int main(){

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout<<"Stack Top to Bottom :: "<<endl;
    cout<<"1 2 3 4 5"<<endl;

    reverse();

    cout<<"Stack reversed :: "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;
}
