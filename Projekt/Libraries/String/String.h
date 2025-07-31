#pragma once

#ifdef _IOSTREAM_
#include <iostream>
#endif

class String {
private:
	char* txt= nullptr;
	int txtLength=0;
	char* text=nullptr;
	int textLength=0;
public:
	String(const char* txt = nullptr);
	String(const String& other);
	~String();
	int getLength();

	// Brings back first value, given to the object
	void toDefault();


	// Adding in future
	// Returns current string upper case
	char* upperCase();

	String& operator=(char* text) {
		if (txt == nullptr)
		{
			getLength();
			txtLength = textLength;
			(*txt) = (*text);
		}
	}

	char operator[](unsigned int i) const {
		return text[i];
	}

	char& operator[](unsigned int i) {
		return text[i];
	}

#ifdef _OSTREAM_
	void print() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s);
#endif

};