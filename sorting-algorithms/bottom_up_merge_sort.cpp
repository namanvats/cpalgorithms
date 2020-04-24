#include <cstddef>//for size_t
#include <utility>//for std::move & std::remove_reference_t
template<class Iterator>
void merge(Iterator, Iterator, const Iterator, char[]);
///bottom-up merge sort which sorts elements in a non-decreasing order
/**
 * sorts elements non-recursively by breaking them into small segments, merging
 * adjacent segments into larger sorted segments, then increasing the sizes of
 * segments by factors of 2.
 * best-case = worst-case = O(n)
 * @param first points to the first element
 * @param last points to 1-step past the last element
 * @param the number of elements
*/
template<class Iterator>
void nonrecursiveMergeSort(const Iterator first, const Iterator last,
						   const size_t n)
{
	//create a buffer large enough to store all elements
	char buffer[n * sizeof(*first)];
	//buffer size can be optimized to largest power of 2 less than n elements
	//divide the container into equally-sized segments whose length start at 1
	// and keeps increasing by factors of 2
	for (size_t length(1); length < n; length <<= 1)
	{
		//merge adjacent segments whose number is n / (length * 2)
		Iterator left(first);
		for (size_t counter(n / (length << 1)); counter; --counter)
		{
			Iterator right(left + length), end(right + length);
			merge(left, right, end, buffer);
			left = end;
		}
		//if the number of remaining elements (n * 2 % length) is longer
		//than a segment, merge the remaining elements
		if ((n & ((length << 1) - 1)) > length)
			merge(left, left + length, last, buffer);
	}
}
///merges 2 sorted adjacent segments into a larger sorted segment
/**
 * best-case = worst-case = O(n)
 * @param l points to the left part
 * @param r points to the right part, end of left part
 * @param e points to end of right part
 * @param b points at the buffer
*/
template<class Iterator>
void merge(Iterator l, Iterator r, const Iterator e, char b[])
{
	//create 2 pointers to point at the buffer
	auto p(reinterpret_cast<std::remove_reference_t<decltype(*l)>*>(b)), c(p);
	//move the left part of the segment
	for (Iterator t(l); r != t; ++t)
		*p++ = std::move(*t);
	//while neither the buffer nor the right part has been exhausted
	//move the smallest element of the two back to the container
	while (e != r && c != p)
		*l++ = std::move(*r < *c ? *r++ : *c++);
	//notice only one of the two following loops will be executed
	//while the right part hasn't bee exhausted, move it back
	while (e != r)
		*l++ = std::move(*r++);
	//while the buffer hasn't bee exhausted, move it back
	while (c != p)
		*l++ = std::move(*c++);
}
template<class Iterator>
void nonrecursiveMergeSort(const Iterator first, const size_t n)
{
	nonrecursiveMergeSort(first, first + n, n);
}
template<class Iterator>
void nonrecursiveMergeSort(const Iterator first, const Iterator last)
{
	nonrecursiveMergeSort(first, last, last - first);
}
//the rest of this is file is only for testing, it can be removed to convert it
//into a header file
#include <iostream>
#include <random>
using namespace std;
int main(int argc, char ** argv)
{
	size_t n;
	cout << "enter the number of elements\n";
	cin >> n;
	unsigned a[n];
	default_random_engine e;
	for (size_t i(0); i != n; ++i)
		a[i] = e() % 10;
	cout << "presorting\n";
	for (size_t i(0); i != n; ++i)
		cout << "a[" << i << "] = " << a[i] << '\n';
	nonrecursiveMergeSort(a, n);
	cout << "after sorting\n";
	for (size_t i(0); i != n; ++i)
		cout << "a[" << i << "] = " << a[i] << '\n';
	return 0;
}
