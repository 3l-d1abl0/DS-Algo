#include<bits/stdc++.h>

using namespace std;

int cnt(int num){

    int ctr = 0;
    while(num){
        if (num & 1 )ctr+= 1;

        num = num>>1;
    }
    return ctr;
}

int priorityFun(int i,int j)
{
    int ctr = cnt(i);
    int ctr1 = cnt(j);
    if (ctr1 >= ctr)
        return true;

    return false;
}

// Complete the cardinalitySort function below.
vector<int> cardinalitySort(vector<int> nums) {

    int sz = nums.size();
    sort(nums.begin(), nums.end(), priorityFun);

    return nums;
}




int main(){

    //int arr[] = {1, 2, 3, 4, 5, 6};
    //int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> arr{ 1,2,3,4,5};
    cout<<"++++++"<<endl;
    vector<int> myvector = cardinalitySort(arr);

        cout<<"______________"<<myvector.size()<<endl;
      for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;

    return 0;

}
