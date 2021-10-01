#pragma once

#include <iostream>

namespace matrix
{
	class Size
	{
	public:
		explicit Size(const unsigned int height = 0, const unsigned int width = 0)
			: height_(height), width_(width) {}

		[[ nodiscard ]] unsigned int height() const
		{
			return height_;
		}
		[[ nodiscard ]] unsigned int width() const
		{
			return width_;
		}
	private:
		unsigned int height_;
		unsigned int width_;
	};
	class Matrix  // NOLINT(cppcoreguidelines-special-member-functions)
	{
	public:
		explicit Matrix(const unsigned int height = 0, const unsigned int width = 0, int** int_array = nullptr)
			: height_(height), width_(width), representation_(nullptr)
		{
			copy_representation(int_array);
		}
		explicit Matrix(const Size size, int** int_array = nullptr)
			: height_(size.height()), width_(size.width()), representation_(nullptr)
		{
			copy_representation(int_array);
		}
		Matrix(const Matrix& matrix)
			: height_(matrix.height_), width_(matrix.width_), representation_(nullptr)
		{
			copy_representation(matrix.representation_);
		}
		~Matrix() { delete_representation(); }


		//Initialize matrix with zeros and ones
		Matrix& operator= (int);
		//Get string from the index
		std::string operator[] (unsigned int) const;
		//Initialize matrix with matrix
		Matrix& operator() (const Matrix&);
		//Initialize matrix with value
		Matrix& operator() (unsigned int, int);
		// Reverse all negative values and assign
		Matrix& operator++ ();
		// Assign and reverse all negative values
		Matrix& operator++ (int);
		//Sum's of matrices
		int operator+ (const Matrix&) const;
		int operator- (const Matrix&) const;
		//Quantity of elements exploration:
		bool operator> (const Matrix&) const;
		bool operator< (const Matrix&) const;
		bool operator== (const Matrix&) const;


		// Reverse all values and assign
		friend Matrix& operator-- (Matrix&);
		// Assign and reverse all values
		friend Matrix& operator-- (Matrix&, int);
		// Smart pow
		friend Matrix& operator+ (Matrix&, double);
		// Smart root
		friend Matrix& operator- (Matrix&, double);
		//Sum comparison
		friend bool operator> (const Matrix&, int);
		friend bool operator< (const Matrix&, int);
		friend bool operator== (const Matrix&, int);
		//Average comparison
		friend bool operator> (const Matrix&, double);
		friend bool operator< (const Matrix&, double);
		friend bool operator== (const Matrix&, double);
		//Output
		friend std::ostream& operator<<(const std::ostream&, const Matrix&);


		explicit operator bool() const;
		explicit operator unsigned int() const;
		explicit operator int() const;
		explicit operator double() const;
		explicit operator matrix::Size () const;


		//Transpose of a matrix (it's transposition)
		[[ nodiscard ]] Matrix& transpose();
	private:
		unsigned int height_;
		unsigned int width_;
		int** representation_;
		inline static Matrix* temp_ = nullptr;
		
		[[ nodiscard ]] unsigned int height() const;
		[[ nodiscard ]] unsigned int width() const;
		[[ nodiscard ]] unsigned int area() const;
		[[ nodiscard ]] int sum() const;
		[[ nodiscard ]] double average() const;

		void copy_representation(int**);
		void delete_representation();
		void copy_fields(const Matrix&);
		void pow_for_each(double) const;

		static void push_temp(const Matrix&);
	};


	// Reverse all values and assign
	Matrix& operator-- (Matrix&);
	// Assign and reverse all values
	Matrix& operator-- (Matrix&, int);
	// Smart pow
	Matrix& operator+ (Matrix&, double);
	// Smart root
	Matrix& operator- (Matrix&, double);
	//Sum comparison
	bool operator> (const Matrix&, int);
	bool operator< (const Matrix&, int);
	bool operator== (const Matrix&, int);
	//Average comparison
	bool operator> (const Matrix&, double);
	bool operator< (const Matrix&, double);
	bool operator== (const Matrix&, double);
	//Output
	std::ostream& operator<<(const std::ostream&, const Matrix&);
}
