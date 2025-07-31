#ifndef VALUES_H
#define VALUES_H

class Values {
public:
	template<typename T, typename U>
	//function swap, swaps two values with eachother
	static T swap(T& value1, U& value2) {
		T temp = value1;
		value1 = value2;
		value2 = temp;
	}

	static int getLength(const char* text) {
		int i;
		for (i = 0; text[i] != '\0'; i++);
		return i;
	}
};

#endif