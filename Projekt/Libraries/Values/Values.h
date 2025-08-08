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

#ifndef VALUES_H
#define VALUES_H

namespace Values
{
	template <typename T, typename U>
	// function swap, swaps two values with eachother
	T swap(T &value1, U &value2)
	{
		T temp = value1;
		value1 = value2;
		value2 = temp;
	}

	int getLength(const char *text);
};

#endif