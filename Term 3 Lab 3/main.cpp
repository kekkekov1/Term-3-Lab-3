#include "lib3.h"

int main()  // NOLINT(bugprone-exception-escape)
{
	using namespace matrix;
	using namespace lib3;

	Matrix m_arr[kAlphabet];

	int s0[] = { 11, 12, 13, 14 };
	int s1[] = { 21, 22, 23, 24 };
	int s2[] = { 31, 32, 33, 34 };
	int* int_array[] = {s0, s1, s2};
	
	std::cout << m_arr[0](Matrix(3, 4, int_array)) << "\n";

	auto m = Matrix(m_arr[0]);

	std::cout << m << "\n";
	std::cout << --m << "\n";
	std::cout << m << "\n";
	std::cout << m-- << "\n";
	std::cout << m << "\n";

	auto n = m;
	std::cout << "n\n" << n << "\n";

	std::cout << n + 2 << "\n";
	std::cout << n + 2 << "\n";
	std::cout << n - 2 << "\n";
	std::cout << n - 2 << "\n";

	std::cout << n - 2 << "\n";
	std::cout << n - 2 << "\n";
	std::cout << n - 2 << "\n";

	return 0;
}
