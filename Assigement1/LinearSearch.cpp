#include <iostream>
#include <fstream>
using namespace std;

int linearSearch(int a[],int size,int k)
{
int i = 1;
bool found = false;
while (i <= size && found == false)
{
    if (a[i] == k )
    {
        found = true;
        cout <<"Element  found at location : "<< i + 1<<endl;
    };
   i++;
}
if (found == false) {cout<<"Element not found" << endl;}
return found;
}

int BothWay_LinearSearch(int  a[],int size,int k)
{
    int front = 0, back = size - 1;
    bool found =false;
    while (front <= back && found == false)
    {
        if (a[front] == k || a[back] == k)
        {
            found =true;
            cout <<"Element founded " <<endl;
        };
            front++;
            back--;
    }
    if (found == false) {cout<<"Element not found" << endl;}
    return found;
}


int main()
{
    ifstream  inf("RanNum.txt");
    int size = 0, k, flag=0 ,i;
    int*a =NULL;
    a = new int[2000000];
    bool found =false;
while (!inf.eof())
{
    inf >> a[size];
    size++;
}
cout << "Please enter the number that you want to search for : ";
cin >> k;
BothWay_LinearSearch(a,size,k);

delete []a;
a = NULL;
inf.close();
    return 0;
}