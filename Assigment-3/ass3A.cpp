  
//quickSort algorithm source: https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/tutorial/

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition( int arr[], int index[],int low, int high)
{
    int p = arr[index[low]]; // making the first elemnt pivot
    int low_to_high = low + 1;

    for (int i = low_to_high; i <= high;i++)
    {
        if (arr[index[low_to_high]] < p )
        {
            swap(index[low_to_high],index[i]);
            low_to_high++;
        }
    }
        swap(index[low], index[low_to_high-1]); //put the pivot element in its proper place.
        return low_to_high - 1; // return pivot position
}
void quicksort( int arr[],int index[], int low, int high)
{
    if (low <high)
    {
        int p = partition(arr, index, low, high);//stores the position of pivot element
        quicksort(arr, index,low, p-1);//sorts the left side of pivot.
        quicksort(arr, index, p+1, high);//sorts the right side of pivot.
    }

}

void num_gen(int arr[], int index[] ,  int n)
{
    srand(700452202);
    int i = 0;
    int random;
    while(i < n) {
        random = rand() % 100000;        
        arr[i] = random;
        index[i] = i;
        i++;
    }

}
void printArr(int arr[], int index[], int n)
{
    ofstream out;
    out.open("QsortOutput.txt");
    for(int i = 0; i < n; i++) {
       if(i > 0 && i % 10 == 0)
       out << endl;
       out << arr[index[i]] << " ";
    }
    out.close();
}

int main()
{
    int n;
    cout << "Enter The element number: ";
    cin >> n;
    int arr[n], index[n];
    num_gen(arr,index,n);


    auto start = chrono::steady_clock::now();
    quicksort(arr,index,0,n-1);
    auto end = chrono::steady_clock::now();
    
    cout << "Time spend on quick sort = "<< chrono::duration_cast<chrono::microseconds>(end - start).count()<< " microsecond"<<endl;
    printArr(arr,index,n);
    return 0;

}