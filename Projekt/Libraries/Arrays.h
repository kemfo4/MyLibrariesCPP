#pragma once

#include "Values.h"


#ifdef _IOSTREAM_
#include <iostream>
#endif
#include <cstdlib>



class Arrays {
public:

	//	Function that creates array with random numbers from given range and given size
	template<typename T>
	static void create(T*&array, unsigned int array_size, unsigned int range) {
		srand(time(NULL));
		array = new T[array_size];
		for (int i = 0; i < array_size; i++) {
			array[i] = rand() % (range+1);
		}
	}

	//	Function check, checks if given value is in the array
	template<typename T, typename U, size_t N>
	static bool check(T value, U(&array)[N]) {
		bool ret = false;
		for (int i = N - 1; i >= 0; i--) {
			if (value == array[i])
				ret = true;
		}
		return ret;
	}

	//	Function print, goes and print one element after another, give size as second parameter for dynamic arrays
	template<typename T, size_t N>
	static void print(T (&array)[N]) {
		std::cout << "[DEBUG] print() called\n";

		for (int i = 0; i < N; i++)
			std::cout << array[i] << " ";
	}

	//	Function print, goes and print one element after another, give size as second parameter for dynamic arrays
	template<typename T>
	static void print(T *array, unsigned int size) {
		for (int i = 0; i < size; i++)
			std::cout << array[i] << " ";
	}

	//	Function sort, sorts by value, letters are sorted by ascii value
	template<typename T, size_t N>
	static void sort(T(&array)[N]) {
		for (int i = 0; i < N - 1; ++i) {
			for (int j = 0; j < N - i - 1; ++j) {
				if (array[j] > array[j + 1]) {
					Values::swap(array[j], array[j + 1]);
				}
			}
		}
	}

};