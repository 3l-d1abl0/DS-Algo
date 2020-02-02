#include<bits/stdc++.h>

using namespace std;

template <class T>
// A function to implement bubble sort
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])

        // calls template function
        swap1(a[j], a[j - 1]);
}

template <class X>
// A Function to perform swapping
void swap1(X &a, X &b) {
    X temp = a;
    a = b;
    b = temp;
}

// Driver Code
int main() {
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);

    // calls template function
    /*bubbleSort(a, 5);

    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    */
    int c=1, b=2;
    cout<<c<<" "<<b<<endl;
    swap1(c,b);
    cout<<c<<" "<<b<<endl;

    char aa='aa'; char bb='bb';
    swap1(aa,bb);
    cout<<aa<<" "<<bb<<endl;

  return 0;
}
