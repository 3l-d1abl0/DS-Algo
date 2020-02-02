#include<bits/stdc++.h>

using namespace std;

class cusStack{

    stack <int> st;
    int maxVal;

public:
    void push(int num);
    void pop();
    int getMax();

};

void cusStack::push(int num){

    if(st.empty()){
        st.push(num);
        maxVal = num;
    }

    if(num<maxVal)
        st.push(num);
    else{
        st.push(num+maxVal);
        maxVal = num;
    }

}

int getMax(){
    return maxVal;
}

int main(){


    return 0;
}
