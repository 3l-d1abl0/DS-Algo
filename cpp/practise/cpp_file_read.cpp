#include<bits/stdc++.h>

using namespace std;

void readFile()
{
    ifstream file;
    file.open ("program.txt");
    if (!file.is_open()) return;

    string word;
    while (file >> word)
    {
        cout<< word << '\n';
    }
}


int main(){

    readFile();

    return 0;
}
