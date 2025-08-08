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

#include "String.h"
#include "../Values/Values.h"

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

int String::length()
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
