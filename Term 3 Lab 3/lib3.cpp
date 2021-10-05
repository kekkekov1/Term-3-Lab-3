#include "lib3.h"

#pragma region namespace lib3:: additional functions

void lib3::update_screen()
{
	system("pause");  // NOLINT(concurrency-mt-unsafe)
	system("cls");  // NOLINT(concurrency-mt-unsafe)
}
void lib3::get_string(std::string* string)
{
	using namespace std;
	while (true)
	{
		rewind(stdin);
		getline(std::cin, *string);
		if (const char c = (*string)[0]; (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return;
		cout << "Incorrect expression! Try again: ";
	}
}

unsigned int lib3::choose_index()
{
	return get_value(1u, kArraySize, true) - 1;
}
int lib3::get_int()
{
	std::cout << "Enter the int value: ";
	return get_value(INT_MIN, INT_MAX);
}
double lib3::get_double()
{
	std::cout << "Enter the double value: ";
	return get_value(DBL_MIN, DBL_MAX);
}
unsigned int lib3::get_uint()
{
	std::cout << "Enter the uint value: ";
	return get_value(0u, UINT_MAX);
}

#pragma endregion

#pragma region namespace lib3:: main_menu function and its cases

#pragma region namespace lib3:: sub-cases

void lib3::case7_1(Arguments* const args, const unsigned int index, const int operation)
{
	if (operation == 1)	std::cout << "This operation will calculate the pow of each element in the matrix. The pow you choose (how many times).\n";
	else std::cout << "This operation will calculate the root of each element in the matrix. The pow you choose (how many times).\n";
	std::cout << "ATTENTION: Signs won't be involved (will remain)!\n";
	auto result = args->m_arr[index];
	if (operation == 1) result = result + get_double();
	else result = result - get_double();
	if (args->assign) args->m_arr[args->index](result);
	std::cout << "Result is:\n" << result;
}
void lib3::case7_2(const Arguments* const args, const unsigned int index, const int operation)
{
	if (operation == 1)	std::cout << "This operation will calculate the quantity of all elements in two matrices.\n";
	else std::cout << "This operation will calculate arithmetical difference between the quantity of all elements in two matrices.\n";
	const auto index2 = choose_index();
	if (operation == 1) std::cout << "Result is: " << args->m_arr[index] + args->m_arr[index2];
	else std::cout << "Result is: " << args->m_arr[index] - args->m_arr[index2] << "\n";
}
bool lib3::case8_1(const Arguments* const args, const unsigned int index, const int operation)
{
	std::cout << "This operation will compare the sum of all elements with the value you provide below.\n";
	switch (operation)
	{
	case 1:
		return args->m_arr[index] > get_int();
	case 2:
		return args->m_arr[index] < get_int();
	default:
		return args->m_arr[index] == get_int();
	}
}
bool lib3::case8_2(const Arguments* const args, const unsigned int index, const int operation)
{
	std::cout << "This operation will compare the average value of all elements with the value you provide below.\n";
	switch (operation)
	{
	case 1:
		return args->m_arr[index] > get_double();
	case 2:
		return args->m_arr[index] < get_double();
	default:
		return args->m_arr[index] == get_double();
	}

}
bool lib3::case8_3(const Arguments* const args, const unsigned int index, const int operation)
{

	std::cout << "This operation will compare the quantity of all elements in two matrices.\n";
	std::cout << "Choose the second matrix: ";
	const auto index2 = choose_index();
	switch (operation)
	{
	case 1:
		return args->m_arr[index] > args->m_arr[index2];
	case 2:
		return args->m_arr[index] < args->m_arr[index2];
	default:
		return args->m_arr[index] == args->m_arr[index2];
	}
}

#pragma endregion

#pragma region namespace lib3:: cases

void lib3::case1(Arguments* const args)
{
	using std::cout;
	cout << "This operation will configure the result assignment, so any operation result with the type Matrix will be placed where you choose.\n";
	args->assign = !args->assign;
	std::cout << "Choose the matrix for assignment: ";
	if (args->assign) args->index = choose_index();
}
void lib3::case2(Arguments* const args)
{
	using std::cout;
	cout << "This operation will initialize the matrix with the values you you choose.\n";
	cout << "Enter the matrix's height: ";
	const unsigned height = get_value(0u, UINT_MAX);
	cout << "Enter the matrix's width: ";
	const unsigned width = get_value(0u, UINT_MAX);
	const auto int_array = new int*[height];
	for (auto i = 0u; i < height; i++)
	{
		int_array[i] = new int[width];
		for (auto j = 0u; j < width; j++)
		{
			cout << "Enter the element[" << i + 1 << "][" << j + 1 << "]: ";
			int_array[i][j] = get_value(INT_MIN, INT_MAX, true);
		}
	}
	const auto result = matrix::Matrix(height, width, int_array);

	for (auto i = 0u; i < height; i++)
		delete[] int_array[i];
	delete[] int_array;

	if (args->assign) args->m_arr[args->index](result);
	cout << "Result is:\n" << result;
}
void lib3::case3(Arguments* const args)
{
	using std::cout;
	cout << "This operation will create E-Matrix of the size you choose.\n";
	matrix::Matrix result;
	result = get_uint();
	if (args->assign) args->m_arr[args->index](result);
	cout << "Result is:\n" << result;
}
void lib3::case4(Arguments* const args)
{
	using std::cout;
	cout << "This operation will transpose the matrix you choose.\n";
	cout << "Choose the matrix: ";
	auto result = args->m_arr[choose_index()];
	result.transpose();
	if (args->assign) args->m_arr[args->index](result);
	cout << "Result is:\n" << result;
}
void lib3::case5(Arguments* const args)
{
	using std::cout;
	cout << "This operation will create the square matrix of the size you choose, filled with the value you choose.\n";
	const auto i = get_int();
	const auto uint = get_uint();
	matrix::Matrix result;
	result(uint, i);
	if (args->assign) args->m_arr[args->index](result);
	cout << "Result is:\n" << result;
}
void lib3::case6(Arguments* const args)
{
	using std::cout;
	cout << "Choose the kind of operation:\n"
		<< "1)\tOperation ++M\n"
		<< "2)\tOperation M++\n"
		<< "3)\tOperation --M\n"
		<< "4)\tOperation M--\n"
		<< "Operation: ";
	const auto operation = get_value(1, 4, true);

	cout << "Choose the matrix: ";
	auto result = args->m_arr[choose_index()];
	
	switch(operation)
	{
	case 1:
		cout << "This operation will reverse all negative values and assign it to the matrix you choose.\n"
			<< "Result is:\n" << ++result;
		break;
	case 2:
		cout << "This operation will assign the matrix you choose and then reverse all negative values in it.\n"
			<< "Result is:\n" << result++;
		break;
	case 3:
		cout << "This operation will reverse ALL values and assign it to the matrix you choose.\n"
			<< "Result is:\n" << --result;
		break;
	default:
		cout << "This operation will assign the matrix you choose and then reverse ALL values in it.\n"
			<< "Result is:\n" << result--;
		break;
	}
	if (args->assign) args->m_arr[args->index](result);
}
void lib3::case7(Arguments* const args)
{
	using std::cout;
	cout << "Choose the type for operation +/-:\n"
		<< "1)\tdouble\n"
		<< "2)\tMatrix\n"
		<< "Type: ";
	const auto type = get_value(1, 2, true);

	cout << "Choose the kind of operation:\n"
		<< "1)\tOperation +\n"
		<< "2)\tOperation -\n"
		<< "Operation: ";
	const auto operation = get_value(1, 2, true);

	cout << (type == 2 ? "Choose the first matrix: " : "Choose the matrix: ");
	const auto index1 = choose_index();
	if (type == 1) case7_1(args, index1, operation);
	else case7_2(args, index1, operation);
}

#pragma endregion

#pragma region namespace lib3:: const cases

void lib3::case8(const Arguments* const args)
{
	using std::cout;
	cout << "Choose the type for operation >/</==:\n"
		<< "1)\tint\n"
		<< "2)\tdouble\n"
		<< "3)\tMatrix\n";
	const auto type = get_value(1, 3, true);

	cout << "Choose the kind of operation:\n"
		<< "1)\tOperation >\n"
		<< "2)\tOperation <\n"
		<< "3)\tOperation ==\n"
		<< "Operation: ";
	const auto operation = get_value(1, 3, true);

	cout << (type == 3 ? "Choose the first matrix: " : "Choose the matrix: ");
	const auto index1 = choose_index();

	using Options = bool(*[])(const Arguments*, unsigned int, int);
	constexpr Options option = { &case8_1, &case8_2, &case8_3 };

	const auto result = option[type - 1](args, index1, operation);
	std::cout << "Result is: " << result << "\n";
}
void lib3::case9(const Arguments* const args)
{
	using std::cout;
	std::cout << "This operation will convert the matrix you choose into the type you choose.\n";
	cout << "Choose the matrix: ";
	const auto index = choose_index();
	cout << "Choose the new type:\n"
		<< "1)\tbool\n"
		<< "2)\tuint\n"
		<< "3)\tint\n"
		<< "4)\tdouble\n"
		<< "5)\tSize\n";
	switch (get_value(1u, 5u, true))
	{
	case 1:
		cout << "The result is: " << static_cast<bool>(args->m_arr[index]) << "\n";
		return;
	case 2:
		cout << "The result is: " << static_cast<unsigned int>(args->m_arr[index]) << "\n";
		return;
	case 3:
		cout << "The result is: " << static_cast<int>(args->m_arr[index]) << "\n";
		return;
	case 4:
		cout << "The result is: " << static_cast<double>(args->m_arr[index]) << "\n";
		return;
	default:
		cout << "The result is: " << static_cast<matrix::Size>(args->m_arr[index]) << "\n";
		return;
	}
}
void lib3::case10(const Arguments* const args)
{
	std::cout << "This operation will print the chosen line of the matrix you choose!\n";
	using std::cout;
	cout << "Choose the matrix: ";
	const auto index = choose_index();
	cout << "Enter the line number value: ";
	const auto uint = get_value(1u, args->m_arr[index].height(), true) - 1;
	cout << "Result is: " << args->m_arr[index][uint] << "\n";
}
void lib3::case11(const Arguments* const args)
{
	std::cout << "This operation will print the matrix you choose!\n";
	std::cout << "Choose the matrix: ";
	std::cout << args->m_arr[choose_index()];
}

#pragma endregion

void lib3::main_menu(Arguments* args)
{
	using std::cout;
	while (true)
	{
		for (auto i = 0u; i < kArraySize; i++)
			cout << "Matrix #" << i + 1 << "\n" << args->m_arr[i] << "\n";

		cout << "No:\tReturn:\tOperation:\n"
			<< "1)\t      :\t" << (args->assign ? "Disable assignment (current matrix used for assignment is " : "M = last result (enable assignment")
			<< (args->assign ? static_cast<char>('1' + args->index) : '\0') << ")\n"
			<< "2)\tMatrix:\tInitialize M\n"	//	TODO
			<< "3)\tMatrix:\tM = uint\n"
			<< "4)\tMatrix:\tTranspose M\n"
			<< "5)\tMatrix:\tM( uint, int )\n"
			<< "6)\tMatrix:\t++/--\n"
			<< "7)\tMatrix:\tM +/- TYPE\n"
			<< "8)\tbool  :\tM >/</== TYPE\n"
			<< "9)\tTYPE  :\tTYPE( M ), aka M -> TYPE\n"
			<< "10)\tString:\tM[ uint ]\n"
			<< "11)\t      :\tPrint M, aka std::cout << M\n"
			<< "12)\t      :\tQuit\n";
		cout << "Choose the action number: ";

		using Options = void(*[])(Arguments*);
		using ConstOptions = void(*[])(const Arguments*);
		constexpr Options options = { &case1, &case2, &case3, &case4, &case5, &case6, &case7 };
		constexpr ConstOptions const_options = { &case8, &case9, &case10, &case11 };

		const auto action = get_value(1, 12, true) - 1;

		system("cls");  // NOLINT(concurrency-mt-unsafe)

		if (action == 11) return;
		if (action < 7) options[action](args);
		else const_options[action - 7](args);

		update_screen();
	}
}

#pragma endregion
