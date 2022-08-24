#pragma once

#include <iostream>

template <typename T>
class weak_pointer;

template <typename T>
class shared_pointer
{
	T* ptr{ nullptr };
	int* counter{ nullptr };
	int* weak_counter{ nullptr };

	void release()
	{
		if (--(*counter) == 0) 
		{
			delete ptr;
			if (weak_counter == 0)
			{
				delete counter;
				delete weak_counter;
			}
		}
	}

	template <typename shared_or_weak_pointer>
	void take_care(shared_or_weak_pointer const& that)
	{
		ptr = that.ptr;
		counter = that.counter;
		++(*counter);
		weak_counter = that.weak_counter;
	}

public:
	friend class weak_pointer<T>;

	T* operator->() { return ptr; }
	T& operator*() { return *ptr; }

	~shared_pointer()
	{
		release();
	}

	explicit shared_pointer(T* ptr) : ptr{ ptr }, counter{ new int{ 1 } }, weak_counter{ new int{ 0 } } {}

	explicit shared_pointer(shared_pointer const& that)
	{
		take_care(that);
	}
	
	shared_pointer& operator=(shared_pointer const& that)
	{
		release();
		take_care(that);
		return *this;
	}


	explicit shared_pointer(weak_pointer<T> const& wp)
	{
		if (wp.get_weak_count())
		{
			take_care(wp);
		}
	}

	shared_pointer& operator=(weak_pointer<T> const& wp)
	{
		//itt lehetne vizsgalni, hogy nem sp => wp => sp eset van-e, akkor esetleg feleslegesen releaselunk/take-elunk
		release();
		take_care(wp);
		return *this;
	}

	int get_ref_count() const { return *counter; }
	int get_weak_count() const { return *weak_counter; }
};

