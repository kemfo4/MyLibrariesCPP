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

#ifdef _IOSTREAM_
#include <iostream>
#endif

class String
{
private:
	char *txt = nullptr;
	int txtLength = 0;
	char *text = nullptr;
	int textLength = 0;

public:
	String(const char *txt = nullptr);
	String(const String &other);
	~String();
	int length();

	// Brings back first value, given to the object
	void toDefault();

	// Adding in future
	// Returns current string upper case
	char *upperCase();

	String &operator=(char *gtext)
	{
		(*text) = (*gtext);
		length();
		if (txt == nullptr)
		{
			txtLength = textLength;
			(*txt) = (*text);
		}
	}

	String &operator=(const char *gtext)
	{
		(*text) = (*gtext);
		length();
		if (txt == nullptr)
		{
			txtLength = textLength;
			(*txt) = (*text);
		}
	}

	char operator[](unsigned int i) const
	{
		return text[i];
	}

	char &operator[](unsigned int i)
	{
		return text[i];
	}

#ifdef _OSTREAM_
	void print() const;

	friend std::ostream &operator<<(std::ostream &os, const String &s);
#endif
};