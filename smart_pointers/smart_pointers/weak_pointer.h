#pragma once

#include "shared_pointer.h"

template <typename T>
class weak_pointer
{
	friend class shared_pointer<T>;

	T* ptr;
	int* counter;
	int* weak_counter;

	void release()
	{
		if (--(*weak_counter) == 0 && counter == 0) 
		{
			delete ptr;
			delete counter;
		}
	}

	//weak or shared
	template<typename weak_or_shared_pointer>
	void take_care(weak_or_shared_pointer const& that)
	{
		ptr = that.ptr;
		counter = that.counter;
		weak_counter = that.weak_counter;
		++(*weak_counter);
	}

public:
	//T* operator->() { return ptr; }
	//T& operator*() { return *ptr; }

	~weak_pointer()
	{
		release();
	}

	explicit weak_pointer(shared_pointer<T> const& sh_ptr)  
	{
		take_care(sh_ptr);
	}

	explicit weak_pointer(weak_pointer const& that)
	{
		take_care(that);
	}

	weak_pointer& operator=(weak_pointer const& that) 
	{
		release();
		take_care(that);
		return *this;
	}

	weak_pointer& operator=(shared_pointer<T> const& sp)
	{
		release();
		take_care(sp);
		return *this;
	}


	shared_pointer<T> getSharedPointer()
	{
		return shared_pointer<T>(*this);
	}

	int get_ref_count() const { return *counter; }
	int get_weak_count() const { return *weak_counter; }

};

