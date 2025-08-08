// EUROPEAN UNION PUBLIC LICENCE v. 1.2
// EUPL © the European Union 2007, 2016

// This European Union Public Licence (the ‘EUPL’) applies to the Work (as defined
// below) which is provided under the terms of this Licence. Any use of the Work,
// other than as authorised under this Licence is prohibited (to the extent such
// use is covered by a right of the copyright holder of the Work).

// The Work is provided under the terms of this Licence when the Licensor (as
// defined below) has placed the following notice immediately following the
// copyright notice for the Work:

// Licensed under the EUPL

// or has expressed by any other means his willingness to license under the EUPL.

#pragma once

#include "Values/Values.h"

#ifdef _IOSTREAM_
#include <iostream>
#endif
#include <cstdlib>

namespace Arrays
{
	//	Function that creates array with random numbers from given range and given size
	template <typename T>
	void create(T *&array, unsigned int array_size, unsigned int range)
	{
		srand(time(NULL));
		array = new T[array_size];
		for (int i = 0; i < array_size; i++)
		{
			array[i] = rand() % (range + 1);
		}
	}

	//	Function check, checks if given value is in the array
	template <typename T, typename U, size_t N>
	bool check(T value, U (&array)[N])
	{
		bool ret = false;
		for (int i = N - 1; i >= 0; i--)
		{
			if (value == array[i])
				ret = true;
		}
		return ret;
	}

	//	Function print, goes and print one element after another, give size as second parameter for dynamic arrays
	template <typename T, size_t N>
	void print(T (&array)[N])
	{

		for (int i = 0; i < N; i++)
			std::cout << array[i] << " ";
	}

	//	Function print, goes and print one element after another, give size as second parameter for dynamic arrays
	template <typename T>
	void print(T *array, unsigned int size)
	{
		for (int i = 0; i < size; i++)
			std::cout << array[i] << " ";
	}

	//	Function sort, sorts by value, letters are sorted by ascii value
	template <typename T, size_t N>
	void sort(T (&array)[N])
	{
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = 0; j < N - i - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					Values::swap(array[j], array[j + 1]);
				}
			}
		}
	}
};