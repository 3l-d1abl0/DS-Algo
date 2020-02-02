#include <iostream>
using namespace std;

int next_power_of_2(unsigned int n)
{
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int N,x,result;
        cin>>N;
        int max = -1;
        for(int i=0;i<N;i++){
            cin>>x;
            if(x>max){
                max = x;
            }
        }
        result = next_power_of_2(max);
        cout<<max<<endl;
        cout<<result<<endl;
    }
    return 0;
}
