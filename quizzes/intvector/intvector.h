#ifndef INTVECTOR_H
#define INTVECTOR_H

/*  See vector<T> reference at
 *  http://www.cplusplus.com/reference/vector/vector/
 *
 *  This class declaration omits or simplifies some members prescribed for
 *  STL containers, to make it more accessible to students.
 *
 *  A production-ready container should probably include all the prescribed
 *  members for portability and reusability, and so that main program
 *  code does not have to be rewritten if you choose to change the
 *  container type.
 */

class IntVector
{
public:
    //  Object management
    IntVector();                                   //  Default constructor
    IntVector(const int& n, const int& val);       //  Fill constructor
    IntVector(const IntVector& other);             //  Copy constructor
    ~IntVector();                                  //  Destructor
    IntVector& operator=(const IntVector& other);  //  Assignment operator

    //  Iterators
    int* begin();               //  Pointer to first element
    int* end();                 //  Pointer to AFTER last element (OOB)
    const int* cbegin() const;  //  const pointer to first element
    const int* cend() const;    //  const pointer to after last element

    //  Capacity
    int size() const;           //  How many ints represented in vector
    void resize (int n);        //  Changes number of ints represented
    int capacity() const;       //  Actual size of array (capacity >= size)
    bool empty() const;         //  size == 0 ?
    void reserve(int n);        //  Increase actual size of array
    void shrink_to_fit();       //  Decrease actual size of array
                                //      Note: reserve() and shrink_to_fit()
                                //      are requests; in reality, they
                                //      might do nothing.

    //  Element access
    int& operator[](int pos);   //  No bounds check.  Cano go OOB.
    int& at(int pos);           //  Terminates program if OOB
    int& front();               //  Reference to first element
    int& back();                //  Reference to last element
    int* data();                //  Pointer to raw array
                                //      Note: may contain garbage values
                                //      at the end that are ignored by the
                                //      class members.

    //  Modifiers
    void push_back(const int& val);  //  Insert val at end of vector
    void pop_back();                 //  Forget last element exists
                                     //      Note: the STL vector<int>
                                     //      actually destroys the last
                                     //      element.
    void insert(const int& pos, const int& val);  //  Insert at pos
    void erase(const int& pos);                   //  Remove int at pos
    void clear();                                 //  Empties vector

private:
    int* data_ = nullptr;
    int size_ = 0;
    int capacity_ = 0;
};

#endif
