#include <gtest/gtest.h>
#include "../primitives/matrix.h"
#include <iostream>

namespace {

	TEST(MatrixTest, Init) {
		
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
}
