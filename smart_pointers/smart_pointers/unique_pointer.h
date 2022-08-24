#pragma once

template <typename T>
class unique_pointer
{
private:
	T* ptr = nullptr;
public:
	unique_pointer(T* ptr) noexcept;
	~unique_pointer();
	unique_pointer(unique_pointer&& that) noexcept;

	T* operator->() const;
	T& operator*() const;
};

template <typename T>
unique_pointer<T> makeUnique(T* ptr)
{
	return unique_pointer(ptr);
}
