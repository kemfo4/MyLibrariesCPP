// MIT License
//
// Copyright (c) 2025 Mateusz Kmieć
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#pragma once

#include "Values.h"

#ifdef _IOSTREAM_
#include <iostream>
#endif
#include <cstdlib>

class Arrays
{
public:
	//	Function that creates array with random numbers from given range and given size
	template <typename T>
	static void create(T *&array, unsigned int array_size, unsigned int range)
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
	static bool check(T value, U (&array)[N])
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
	static void print(T (&array)[N])
	{

		for (int i = 0; i < N; i++)
			std::cout << array[i] << " ";
	}

	//	Function print, goes and print one element after another, give size as second parameter for dynamic arrays
	template <typename T>
	static void print(T *array, unsigned int size)
	{
		for (int i = 0; i < size; i++)
			std::cout << array[i] << " ";
	}

	//	Function sort, sorts by value, letters are sorted by ascii value
	template <typename T, size_t N>
	static void sort(T (&array)[N])
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