#include <iostream>
#include <fstream>
using namespace std;



// int size, howmany, i, data;
// // specify size of array needed
// std::cout << "Size of array needed? ";
// std::cin >> size;
// // declare it
// IntIndColl arr(size); // declare a safe array

// // fill a part of the array
// std::cout << "How much of the array is occupied?";
// std::cin >> howmany;
// for (i=0;i<howmany;i++)
// {
// std::cin >> data;
// arr.Store(i,data); // use the store function
// }
// // test the retrieve function
// std::cout << "Which item do you want? ";
// std::cin >> i;
// data = arr.Retrieve(i);
// std::cout << "arr[" << i << "] = " << data << endl;



int linearSearch(long long int  a[],int size,int k)
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

int BothWay_LinearSearch(long long int  a[],int size,int k)
{
    int front = 0, back = size - 1;
    bool found =false;
    while (front <= back && found == false)
    {
        if (a[front] == k || a[back] == k)
        {
            found =true;
            cout <<"Element  found at location : "<< front + 1 <<endl;
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
    long long int a[100000];
    int size = 0, k, flag=0 ,i;
    bool found =false;
while (!inf.eof())
{
    inf >> a[size];
    size++;
}
cout << "Please enter the number that you want to search for : ";
cin >> k;
BothWay_LinearSearch(a,size,k);

inf.close();
    return 0;
}