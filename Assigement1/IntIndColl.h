#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_
class IntIndColl
{
public:
// constructor - uses default argument so only one needed
    IntIndColl(int sz = 100);
    ~IntIndColl(); // destructor
    void Store(int,int); // store in index a value
    int Retrieve(int) const ; // retrieve from index
    void Copy(const IntIndColl&); // copy an array
    // int& operator[](int index);
    // IntIndColl(const IntIndColl& source);
    
    private:
    int *collection; // pointer to the array itself
    int size; // total size of array
};
    #endif