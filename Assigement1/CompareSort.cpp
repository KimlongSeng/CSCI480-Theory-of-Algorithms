#include <iostream>
using namespace std;
#inculde <time.h>

void insertion_sort(int a[], int size)
{
    int i,k,j;
    for(i=1; i<size; i++)
    {
        k = a[i];
        j = i - 1;
        while(j>= 0 && a[j] > k )
        {
            a[j+1] = a[j];
            j = j -1;
        }
        a[j+1] = k ;
    }
}
void V2insertion_sort(long long int b[], int size)
{
    int i,k,j;
    for(i=0; i<size; i++)
    {
        k = b[i];
        j = i - 1;
        while(j>= 0 && b[j] > k )
        {
            b[j+1] = b[j];
            j = j -1;
        }
        b[j+1] =k ;
    }
}
void merge(int a[],int l,int m,int r )
{
    int i, j, k;
    int p = m - l + 1;
    int q = r - m ;
    int L[p], R[q];
    for (i=0;i<p;i++)
    {
        L[i]=a[l+i];
    }
    for (j=0;j<q;j++)
    {
        R[j]=a[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while (i<p && j<q)
    {
        if (L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
       while (i < p) { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < q) { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
   
}
void merge_sort(int a[],int l,int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void V2merge(long long int a[],int l,int m,int r )
{
      int i, j, k;
    int p = m - l + 1;
    int q = r - m ;
    int L[p], R[q];
    for (i=0;i<p;i++)
    {
        L[i]=a[l+i];
    }
    for (j=0;j<q;j++)
    {
        R[j]=a[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while (i<p && j<q)
    {
        if (L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
       while (i < p) { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < q) { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
   
}
void V2merge_sort(long long int a[],int l,int r)
{
    if (l < r)
    {
        int m =l + (r-l)/2;
        V2merge_sort(a,l,m);
        V2merge_sort(a,m+1,r);
        V2merge(a,l,m,r);
    }
}

int evenodd()
{
    int q = rand() % 2;
    if (q > 0)
    {
        return 1;
    }
    else return -1;
}

int main()
{
     
    int size = 0, k;
    cout << "What is the size of array?"<<endl;
    cin >> size;
   
    long long int *b=NULL , *b1 =NULL;
    b = new long long int[size +1];
    b1 =new long long int[size +1];
    int* a = NULL;
    int* a1 = NULL;
    a = new int[size+ 1];
    a1= new int[size+ 1];
    
    clock_t begin, end;
    double time1,time2,time3,time4;

   
    int iupbound = 2147483646;
   long long  int Long_intupb =9223372036854775807;
    srand(700452202);
    int range_int; 
    long long int range_longint ;
    for (int i=0 ; i <= size;i++)
    {
        range_int = (rand() % iupbound) * evenodd();
        a[i] = range_int;
        a1[i] = a[i];
        range_longint = (rand() % Long_intupb) * evenodd();
        b[i] = range_longint;
        b1[i] = b[i];
        range_int = 0;
        range_longint =0;
    }

    begin = clock();
    insertion_sort(a,size);
    end = clock();
    time1 = (double)(end-begin)/CLOCKS_PER_SEC;

    begin = clock();
    merge_sort(a1,0,size-1);
    end = clock();
    time2 =(double)(end-begin)/CLOCKS_PER_SEC;

    begin = clock();
    V2insertion_sort(b,size);
    end = clock();
    time3 = (double)(end-begin)/CLOCKS_PER_SEC;

    begin = clock();
    V2merge_sort(b1,0,size-1);
    end = clock();
    time4 =(double)(end-begin)/CLOCKS_PER_SEC;
    
    cout << "Time spend on insertion sort (using int) = "<< time1 <<endl;
    cout << "Time spend on merge sort (using int)  = "<< time2 <<endl;
    cout << "Time spend on insertion sort (using long int) = "<< time3 <<endl;
    cout << "Time spend on merge sort (using long int)  = "<< time4 <<endl;

    delete []a;
    a = NULL;
    delete []a1;
    a1 = NULL;
    delete []b1;
    b1 = NULL;
    delete []b;
    b = NULL;
    return 0;
}