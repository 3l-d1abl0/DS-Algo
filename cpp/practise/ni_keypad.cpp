// Name: Sameer Barha
// Summary:

#include <iostream>
#include<vector>

using namespace std;

// Remove additional cin/cout before submission
string DecodeMessage(string message){
	/* Write your code here. */

	vector<vector<char> > keypad {  { '.', '1' },
                                                                {'a','b','c','2'},
                                                                {'d', 'e', 'f','3'},
                                                                {'g', 'h', 'i', '4'},
                                                                {'j','k','l','5' },
                                                                {'m', 'n', 'o', '6'},
                                                                {'p', 'q', 'r', 's', '7' },
                                                                { 't', 'u', 'v', '8'},
                                                                {'w', 'x', 'y', 'z', '9'},
                                                                { ' ', '0'} };

    int stLen = message.length();
    for(int i=0; i<stLen; i++){
        cout<<message[i];
    }


    return "123";
}

/* Do not modify the main() function */
int main(void) {
	string cipherMessage;
	cin >> cipherMessage;
    cout << DecodeMessage(cipherMessage) << endl;
	return 0;
}
