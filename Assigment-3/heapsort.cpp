
// heapsort source: https://www.geeksforgeeks.org/heap-sort/


#include <iostream> 
#include <fstream>
#include "heapsort.h"
#include "hashTable.cpp"
  
using namespace std; 

void heapify(int arr[], int index[] , int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[index[l]] > arr[index[largest]]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[index[r]] > arr[index[largest]]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[index[i]], arr[index[largest]]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, index,n, largest); 
    } 
} 

void heapSort(int arr[],int index[]  , int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, index, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i > 0 ; i--) 
    { 
        // Move current root to end 
        swap(arr[index[0]], arr[index[i]]); 
  
        // call max heapify on the reduced heap 
        heapify(arr,index, i, 0); 
    } 
} 
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }


void sorttable() {
	ifstream in;
	in.open("output.txt");
	int numArr[7000];
	string strArr[7000];
	int index[7000];
	string trash;
	int i = 0;
	string temp;
	int tempcount;
	while(in >> temp) {
		in >> tempcount;
		in >> trash;
		temp.erase(temp.length()- 1, temp.length()); //erase the : after each word
		strArr[i] = temp;
		numArr[i] = tempcount;
		index[i] = i;
		i++;
	}
	in.close();


	heapsort(numArr,index,7000-1);
	
	ofstream out;
	ofstream out1;
    out.open("CommonUsedWord.txt");
	out1.open("UnCommonUsedWord.txt");

	 for(int v = 6700; v < 7000; v++)
	{
		v++;
		out1 << strArr[index[v]] << ": " << numArr[index[v]] << endl; 
	}

    for(int j = 0; j < 150; j++)
	{
       out << strArr[index[j]] << ": " << numArr[index[j]] << endl;    
	}
	out1.close();
	out.close();
}