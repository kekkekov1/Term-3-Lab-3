#include "lib3.h"

int main()  // NOLINT(bugprone-exception-escape)
{
	using namespace lib3;
	using matrix::Matrix;
	using std::cout;
	cout << std::boolalpha;
	Arguments args;

	// Pre-Initializer
	{
		int s0[] = { 11, -12, 13, -14, 15, -16 };
		int s1[] = { -21, 22, -23, 24, -25, 26 };
		int s2[] = { 31, -32, 33, -34, 35, -36 };
		int s3[] = { -41, 42, -43, 44, -45, 46 };
		int s4[] = { 51, -52, 53, -54, 55, -56 };
		int* int_array[] = { s0, s1, s2, s3, s4 };

		for (auto i = 0u; i < kArraySize; i++)
			args.m_arr[i](Matrix(5 - (i + 2) / 2, 6 - (i + 3) / 2, int_array));
	}
	main_menu(&args);
}
