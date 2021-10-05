#pragma once

#include <string>
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

constexpr unsigned int kArraySize = 5;

namespace lib3
{
	enum Type
	{
		kMatrix = 1,
		kInt,
		kUint,
		kDouble,
		kBool,
		kSize,
	};
	struct Arguments
	{
		matrix::Matrix m_arr[kArraySize];
		bool assign;
		unsigned int index;

		Arguments()
			: assign(false), index(0) {}

	};
	
	void update_screen();
	void get_string(std::string* string);

	unsigned int choose_index();
	int get_int();
	double get_double();
	unsigned int get_uint();
	
	void case7_1(Arguments*, unsigned int, int);
	void case7_2(const Arguments*, unsigned int, int);
	bool case8_1(const Arguments*, unsigned int, int);
	bool case8_2(const Arguments*, unsigned int, int);
	bool case8_3(const Arguments*, unsigned int, int);

	void case1(Arguments* args);
	void case2(Arguments* args);
	void case3(Arguments* args);
	void case4(Arguments* args);
	void case5(Arguments* args);
	void case6(Arguments* args);
	void case7(Arguments* args);

	void case8(const Arguments* args);
	void case9(const Arguments* args);
	void case10(const Arguments* args);
	void case11(const Arguments* args);

	void main_menu(Arguments* args);
}
