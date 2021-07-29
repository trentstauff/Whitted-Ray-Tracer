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
	
}
