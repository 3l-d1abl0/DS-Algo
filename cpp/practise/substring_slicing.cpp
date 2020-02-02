/*
// Sample code to perform I/O:
*/
#include <iostream>

using namespace std;

bool checkPalindrome(string str){
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length();

    //cout<<"->"<<str<<endl;
    for(int i=0; i<h/2; i++){

        if(str[i] != str[h-i-1])
            return false;
    }

    return true;
}

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	//cout << "Input number is " << num << endl;		// Writing output to STDOUT
	string str;
	while(num--){
	    cin>>str;
	    int len = str.length();

	    bool flag = false;
	    for(int i=0; i<len; i++){

	        if(checkPalindrome( str.substr(i+1)+str.substr(0,i+1) )){
	            flag = true;
	            break;
	        }
	    }

	    if(flag)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;

	}
}

/*
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

