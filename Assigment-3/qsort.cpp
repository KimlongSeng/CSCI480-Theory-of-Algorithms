/*
step2:
    improvement to quicksort
    middle of 3 : https://tutorialspoint.dev/language/cpp/middle-of-three-using-minimum-comparisons
    kth element code from: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/


*/

#include "qsort.h"
using namespace std;

int kthValue(int arr[], int index[], int low, int high, int k) { 
    if (k > 0 && k <= high - low + 1) {

        int pos = increasing_partition(arr, index, low, high); 

        if (pos-low == k-1) 
            return arr[index[pos]]; 
        if (pos-low > k-1)
            return kthValue(arr, index, low, pos-1, k); 

        return kthValue(arr, index, pos+1, high, k-pos+low-1); 
    }
    return INT_MAX; 
} 

void sort3(int arr[], int index[], int low, int high) {
	int a = arr[index[low]];
	int b = arr[index[high/2]];
	int c = arr[index[high]];
	if((a < b && b < c) || (c < b && b < a))
		swap(index[high/2], index[high]);
	else if((b < a && a < c) || (c < a && a < b))
		swap(index[low], index[high]);
}

int partition(int arr[], int index[], int low, int high) {
	sort3(arr, index, low, high);
	int pivot = arr[index[high]];
    int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[index[j]] >= pivot) { //changed sign to sort by decreasing
			i++;
			swap(index[i], index[j]);
		}
	}
	swap(index[i+1], index[high]);
	return i + 1;
}

int increasing_partition(int arr[], int index[], int low, int high) {
	sort3(arr, index, low, high);
	int pivot = arr[index[high]];
    int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[index[j]] <= pivot) {
			i++;
			swap(index[i], index[j]);
		}
	}
	swap(index[i+1], index[high]);
	return i + 1;
}

void increasing_quicksort(int arr[], int index[], int low, int high) {
	if (low < high) {
		int p = increasing_partition(arr, index, low, high);
		increasing_quicksort(arr, index, low, p - 1);
		increasing_quicksort(arr, index, p + 1,high);
	}
}

void quicksort(int arr[], int index[], int low, int high) {
	if (low < high) {
		int p = partition(arr, index, low, high);
		quicksort(arr, index, low, p - 1);
		quicksort(arr, index, p + 1,high);
	}
}

void num_gen(int arr[], int index[], int n) {
    srand(time(NULL));
	int i = 0;
    int random;
    while(i < n) {
        random = rand() % 10000;        
        arr[i] = random;
        index[i] = i;
        i++;
    }
}

void swap(int *a, int *b) {
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int arr[], int index[], int n) {
    ofstream out;
    out.open("sortoutput.txt");
    for(int i = 0; i < n; i++) {
       if(i > 0 && i % 10 == 0)
           out << endl;
       out << arr[index[i]] << " ";
    }
    out.close();
}