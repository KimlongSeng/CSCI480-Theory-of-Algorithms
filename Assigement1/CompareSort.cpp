#include <iostream>
#include <fstream>
using namespace std;




void insertion_sort( int a[], int size)
{
    int i,k,j;
    for(i=0; i<size; i++)
    {
        k = a[i];
        j = i - 1;
        while(j>= 0 && a[j] > k )
        {
            a[j+1] = a[j];
            i = j -1;
        }
        a[j+1] =k ;
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
            i = j -1;
        }
        b[j+1] =k ;
    }
}


void merge(int a[],int l,int m,int r )
{
    int i, j, k;
    int p = m-l +1;
    int q = r - m ;
    int L[p], R[q];
    for (i=0;i<p;i++)
    {
        L[i]=a[l+i];
    }
    for (j=0;j<q;j++)
    {
        R[j]=a[r+1];
    }
    i=0,j=0,k=l;
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
    if (i = p)
    {
        a[k]=R[j];
        j++;
        k++;
    }
    else
    {
        a[k]=L[i];
        i++;
        k++;
    }
}

void merge_sort(int a[],int l,int r)
{
    if (l < r)
    {
        int m =l + (r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void V2merge(long long int b[],int l,int m,int r )
{
    int i, j, k;
    int p = m-l +1;
    int q = r - m ;
    int L[p], R[q];
    for (i=0;i<p;i++)
    {
        L[i]=b[l+i];
    }
    for (j=0;j<q;j++)
    {
        R[j]=b[r+1];
    }
    i=0,j=0,k=l;
    while (i<p && j<q)
    {
        if (L[i]<=R[j])
        {
            b[k]=L[i];
            i++;
        }
        else
        {
            b[k]=R[j];
            j++;
        }
        k++;
    }
    if (i = p)
    {
        b[k]=R[j];
        j++;
        k++;
    }
    else
    {
        b[k]=L[i];
        i++;
        k++;
    }
}
void V2merge_sort(long long int b[],int l,int r)
{
    if (l < r)
    {
        int m =l + (r-l)/2;
        V2merge_sort(b,l,m);
        V2merge_sort(b,m+1,r);
        V2merge(b,l,m,r);
    }
}

int main()
{
     ifstream  inf("ForSortNum.txt");
    int size = 0, k, flag=0 ,i;
    long long int *b=NULL;
    b = new long long int[2000000];
    int*a =NULL;
    a = new int[2000000];

    while (!inf.eof())
    {
        inf >> a[size];
        size++;
    }





    delete []b;
    b = NULL;
    delete []a;
    a = NULL;
    inf.close();
    return 0;
}