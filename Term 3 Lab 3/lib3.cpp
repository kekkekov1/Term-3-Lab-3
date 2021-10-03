#include "lib3.h"

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
	std::cout << "Choose the matrix for assignment: ";
	return get_value(1u, kArraySize, true) - 1;
}
int lib3::get_int()
{
	std::cout << "Enter the int value: ";
	return get_value(INT_MIN, INT_MAX);
}
unsigned int lib3::get_uint()
{
	std::cout << "Enter the uint value: ";
	return get_value(0u, UINT_MAX);
}

auto lib3::case1(Arguments* const args)
{
	args->assign = !args->assign;
	if (args->assign) args->index = choose_index();
	if (args->assign) return "Assignment enabled";
	return "Assignment disabled";
}
auto lib3::case2(const Arguments* const args)
{
	return "NO RESULT";
}
auto lib3::case3(Arguments* const args)
{
	matrix::Matrix result;
	result = get_uint();
	if (args->assign) args->m_arr[args->index](result);
	return result;
}
auto lib3::case4(const Arguments* const args)
{
	const auto index = choose_index();
	std::cout << "Enter the uint value: ";
	auto result = args->m_arr[index].operator[](get_value(1u, args->m_arr[index].height(), true) - 1);
	return result;
}
auto lib3::case5(Arguments* const args)
{
	const auto i = get_int();
	const auto uint = get_uint();
	matrix::Matrix result;
	result(uint, i);
	if (args->assign) args->m_arr[args->index](result);
	return result;
}
auto lib3::case6(const Arguments* const args)
{
	return "NO RESULT";
}
auto lib3::case7(const Arguments* const args)
{
	return "NO RESULT";
}
auto lib3::case8(const Arguments* const args)
{
	return "NO RESULT";
}
auto lib3::case9(const Arguments* const args)
{
	return "NO RESULT";
}
auto lib3::case10(const Arguments* const args)
{
	using std::cout;
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
		cout << static_cast<bool>(args->m_arr[index]);
		break;
	case 2:
		cout << static_cast<unsigned int>(args->m_arr[index]);
		break;
	case 3:
		cout << static_cast<int>(args->m_arr[index]);
		break;
	case 4:
		cout << static_cast<double>(args->m_arr[index]);
		break;
	default:
		cout << static_cast<matrix::Size>(args->m_arr[index]);
		break;
	}
	return "";
}
auto lib3::case11(Arguments* const args)
{
	auto result = args->m_arr[choose_index()];
	result.transpose();
	if (args->assign) args->m_arr[args->index](result);
	return result;
}
auto lib3::case12(const Arguments* const args)
{
	std::cout << args->m_arr[choose_index()];
	return "";
}

void lib3::main_menu(Arguments* args)
{
	using std::cout;
	while (true)
	{
		for (auto& i : args->m_arr)
			cout << i << "\n";

		cout << "№:\tReturn:\tOperation:\n"
			<< "1)\t      :\t" << (args->assign ? "Disable assignment (current matrix used for assignment is " : "M = last result (enable assignment")
			<< (args->assign ? static_cast<char>('1' + args->index) : '\0') << ")\n"
			<< "2)\tMatrix:\tInitialize M\n"	//	TODO
			<< "3)\tMatrix:\tM = uint\n"
			<< "4)\tString:\tM[ uint ]\n"
			<< "5)\tMatrix:\tM( uint, int )\n"
			<< "6)\tMatrix:\t++\n"	//	TODO	sub		2
			<< "7)\tMatrix:\t--\n"	//	TODO	sub		2
			<< "8)\tMatrix:\tM +/- TYPE\n"	//	TODO	sub		2	2
			<< "9)\tbool  :\tM >/</== TYPE\n"	//	TODO	sub		3	3
			<< "10)\tTYPE  :\tTYPE( M ), aka M -> TYPE\n"
			<< "11)\tMatrix:\tTranspose M\n"
			<< "12)\t      :\tPrint M\n"
			<< "13)\t      :\tQuit\n";

		cout << "Choose the action number: ";
		switch (get_value(1, 13, true))
		{
		case 1:
		{
			cout << "Result is: " << case1(args);
		}
		break;
		case 2:
			//Initialize M
			cout << "Result is: " << case2(args);
			break;
		case 3:
			cout << "Result is: " << case3(args);
			break;
		case 4:
			cout << "Result is: " << case4(args);
			break;
		case 5:
			cout << "Result is: " << case5(args);
			break;
		case 6:
			cout << "Result is: " << case6(args);
			break;
		case 7:
			cout << "Result is: " << case7(args);
			break;
		case 8:
			cout << "Result is: " << case8(args);
			break;
		case 9:
			cout << "Result is: " << case9(args);
			break;
		case 10:
			cout << "Result is: " << case10(args);
			break;
		case 11:
			cout << "Result is: " << case11(args);
			break;
		case 12:
			cout << "Result is: " << case12(args);
			break;
		default:
			return;
		}

		update_screen();
	}
}
