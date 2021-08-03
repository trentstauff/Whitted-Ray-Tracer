#include <gtest/gtest.h>
#include "../primitives/matrix.h"
#include <iostream>

namespace {

	TEST(MatrixTest, Init4x4) {
		
		const auto matrix = Matrix(4, 4);

		double arr[] = { 1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 13.5, 14.5, 15.5, 16.5 };
		
		matrix.set(arr);
		
		EXPECT_EQ(matrix.rows(), 4);
		EXPECT_EQ(matrix.columns(), 4);
		
		EXPECT_DOUBLE_EQ(matrix(0, 0), 1);
		EXPECT_DOUBLE_EQ(matrix(1, 0), 5.5);
		EXPECT_DOUBLE_EQ(matrix(1, 2), 7.5);
		EXPECT_DOUBLE_EQ(matrix(2, 2), 11);
		EXPECT_DOUBLE_EQ(matrix(3, 0), 13.5);
		EXPECT_DOUBLE_EQ(matrix(3, 2), 15.5);
		
	}

	TEST(MatrixTest, Init2x2) {

		const auto matrix = Matrix(2, 2);

		double arr[] = { -3, 5, 1, -2 };

		matrix.set(arr);

		EXPECT_EQ(matrix.rows(), 2);
		EXPECT_EQ(matrix.columns(), 2);

		EXPECT_DOUBLE_EQ(matrix(0, 0), -3);
		EXPECT_DOUBLE_EQ(matrix(0, 1), 5);
		EXPECT_DOUBLE_EQ(matrix(1, 0), 1);
		EXPECT_DOUBLE_EQ(matrix(1, 1), -2);

	}

	TEST(MatrixTest, Init3x3) {

		const auto matrix = Matrix(3, 3);

		double arr[] = { -3, 5, 0, 1, -2, -7, 0, 1, 1 };

		matrix.set(arr);

		EXPECT_EQ(matrix.rows(), 3);
		EXPECT_EQ(matrix.columns(), 3);

		EXPECT_DOUBLE_EQ(matrix(0, 0), -3);
		EXPECT_DOUBLE_EQ(matrix(1, 1), -2);
		EXPECT_DOUBLE_EQ(matrix(2, 2), 1);

	}

	TEST(MatrixTest, MatrixValueComparison) {
		
		auto a = Matrix(4, 4);
		auto b = Matrix(4, 4);

		double arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2 };
		double arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2 };
		a.set(arr);
		b.set(arr2);
		
		// expect equal
		EXPECT_TRUE(a == b);
		
		b.set(0,0,99);

		// expect not equal
		EXPECT_FALSE(a == b);

	}

	TEST(MatrixTest, MatrixMultiplication) {

		auto a = Matrix(4, 4);
		auto b = Matrix(4, 4);

		double arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2 };
		double arr2[] = { -2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8 };
		a.set(arr);
		b.set(arr2);

		double expected[] = { 20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42 };

		auto c = Matrix(4, 4);
		c.set(expected);

		EXPECT_TRUE((a*b) == c);

	}

	TEST(MatrixTest, MatrixTupleMultiplication) {

		auto a = Matrix(4, 4);
		auto b = Tuple(1, 2, 3, 1);

		double arr[] = { 1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1 };
		a.set(arr);

		auto expected = Tuple(18,24,33,1);

		auto result = a * b;

		EXPECT_TRUE(result == expected);

	}

	TEST(MatrixTest, IdentityMatrix) {

		auto a = Matrix(4, 4);

		double arr[] = { 0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32 };
		a.set(arr);

		auto result = a * IdentityMatrix(4);

		EXPECT_TRUE(result == a);

	}

	TEST(MatrixTest, Transpose) {

		auto a = Matrix(4, 4);

		double arr[] = { 0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8 };
		a.set(arr);

		auto result = a.transpose();

		auto expected = Matrix(4,4);
		double arr2[] = { 0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8 };
		expected.set(arr2);

		EXPECT_TRUE(result == expected);

	}

	TEST(MatrixTest, IdentityTranspose) {

		auto a = IdentityMatrix(4);

		EXPECT_TRUE(a == a.transpose());

	}

	TEST(MatrixTest, Determinant2x2) {

		auto a = Matrix(2, 2);
		double arr[] = { 1, 5, -3, 2 };
		a.set(arr);

		auto determinant = a.determinant();
		
		EXPECT_TRUE(fequals(determinant, 17));

	}

	TEST(MatrixTest, Determinant3x3) {

		auto a = Matrix(3, 3);
		double arr[] = { 1, 2, 6, -5, 8, -4, 2, 6, 4 };
		a.set(arr);

		auto determinant = a.determinant();

		EXPECT_TRUE(fequals(determinant, -196));

	}

	TEST(MatrixTest, Determinant4x4) {

		auto a = Matrix(4, 4);
		double arr[] = { -2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9 };
		a.set(arr);

		auto determinant = a.determinant();

		EXPECT_TRUE(fequals(determinant, -4071));

	}
	
	TEST(MatrixTest, Submatrix) {

		// 3x3
		auto a = Matrix(3, 3);
		double arr[] = { 1, 5, 0, -3, 2, 7, 0, 6, -3 };
		a.set(arr);

		auto expected = Matrix(2, 2);
		double arr2[] = { -3, 2, 0, 6 };
		expected.set(arr2);
		
		auto submatrix = a.submatrix(0,2);

		EXPECT_TRUE(expected == submatrix);

		// 4x4
		auto b = Matrix(4, 4);
		double arr3[] = { -6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1 };
		b.set(arr3);

		auto expected2 = Matrix(3, 3);
		double arr4[] = { -6, 1, 6, -8, 8, 6, -7, -1, 1 };
		expected2.set(arr4);

		auto submatrix2 = b.submatrix(2, 1);

		EXPECT_TRUE(expected2 == submatrix2);

	}

	TEST(MatrixTest, Minor3x3) {

		auto a = Matrix(3, 3);
		double arr[] = { 3, 5, 0, 2, -1, -7, 6, -1, 5 };
		a.set(arr);

		auto minor = a.minor(1, 0);

		EXPECT_TRUE(fequals(minor, 25));

	}

	TEST(MatrixTest, Cofactor) {

		auto a = Matrix(3, 3);
		double arr[] = { 3, 5, 0, 2, -1, -7, 6, -1, 5 };
		a.set(arr);

		auto cofactor = a.cofactor(0, 0);

		EXPECT_TRUE(fequals(cofactor, -12));

		cofactor = a.cofactor(1, 0);

		EXPECT_TRUE(fequals(cofactor, -25));

	}
	
	
}
