#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
#include <climits>
#include <chrono>


void swap(int *a,int *b);
void sort3(int arr[], int index[], int low, int high);
int partition( int arr[], int index[],int low, int high);
int increasing_partition(int arr[], int index[], int low, int high);
int kthValue(int arr[], int index[], int low, int high, int k);
void increasing_quicksort(int arr[], int index[], int low, int high);
void quicksort( int arr[],int index[], int low, int high);
void num_gen(int arr[], int index[] ,  int n);
void printArr(int arr[], int index[], int n);