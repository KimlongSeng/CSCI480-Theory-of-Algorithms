#include "IntIndColl.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

IntIndColl::IntIndColl(int sz) // note no default value here
{
    size = sz; // should check for positive value
    collection = new int[sz];
}

IntIndColl::~IntIndColl()
{
    delete [] collection;
}

void IntIndColl::Store(int index, int value)
{
    if ((index < 0) || (index > size-1))
        {
            cerr << "\nERROR: index is out of range\n";
            exit(1);
        }
    collection[index] = value;
}
int IntIndColl::Retrieve(int index) const
{
    if ((index < 0) || (index > size-1))
        {
            cerr << "\nERROR: index is out of range\n";
            exit(1);
        }
return collection[index];
}
void IntIndColl::Copy(const IntIndColl& source)
{
    if (source.size > size)
        {
            cerr << ("\nERROR: collection too large\n");
            exit(1);
        }
    for (int i=0;i<source.size;i++)
    collection[i] = source.collection[i];
}



// Qsort

int partition1(int arr[], int start, int end, int & compr, int & move) { //select first element as pivot value
int pivot = arr[start];
int L = start + 1;
int R = end;
int temp = 0;
//int compr = 0;
//int move = 0;
while (true) {
    compr++; // !!!
    while ((L < R) && (arr[R] >= pivot)) {  //bringing R to the left
                --R;
                compr++;
    } 
compr++; // !!!
while ((L < R) && (arr[L] < pivot)) {   //bringing R to the right
        ++L;
        compr++;
    }
// the same lines to the end of function partition1, except of printing compr and move
    }
}

void quickSort(int arr[], int start, int end, int & compr, int & move) 
{
    int boundary;
    if (start < end) {
        boundary = partition1(arr, start, end, compr, move);
        quickSort(arr, start, boundary - 1, compr, move);
        quickSort(arr, boundary + 1, end, compr, move);
            } 
}

int main()
{
    ofstream outfile;
    ifstream infile;

outfile.open("Result.txt");
infile.open("RanNum.txt");

    int compr = 0;
    int move = 0;
    int count =0;
    string output;
    int list[];
 if (infile.is_open()) {
     while (!infile.eof()) {
         infile >> list[count];
         count++;
    }
}

    quickSort( {list[]}, 0, 99999, compr, move );

    cout << "Total comparison : " << compr << endl;
    cout << "Total moves : " << move << endl;



outfile.close();
return 0;
}

/*
//So, how do we use it?
int size, howmany, i, data;
// specify size of array needed
cout << "Size of array needed? ";
cin >> size;
// declare it
IntIndColl arr(size); // declare a safe array

// fill a part of the array
cout << "How much of the array is occupied?";
cin >> howmany;
for (i=0;i<howmany;i++)
    {
        cin >> data;
        arr.Store(i,data); // use the store function
    }
// test the retrieve function
cout << "Which item do you want? ";
cin >> i;
data = arr.Retrieve(i);
cout << "arr[" << i << "] = " << data << endl;









float size=0, count;
string names[size];



while (count < size) {
		getline(infile,names[count]);
		count++;
	}
cout << "Count"<< count << endl;

if ()



//So, how do we use it?
int size, howmany, i, data;
// specify size of array needed
cout << "Size of array needed? ";
cin >> size;
// declare it
IntIndColl arr(size); // declare a safe array

// fill a part of the array
cout << "How much of the array is occupied?";
cin >> howmany;
for (i=0;i<howmany;i++)
    {
        cin >> data;
        arr.Store(i,data); // use the store function
    }
// test the retrieve function
cout << "Which item do you want? ";
cin >> i;
data = arr.Retrieve(i);
cout << "arr[" << i << "] = " << data << endl;

*/