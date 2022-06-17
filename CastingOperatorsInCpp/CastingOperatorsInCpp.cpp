// CastingOperatorsInCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template <typename T>T* allocate(const size_t n)
{
	if (n == 0)
	{
		return nullptr;
	}
	size_t max_size = static_cast<size_t>(-1) / sizeof(T);
	if (n > max_size)
	{
		throw std::bad_array_new_length();
	}
	size_t array_size = n * sizeof(T);

	void* const pv = malloc(array_size);
	if (!pv) { throw std::bad_alloc(); }
	return static_cast<T*>(pv);
}

template <typename T> void print(const T& t) {
	cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
	cout << first << ", ";
	print(rest...); // recursive call using pack expansion syntax
}


class Base
{
public:
	void fun_in_base() { cout << "fun in base"; };

private:
	int baseint;
};

class Derived : public Base
{
public:
	void fun_in_derived() { cout << "fun in derived"; };

private:
	int derivedint;
};

//int main()
//{
//	// these call the third overload, the variadic template,
//	// which uses recursion as needed.
//	//print(100, 200, 300);
//
//	//std::cout << "just a test";
//
//	double d = 1.58947;
//	int j = static_cast<int>(d);       // No warning.
//
//	// No error but not necessarily safe.
//	Base* b = new Base();
//	Derived* d2 = static_cast<Derived*>(b);
//	d2->fun_in_derived();
//
//	print(j);
//
//}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#pragma once
#include <stdlib.h> //size_t, malloc, free
#include <new> // bad_alloc, bad_array_new_length
#include <memory>
template <class T>
struct Mallocator
{
	typedef T value_type;
	Mallocator() noexcept {} //default ctor not required by C++ Standard Library

	// A converting copy constructor:
	template<class U> Mallocator(const Mallocator<U>&) noexcept {}
	template<class U> bool operator==(const Mallocator<U>&) const noexcept
	{
		return true;
	}
	template<class U> bool operator!=(const Mallocator<U>&) const noexcept
	{
		return false;
	}
	T* allocate(const size_t n) const;
	void deallocate(T* const p, size_t) const noexcept;
};

template <class T>
T* Mallocator<T>::allocate(const size_t n) const
{
	if (n == 0)
	{
		return nullptr;
	}
	if (n > static_cast<size_t>(-1) / sizeof(T))
	{
		throw std::bad_array_new_length();
	}
	void* const pv = malloc(n * sizeof(T));
	if (!pv) { throw std::bad_alloc(); }
	return static_cast<T*>(pv);
}

template<class T>
void Mallocator<T>::deallocate(T* const p, size_t) const noexcept
{
	free(p);
}
