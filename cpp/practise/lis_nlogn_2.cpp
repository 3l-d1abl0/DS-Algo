//tonynater - HackerRank 2013

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define sz(x) ((int) x.size())

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = acos(-1);
const double tau = 2*pi;
const double epsilon = 1e-6;

const int INF = 1<<30;

const int MAX_N = 1000100;

int N;

int A[MAX_N];

int mnEnd[MAX_N]; int mxLIS;

int main (int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> A[i];

    fill_n(mnEnd, MAX_N, INF);

    for(int i = 0; i < N; i++)
    {
        int low = 0, high = mxLIS;
        while(low < high-1)
        {
            int mid = (low+high)/2;
            if(mnEnd[mid] < A[i]) low = mid;
            else high = mid;
        }

        if(mnEnd[low] < A[i]) mnEnd[low+1] = min(A[i], mnEnd[low+1]);
        else mnEnd[low] = A[i];

        if(mnEnd[mxLIS] != INF) ++mxLIS;
    }

    cout << mxLIS << '\n';

    return 0;
}
