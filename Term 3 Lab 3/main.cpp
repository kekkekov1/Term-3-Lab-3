#include "lib3.h"

/*
void converter(lib3::Arguments& args)
{
	using std::cout;
	using namespace lib3;
	if (const size_t pos = args.expression.find(')') + 1)
		if (const int ind = index(args.expression[pos - 2]); ind >= 0 && ind < kArraySize)
		{
			const auto temp = matrix::Matrix(args.m_arr[ind]);

			if (args.type[0] == kBool) cout << static_cast<bool>(temp);
			else if (args.type[0] == kUint) cout << static_cast<unsigned int>(temp);
			else if (args.type[0] == kInt) cout << static_cast<int>(temp);
			else if (args.type[0] == kDouble) cout << static_cast<double>(temp);
			else if (args.type[0] == kSize) cout << static_cast<matrix::Size>(temp);
			return;
		}
	cout << "An error occurred\n";
}
*/

int main()  // NOLINT(bugprone-exception-escape)
{
	using namespace lib3;
	using matrix::Matrix;
	using std::cout;
	cout << std::boolalpha;

	Arguments args;

	int s0[] = { 11, 12, 13, 14, 15, 16 };
	int s1[] = { 21, 22, 23, 24, 25, 26 };
	int s2[] = { 31, 32, 33, 34, 35, 36 };
	int s3[] = { 41, 42, 43, 44, 45, 46 };
	int s4[] = { 51, 52, 53, 54, 55, 56 };
	int* int_array[] = {s0, s1, s2, s3, s4};

	//Initilizer
	for (auto i = 0u; i < kArraySize; i++)
		args.m_arr[i](Matrix(5 - (i+2)/2, 6 - (i+3)/2, int_array));

	main_menu(&args);

}
