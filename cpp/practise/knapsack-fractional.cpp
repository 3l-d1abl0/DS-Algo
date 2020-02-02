#include<bits/stdc++.h>

using namespace std;

//In Fractional Knapsack, we can break items for maximizing the total value of knapsack. 

struct Item 
{ 
    int value, weight; 
  
    // Constructor 
    /*Item(int value, int weight) : value(value), weight(weight) 
    {}*/

    Item(int val, int wt){
        value = val;
        weight = wt;
    } 
}; 


bool customComp(Item a, Item b){
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;

    return r1>r2;
}

double fractionalKnapsack(int W, Item arr[], int n){

    sort(arr, arr+n, customComp);

    int wtSum = 0;
    double valueSum = 0.0;

    for(int i=0; i<n; i++){

        if(wtSum +arr[i].weight <=W){
            wtSum +=arr[i].weight;
            valueSum += arr[i].value;
        }else{

            int remaining_weight = W-wtSum;
            valueSum += (double)remaining_weight * (double)arr[i].value/arr[i].weight;

            return valueSum;
        }

    }
}

int main(){

    int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n)<<endl;
    return 0; 

    return 0;
}