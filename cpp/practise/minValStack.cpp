#include<bits/stdc++.h>

using namespace std;

class cusStack{

    stack <int> st;
    int minVal;

public:
    void push(int num);
    void pop();
    int getMin();

};

void cusStack::push(int num){

    if(st.empty()){
        st.push(num);
        return;
    }

    if(num < minVal){
        st.push(2*num - minVal);
        minVal = num;
        return;
    }
    else
        st.push(num);

    cout<<"Pushed"<<endl;

}

void cusStack::pop(){

    if(st.empty()){
        cout<<"Empty Stack !"<<endl;
    }

    int tt = st.top();
    st.pop();

    if(tt<minVal){
        minVal = 2*minVal -tt;
    }
    cout<<"Popped Element :: "<<tt<<endl;
}


int cusStack::getMin(){

    return minVal;
}

int main(){

    cusStack st;

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(23);
    cout<<st.getMin()<<endl;
    st.push(2);
    st.push(4);
    cout<<st.getMin()<<endl;
    st.pop();
    st.pop();
    cout<<st.getMin()<<endl;


    return 0;
}
