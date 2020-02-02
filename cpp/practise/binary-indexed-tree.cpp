#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class BIT{

    public:

        BIT(vector<int> arr, int n){

            bit_array = vector<int>(n+1, 0);

            for(int i=1; i<=n; i++){

                int idx = i;
                while(idx<=n){
                    bit_array[idx] +=arr[i-1];
                    idx += idx &(-idx);
                }
            }

            for(int i=0; i<=n; i++){
                cout<< std::setw(2)<< bit_array[i]<<" ";
            }

            cout<<endl;

        }

        int prefix_query(int idx){
            idx +=1;
            int sum =0;

            while(idx> 0){
                sum += bit_array[idx];
                cout<<sum<<"==>"<<idx <<endl;
                idx -= idx & (-idx);
            }

            return sum;
        } //prefix_query

        int range_query(int from_idx, int to_idx){

            if(from_idx ==0)
                return prefix_query(to_idx);
            else
                return (prefix_query(to_idx) -  prefix_query(from_idx));
        } //range_query

        //int update(int idx, int value)


    private:

        vector<int> bit_array;

};

void print(BIT &bit, int n) {


    //std::cout << "Prefix sum of first 13 elements: \t" << bit.range_query(0,12) << std::endl;
	//std::cout << "Prefix sum of first 7 elements: \t" << bit.prefix_query(6) << std::endl;
	std::cout << "Range sum from index 1 to index 5: \t" << bit.range_query(1, 5) << std::endl;
    std::cout << std::endl;
}

int main(){

    vector<int> arr{ 1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5 };
    int n = arr.size();

    //BIT bit = new BIT(array, n);

    BIT bit(arr, n);

    print(bit, n);



    return 0;
}

