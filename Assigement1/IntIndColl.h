#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_
template<class T>
class IntIndColl
{
public:
// constructor - uses default argument so only one needed
    IntIndColl(T sz = 100);
    ~IntIndColl(); // destructor
    void Store(int,T); // store in index a value
    TRetrieve(int) const ; // retrieve from index
    void Copy(const IntIndColl&); // copy an array
   
    T& operator[](int index);
     IntIndColl(const IntIndColl& source);
    
    private:
    T *collection; // pointer to the array itself
    int size; // total size of array
};
    #endif