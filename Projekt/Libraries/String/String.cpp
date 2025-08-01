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

#include "String.h"
#include "../Values.h"

#ifdef _IOSTREAM_
#include <iostream>
#endif

String::String(const char *txt)
{
	txtLength = Values::getLength(txt);
	toDefault();
}

String::String(const String &other)
{
	txtLength = other.txtLength;
	textLength = other.textLength;

	txt = new char[txtLength + 1];
	for (int i = 0; i < txtLength + 1; i++)
		txt[i] = other.txt[i];

	text = new char[textLength + 1];
	for (int i = 0; i < textLength + 1; i++)
		text[i] = other.text[i];
}

String::~String()
{
	delete[] txt;
	delete[] text;
}

int String::getLength()
{
	textLength = Values::getLength(text);
	return textLength;
}

void String::toDefault()
{
	text = new char[txtLength + 1];
	for (int i = 0; i < txtLength + 1; i++)
		text[i] = txt[i];
	textLength = txtLength;
}

#ifdef _OSTREAM_
void String::print() const
{
	std::cout << "[DEBUG] txt: ";
	for (int i = 0; i < textLength; i++)
		std::cout << text[i];
}
#endif

#ifdef _OSTREAM_
std::ostream &operator<<(std::ostream &os, const String &s)
{
	for (int i = 0; i < s.textLength; i++)
		os << s.text[i];
	return os;
}
#endif
