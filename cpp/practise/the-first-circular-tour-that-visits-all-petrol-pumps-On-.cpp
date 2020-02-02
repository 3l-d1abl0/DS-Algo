#include<bits/stdc++.h>

using namespace std;

class petrolPump
{
	public:
	int petrol;
	int distance;
};

int getTour(petrolPump arr[], int sz){

    int surplus =0, deficit =0;
    int start_idx =0;
    for(int i=0; i<sz; i++){
        //cout<<"> "<<arr[i].petrol<<" "<<arr[i].distance<<endl;
        surplus += arr[i].petrol - arr[i].distance;
        if(surplus < 0){
            deficit +=surplus;
            surplus =0;
            start_idx = i+1;
        }
        //cout<<surplus<<" "<<deficit<<endl;
    }
    //cout<<surplus<<" "<<deficit<<endl;
    return (surplus+deficit>=0) ? start_idx : -1;
}

int main(){

    	//petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}, {4,5}};
        //petrolPump arr[] = {{6, 2}, {3, 14}, {7, 6}, {11, 9}};

        petrolPump arr[] = { {2, 4},  {3,5}, {4,1}, {5,2}, {1,3}};

    int sz = sizeof(arr)/sizeof(arr[0]);

    int start_idx = getTour(arr, sz);

    if (start_idx == -1)
        cout<<"No Solution "<<endl;
    else
        cout<<"Pump Index to Start : "<<start_idx<<endl;

    return 0;
}
