#include <iostream>
#include "qsort.cpp"

using namespace std;

int main()
{
    int n, k ;
    cout << "Enter the number of element: " <<endl;
    cin >> n;
    cout << endl;
    cout << "Enter the Kth element to find: " <<endl;
    cin >> k;
    cout << endl;
    
    int arr[n], index[n];

    num_gen(arr, index, n);
    cout  << "The" << k <<" th value is :" << kthValue(arr, index,0,n-1,k) << endl;

    auto start = chrono::steady_clock::now();
    increasing_quicksort(arr,index, 0, n-1);
    auto end = chrono::steady_clock::now();

    cout << "Time spend on kth quick sort = "<< chrono::duration_cast<chrono::microseconds>(end - start).count()<< " microsecond"<<endl;
    printArr(arr,index,n);


    return 0;
}
