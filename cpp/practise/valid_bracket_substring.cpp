#include<bits/stdc++.h>


using namespace std;

int findLen(string str, int len){

    stack<int> stk;
    stk.push(-1);

    int result =0;

    for(int i=0; i<len; i++){

            if(str[i]=='('){
                    stk.push(i);    cout<<"pushing "<<i<<endl;
            }else{
                    stk.pop();

                    if(!stk.empty()){
                        //result = max(result, i-stk.top());
                        if(i-stk.top() > result){
                            cout<<i<<" - "<<stk.top()<<" = "<<i-stk.top()<<endl;
                            result = i-stk.top();
                            cout<<"Result :: "<<result<<endl;
                        }
                    }else{
                        cout<<"push..."<<i<<endl;
                        stk.push(i);
                    }
            }
    }

    return result;
}

int main(){

    //string str = "(()())";
    //string str = "((()";
    string str = ")()())";
    //string str = "()(()))))";

    int len = str.length();
    cout<<"String Length :: "<<len<<endl;
    cout<<"Length :: "<<findLen(str, len)<<endl;

    return 0;
}
