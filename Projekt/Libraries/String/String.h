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
	int getLength();

	// Brings back first value, given to the object
	void toDefault();

	// Adding in future
	// Returns current string upper case
	char *upperCase();

	String &operator=(char *text)
	{
		if (txt == nullptr)
		{
			getLength();
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