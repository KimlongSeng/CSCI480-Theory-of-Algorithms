#include "IntIndColl.h"
#include <stdlib.h>
#include <iostream>



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
        std::cerr << "\nERROR: index is out of range\n";
        exit(1);
      }
    collection[index] = value;
}
int IntIndColl::Retrieve(int index) const
{
    if ((index < 0) || (index > size-1))
    {
        std::cerr << "\nERROR: index is out of range\n";
        exit(1);
    }
    return collection[index];
}
void IntIndColl::Copy(const IntIndColl& source)
{
    if (source.size > size)
{
    std::cerr << "\nERROR: collection too large\n";
    exit(1);
}
    for (int i=0;i<source.size;i++)
    collection[i] = source.collection[i];
}

int main()
{
    void Store(int,int); // store in index a value
    int Retrieve(int) ; // retrieve from index
    void Copy(const IntIndColl&);
}

// int& IntIndColl::operator[](int index)
// {
//     if ((index < 0) || (index > size-1))
//     {
//         std::cerr << "\nERROR: index is out of range\n";
//         exit(1);
//     }
//     return collection[index];
// }

// IntIndColl::IntIndColl(const IntIndColl& source)
// {
//     size = source.size;
//     collection = new int[size]; // new space
//     for (int i=0;i<source.size;i++)
//     collection[i] = source.collection[i];
// }

