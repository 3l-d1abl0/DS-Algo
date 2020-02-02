#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the primeCount function below.
 */
int primeCount(long n) {
    /*
     * Write your code here.
     */

    vector<bool > pri (sqrt(n+1) ) ;

    vector<long long> p;
    cout<<"1"<<endl;

    for(int i=0; i<=sqrt(n+1); i++)
        pri[i] = true;
    cout<<"2"<<endl;
    for(int i=2; i*i<=sqrt(n+1); i++){

        if(pri[i]==true){

            for(int j=i*2; j<=sqrt(n+1); j+=i)
                pri[j] = false;

            p.push_back(i);
        }
    }
    cout<<"3 :: "<<p.size()<<endl;

    int ctr=0;
    unsigned long long int prod=1;
    for(int i=0; i<p.size(); i++){
    cout<<"pro"<<prod*p[i]<<endl;
        if (prod*p[i]<=n){

            ctr++;
        }else{
            break;
        }
    }
    cout<<"4"<<endl;
    return ctr;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = primeCount(n);

        cout <<"RES: " <<result << "\n";
    }

    fout.close();

    return 0;
}
