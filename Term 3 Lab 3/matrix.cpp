#include "matrix.h"
#include <cmath>
#include <string>

#pragma region namespace matrix:: functions

// Reverse all values and assign
matrix::Matrix& matrix::operator-- (Matrix& matrix)
{
	if (matrix.representation_)
		for (auto i = 0u; i < matrix.height_; i++)
			for (auto j = 0u; j < matrix.width_; j++)
				matrix.representation_[i][j] *= -1;
	return matrix;
}
// Assign and reverse all values
matrix::Matrix& matrix::operator-- (Matrix& matrix, int)
{
	Matrix::push_temp(matrix);
	--matrix;
	return *Matrix::temp_;
}
// Smart pow
matrix::Matrix& matrix::operator+ (Matrix& matrix, const double value)
{
	matrix.pow_for_each(value);
	return matrix;
}
// Smart root
matrix::Matrix& matrix::operator- (Matrix& matrix, const double value)
{
	matrix.pow_for_each(1.0 / value);
	return matrix;
}
//Sum comparison
bool matrix::operator> (const Matrix& matrix, const int value)
{
	return matrix.sum() > value;
}
bool matrix::operator< (const Matrix& matrix, const int value)
{
	return matrix.sum() < value;
}
bool matrix::operator== (const Matrix& matrix, const int value)
{
	return matrix.sum() == value;
}
//Average comparison
bool matrix::operator> (const Matrix& matrix, const double value)
{
	return matrix.average() > value;
}
bool matrix::operator< (const Matrix& matrix, const double value)
{
	return matrix.average() < value;
}
bool matrix::operator== (const Matrix& matrix, const double value)
{
	return !(matrix.average() > value || matrix.average() < value);
}
//Output
std::ostream& matrix::operator<<(const std::ostream&, const Matrix& matrix)
{
	using std::cout;
	if (!matrix.area()) return cout << "Matrix is empty.\n";
	for (auto i = 0u; i < matrix.height_; i++)
		cout << "| " << matrix[i] << " |\n";
	return cout;
}
std::ostream& matrix::operator<<(const std::ostream&, const Size& size)
{
	return std::cout << "Height: " << size.height_ << "\tWidth: " << size.width_;
}

#pragma endregion

#pragma region class matrix::Matrix:: functions (public)

//Initialize matrix with zeros and ones
matrix::Matrix& matrix::Matrix::operator= (const unsigned int size)
{
	delete_representation();
	representation_ = new int* [height_ = size];
	for (auto i = 0u; i < height_; i++)
	{
		representation_[i] = new int[width_ = size];
		for (auto j = 0u; j < width_; j++)
			representation_[i][j] = 0;
		representation_[i][i] = 1;
	}
	return *this;
}
//Get string from the index
std::string matrix::Matrix::operator[] (const unsigned int i) const
{
	auto string = std::string();
	if (representation_)
		for (auto k = 0u; k < width_; k++)
		{
			string += std::to_string(representation_[i][k]);
			if (k != width_ - 1) string += " ";
		}
	return string;
}
//Initialize matrix with matrix
matrix::Matrix& matrix::Matrix::operator() (const Matrix& matrix)
{
	delete_representation();
	height_ = matrix.height_;
	width_ = matrix.width_;
	copy_representation(matrix.representation_);
	return *this;
}
//Initialize matrix with value
matrix::Matrix& matrix::Matrix::operator() (const unsigned int size, const int value)
{
	delete_representation();
	representation_ = new int* [height_ = size];
	for (auto i = 0u; i < height_; i++)
	{
		representation_[i] = new int[width_ = size];
		for (auto j = 0u; j < width_; j++)
			representation_[i][j] = value;
	}
	return *this;
}
// Reverse all negative values and assign
matrix::Matrix& matrix::Matrix::operator++ ()
{
	if (representation_)
		for (auto i = 0u; i < height_; i++)
			for (auto j = 0u; j < width_; j++)
				if (representation_[i][j] < 0) representation_[i][j] *= -1;
	return *this;
}
// Assign and reverse all negative values
matrix::Matrix& matrix::Matrix::operator++ (int)
{
	push_temp(*this);
	++* this;
	return *temp_;
}
//Sum's of matrices
int matrix::Matrix::operator+ (const Matrix& matrix) const
{
	return sum() + matrix.sum();
}
int matrix::Matrix::operator- (const Matrix& matrix) const
{
	return sum() - matrix.sum();
}
//Quantity of elements exploration:
bool matrix::Matrix::operator> (const Matrix& matrix) const
{
	return area() > matrix.area();
}
bool matrix::Matrix::operator< (const Matrix& matrix) const
{
	return area() < matrix.area();
}
bool matrix::Matrix::operator== (const Matrix& matrix) const
{
	return area() == matrix.area();
}

//Transpose of a matrix (it's transposition)
[[ nodiscard ]] unsigned int matrix::Matrix::height() const
{
	return height_;
}
[[ nodiscard ]] unsigned int matrix::Matrix::width() const
{
	return width_;
}
matrix::Matrix& matrix::Matrix::transpose()
{
	push_temp(*this);
	delete_representation();
	height_ = temp_->width();
	width_ = temp_->height();
	representation_ = new int* [height_];
	for (auto i = 0u; i < height_; i++)
	{
		representation_[i] = new int[width_];
		for (auto j = 0u; j < width_; j++)
			representation_[i][j] = temp_->representation_[j][i];
	}
	return *this;
}

#pragma endregion

#pragma region class matrix::Matrix:: conversions (public)

matrix::Matrix::operator bool() const
{
	return representation_;
}
matrix::Matrix::operator unsigned int() const
{
	return area();
}
matrix::Matrix::operator int() const
{
	return sum();
}
matrix::Matrix::operator double() const
{
	return average();
}
matrix::Matrix::operator matrix::Size () const
{
	return Size(height_, width_);
}

#pragma endregion

#pragma region class matrix::Matrix:: functions (private)

[[ nodiscard ]] unsigned int matrix::Matrix::area() const
{
	return height_ * width_;
}
[[ nodiscard ]] int matrix::Matrix::sum() const
{
	int sum = 0;
	if (representation_)
		for (auto i = 0u; i < height_; i++)
			for (auto j = 0u; j < width_; j++)
				sum += representation_[i][j];
	return sum;
}
[[ nodiscard ]] double matrix::Matrix::average() const
{
	return static_cast<double>(sum()) / area();
}

void matrix::Matrix::copy_representation(int** int_array)
{
	if (!int_array) return;
	representation_ = new int* [height_];
	for (auto i = 0u; i < height_; i++)
	{
		representation_[i] = new int[width_];
		for (auto j = 0u; j < width_; j++)
			representation_[i][j] = int_array[i][j];
	}
}
void matrix::Matrix::delete_representation()
{
	if (representation_)
	{
		for (auto i = 0u; i < height_; i++)
			delete[] representation_[i];
		delete[] representation_;
		representation_ = nullptr;
	}
}
void matrix::Matrix::copy_fields(const Matrix& matrix)
{
	width_ = matrix.width_;
	height_ = matrix.height_;
	delete_representation();
	copy_representation(matrix.representation_);
}
void matrix::Matrix::pow_for_each(const double value) const
{
	if (representation_)
		for (auto i = 0u; i < height_; i++)
			for (auto j = 0u; j < width_; j++)
				representation_[i][j] = static_cast<int>(pow(static_cast<double>(representation_[i][j]), value));
}

void matrix::Matrix::push_temp(const Matrix& matrix)
{
	delete temp_;
	temp_ = new Matrix(matrix);
}

#pragma endregion
