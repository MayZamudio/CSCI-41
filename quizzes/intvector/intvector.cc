#include "intvector.h"
#include <cstdlib> //  exit()

const double expansion = 1.5;
const int default_size = 10;
const int fill_val = 0;

////
//
//  Object Management
//
////

/*  IntVector iv;
 *  IntVector iv();
 *
 *  Default constructor
 */
IntVector::IntVector()
{
	new int[default_size];
	size_ = 0;
	capacity_ = default_size;

}

/*  IntVector iv(n);
 *  IntVector iv(n, val);
 *
 *  Fill constructor
 *  Creates a new vector of size n.  If val is specified, all elements will
 *  be initialized to val; otherwise, they will be initialized to fill_val.
 */
IntVector::IntVector(const int& n, const int& val = fill_val)
{
	capacity_ = n * expansion;
	data_ = new int [capacity_];
	size_ = n;

	for (int i = 0; i < size_; ++i)
		data_[i] = val;
}

/*  IntVector iv(other);
 *  IntVector iv = other;
 *
 *  Copy constructor
 *  Creates a new vector with same size as other and copies the elements
 *  from other to *this.
 */
IntVector::IntVector(const IntVector& other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;
	data_ = new int [capacity_];

	for (int i = 0; i < size_; ++i)
		data_[i] = other.data_[i];
}

/*  Destructor (not called manually)
 *
 *  Frees the memory reserved by the data array before the IntVector dies.
 */
IntVector::~IntVector()//  ~identifies the destructor
{
	delete[] data_;
}

////
//
//  Iterators
//
////

/*  iv.begin()
 *
 *  Returns a pointer to the first element in the data array.
 */

/*
   iv = other;
   Assignment operator. Clears this then copies the values from other this
   */
IntVector& IntVector:: operator =(const IntVector& other)
{
	clear();
	reserve(other.size_);
	size_ = other.size_;
	for (int i = 0; i < size_; ++i)
		data_[i] = other.data_[i];
	return *this;
}

int* IntVector::begin()
{
	return data_;
}

/*  iv.end()
 *
 *  Returns a pointer to the address AFTER the last element in the data
 *  array.  end() is out of bounds.
 */
int* IntVector::end()
{
	return data_ + size_;
}

/*  iv.cbegin()
 *
 *  Returns a pointer to the first element in the data array, but only
 *  grants read access.  You cannot modify the value at *(cbegin()).
 */
const int* IntVector::cbegin() const
{
	return data_;
}

/*  iv.cend()
 *
 *  Returns a pointer to the address AFTER the last element in the data
 *  array, but only grants read access.  You cannot modify the value at
 *  *(cend()).  cend() is out of bounds.
 */
const int* IntVector::cend() const
{
	return data_ + size_;
}

////
//
//  Capacity
//
////

/*  iv.size()
 *
 *  Returns the number of elements represented by the vector.  This is
 *  usually not the size of the actual data array.  For example, if the
 *  data array has a capacity of 10 ints but the vector only represents the
 *  ints { 0, 1, 2 }, then size_ and size() should be 3.
 */
int IntVector::size() const
{
	return size_;
}

/*  iv.resize(n)
 *
 *  Changes the size of the vector to n.  If the vector contains more than
 *  n elements,  the vector will forget the extra elements exist.  If the
 *  data array is smaller than n, the data array will be reallocated and
 *  copied to a new larger array, then the old array will be destroyed.
 */
void IntVector::resize (int n)
{

}

/*  iv.capacity()
 *
 *  Returns the actual size of the underlying data array.  This is usually
 *  not size of the vector.  For example, if the vector represents the
 *  ints { 0, 1, 2 } but the data array actually has a capacity of 10 ints,
 *  then capacity_ and capacity() should be 10.
 */
int IntVector::capacity() const
{
	return capacity_;
}

/*  iv.empty()
 *
 *  Returns whether size_ is 0.
 */
bool IntVector::empty() const
{
	return size_ == 0;
}

/*  iv.reserve(n)
 *
 *  Requests that the capacity of the data array is increased to at least
 *  n.  If the data array is already larger than n, nothing happens.  If
 *  the data array is not at least as large as n, the array will be
 *  reallocated and copied to a new larger array, then the old array will
 *  be destroyed.
 */
void IntVector::reserve(int n)
{
	if (capacity_ >= n)
		return;
	//Otherwise reallocate
	int* trash = data_;
	data_ = new int[n];
	for (int i = 0; i < size_; ++i)
		data_[i] = trash[i];
	delete[] trash;
	capacity_ = n;
}

/*  iv.shrink_to_fit()
 *
 *  Requests that the capacity of the data array is reduced to match size.
 *  If you honor this request, the data array will be reallocated and
 *  copied to a new smaller array, then the old array will be destroyed.
 */
void IntVector::shrink_to_fit()
{

}

////
//
//  Element Access
//
////

/*  iv[pos]
 *
 *  Returns a reference to the element at pos.  If pos is out of bounds,
 *  this function should not terminate the program deliberately.  Allow
 *  the end user to use the [] operator on a pos that is out of bounds,
 *  consequences be damned.  It is up to them to make validate pos on their
 *  own.
 */
int& IntVector::operator[](int pos)
{
	return data_[pos];
}

/*  iv.at(pos)
 *
 *  Returns a reference to the element at pos.  If pos is out of bounds,
 *  this function should terminate the program.
 */
int& IntVector::at(int pos)
{
	if (pos >= size_)
		exit(1);
	return data_[pos];
}

/*  iv.front()
 *
 *  Returns a reference to the first element in the vector.
 */
int& IntVector::front()
{
	return data_[0];
}

/*  iv.back()
 *
 *  Returns a reference to the last element in the vector.  Note that this
 *  is in bounds.  The reference is not located at iv.end().
 */
int& IntVector::back()
{
	return data_[size_ - 1];
}

int* IntVector::data() { return data_ ;}
////
//
//  Modifiers
//
////

/*  iv.push_back(val)
 *
 *  Adds val to the end of the vector.  If the data array is already filled
 *  to capacity, the data array will be reallocated and copied to a new
 *  larger array, then the old array will be destroyed.
 */
void IntVector::push_back(const int& val)
{
	reserve(size_ * expansion);
	data_[size_] = val;
	++size_;
}

/*  iv.pop_back()
 *
 *  Removes the last element of the vector.  For our purposees, the vector
 *  will just forget that the last element exists, but we won't actually
 *  destroy it.  In a standard container implementation, the removed
 *  element would be destroyed.
 */
void IntVector::pop_back()
{
	--size_;
}

/*  iv.insert(pos, val)
 *
 *  Inserts val at pos.  All elements after pos must be shifted one spot
 *  toward the back.  If the data array is already filled to capacity, the
 *  data array will be reallocated and copied to a new larger array, then
 *  the old array will be destroyed.
 *
 *  In a standard container, the pos argument is actually an iterator or
 *  pointer to the address where the element should be inserted, rather
 *  than an index.
 */
void IntVector::insert(const int& pos, const int& val)
{
	reserve(size_ * expansion);
	for (int i = size_; i > pos; --i)
		data_[i] = data_[i - 1];
	data_[pos] = val;
	size_++;
}

/*  iv.erase(pos)
 *
 *  Removes the element at pos.  All elements after pos must be shifted
 *  one spot toward the front.
 *
 *  In a standard container, the pos argument is actually an iterator or
 *  pointer to the address where the element should be inserted, rather
 *  than an index.
 */
void IntVector::erase(const int& pos)
{
	reserve(size_ * expansion);
	for (int i = pos; i > size_; ++i)
		data_[i] = data_[i + 1];
	data_[pos] = pos;
	size_--;
}

/*  iv.clear()
 *
 *  Resets the size of vector to 0.  A standard container will actually
 *  destroy all the elements.
 *
 *  You are not required to reallocate the data array on a clear().  It
 *  is the end user's responsibility to call shrink_to_fit() or use a
 *  different method of resetting the array.
 */
void IntVector::clear()
{
	size_ = 0;
}
