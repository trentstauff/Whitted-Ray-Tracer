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
	
	
}
