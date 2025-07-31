#include "String.h"
#include "../Values.h"

#ifdef _IOSTREAM_
#include <iostream>
#endif


String::String(const char* txt) {
	txtLength = Values::getLength(txt);
	toDefault();
}

String::String(const String& other) {
	txtLength = other.txtLength;
	textLength = other.textLength;
	
	txt = new char[txtLength + 1];
	for (int i = 0; i < txtLength + 1; i++)
		txt[i] = other.txt[i];
	
	text = new char[textLength + 1];
	for (int i = 0; i < textLength+1; i++)
		text[i] = other.text[i];
}

String::~String() {
	delete[] txt;
	delete[] text;
}

int String::getLength() {
	textLength = Values::getLength(text);
	return textLength;
}

void String::toDefault() {
	text = new char[txtLength+1];
	for (int i = 0; i < txtLength+1; i++)
		text[i] = txt[i];
	textLength = txtLength;
}

#ifdef _OSTREAM_
void String::print() const{
	std::cout << "[DEBUG] txt: ";
	for (int i = 0; i < textLength; i++)
		std::cout << text[i];
}
#endif


#ifdef _OSTREAM_
std::ostream& operator<<(std::ostream& os, const String& s) {
	for (int i = 0; i < s.textLength; i++)
		os << s.text[i];
	return os;
}
#endif
