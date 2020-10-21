/*
    middle of 3 : https://tutorialspoint.dev/language/cpp/middle-of-three-using-minimum-comparisons
*/
#include <iostream>
#include <fstream>

using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort3(int arr[], int index[], int low, int high)
{
    int a= arr[index[low]];
    int b = arr[index[high/2]];
    int c = arr[index[high]];
    if((a < b && b < c) || (c < b && b < a))
		swap(index[high/2], index[high]);
	else if((b < a && a < c) || (c < a && a < b))
		swap(index[low], index[high]);

}



int partition( int arr[], int index[],int low, int high)
{
    sort3(arr,index,low,high);
    int p = arr[index[high]]; // making the last elemnt pivot
    int high_to_low = low - 1;

    // sorting by decreasing from high to low
    for (int i = low; i <= high;i++)
    {
        if (arr[index[high_to_low]] >= p )
        {
            high_to_low++;
            swap(index[high_to_low],index[i]);
        }
    }
        swap(index[high_to_low +1], index[high]); 
        return high_to_low + 1; // return pivot position
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