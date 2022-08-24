#include <algorithm>

#include "unique_pointer.h"

template <typename T>
unique_pointer<T>::unique_pointer(T* _ptr) noexcept : ptr(_ptr)
{

}

template <typename T>
unique_pointer<T>::~unique_pointer()
{
	delete ptr;
}

//move constructor
template <typename T>
unique_pointer<T>::unique_pointer(unique_pointer&& that) noexcept
{
	//std::cout << "move constr" << endl;
	std::swap(this->ptr, that.ptr);
}



template <typename T>
T* unique_pointer<T>::operator->() const
{
	return ptr;
}

template <typename T>
T& unique_pointer<T>::operator*() const
{
	return *ptr;
}


