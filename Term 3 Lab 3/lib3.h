#pragma once

#include "matrix.h"

template <typename T>
T get_value(const T min, const T max, bool include_min = false, bool exclude_max = false)
{
	using std::cout;
	using std::cin;
	while (true)
	{
		T value;
		while (!(cin >> value))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect value! The value must be a number!\nTry again: ";
		}
		if (!(									//	if one condition is true value is not valid:
			(include_min && value < min) ||		//	min value is valid value, actual value is less then min value
			(!include_min && value <= min) ||	//	min value is NOT valid value, actual value is less then min value OR equals it
			(!exclude_max && value > max) ||	//	max value is valid value, actual value is greater then max value
			(exclude_max && value >= max)		//	max value is NOT valid value, actual value is greater then max value OR equals it
			)) return value;
		cout << "Incorrect value! The value must be in range "
			<< (include_min ? "[" : "(") << min << "; " << max
			<< (exclude_max ? ")" : "]") << "!\nTry again : ";
	}
}

constexpr auto kAlphabet = 26;

namespace lib3
{
	inline unsigned int index(const char c)
	{
		return c - 'a';
	}
}
