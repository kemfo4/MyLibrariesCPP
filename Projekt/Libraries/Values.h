#ifndef VALUES_H
#define VALUES_H

#include <iostream>

class Values {
	template<typename T, typename U>
	//function swap, swaps two values with eachother
	T swap(T& value1, U& value2) {
		T temp = value1;
		value1 = value2;
		value2 = temp;
	}
};

#endif