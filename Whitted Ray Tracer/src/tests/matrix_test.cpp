#include <gtest/gtest.h>
#include "../primitives/matrix.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

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

		EXPECT_TRUE(submatrix == expected);

		// 4x4
		auto b = Matrix(4, 4);
		double arr3[] = { -6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1 };
		b.set(arr3);

		auto expected2 = Matrix(3, 3);
		double arr4[] = { -6, 1, 6, -8, 8, 6, -7, -1, 1 };
		expected2.set(arr4);

		auto submatrix2 = b.submatrix(2, 1);

		EXPECT_TRUE(submatrix2 == expected2);

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

	TEST(MatrixTest, Inverse1) {

		auto a = Matrix(4, 4);
		double arr[] = { -5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4 };
		a.set(arr);
		
		auto result = a.inverse();

		auto expected = Matrix(4, 4);
		double arr2[] = { 0.21805, 0.45113, 0.24060, -0.04511, -0.80827, -1.45677, -0.44361, 0.52068, -0.07895, -0.22368, -0.05263, 0.19737, -0.52256, -0.81391, -0.30075, 0.30639 };
		expected.set(arr2);

		EXPECT_TRUE(result == expected);
		
	}

	TEST(MatrixTest, Inverse2) {

		auto a = Matrix(4, 4);
		double arr[] = { 8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4 };
		a.set(arr);

		auto result = a.inverse();

		auto expected = Matrix(4, 4);
		double arr2[] = { -0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308, 0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231, -0.69231, -0.76923, -1.92308 };
		expected.set(arr2);
		
		EXPECT_TRUE(result == expected);

	}

	TEST(MatrixTest, Inverse3) {

		auto a = Matrix(4, 4);
		double arr[] = { 9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2 };
		a.set(arr);

		auto result = a.inverse();

		auto expected = Matrix(4, 4);
		double arr2[] = { -0.04074, -0.07778, 0.14444, -0.22222, -0.07778, 0.03333, 0.36667, -0.33333, -0.02901, -0.14630, -0.10926, 0.12963, 0.17778, 0.06667, -0.26667, 0.33333 };
		expected.set(arr2);

		EXPECT_TRUE(result == expected);

	}

	TEST(MatrixTest, MultProductByInverse) {

		auto a = Matrix(4, 4);
		double arr[] = { 3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1 };
		a.set(arr);

		auto b = Matrix(4, 4);
		double arr2[] = { 8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5 };
		b.set(arr2);

		auto c = a * b;

		auto d = c * b.inverse();
		
		EXPECT_TRUE(a == d);

	}

	TEST(MatrixTest, TranslationMatrixTimesPoint) {

		auto transform = TranslationMatrix(5, -3, 2);

		auto point = Point(-3, 4, 5);

		auto translated_point = transform * point;

		auto expected = Point(2, 1, 7);
		
		EXPECT_TRUE(translated_point == expected);

	}

	TEST(MatrixTest, InverseTranslationMatrixTimesPoint) {

		auto transform = TranslationMatrix(5, -3, 2).inverse();

		auto point = Point(-3, 4, 5);

		auto translated_point = transform * point;

		auto expected = Point(-8, 7, 3);

		EXPECT_TRUE(translated_point == expected);

	}

	TEST(MatrixTest, TranslationMatrixTimesVector) {

		auto transform = TranslationMatrix(5, -3, 2);

		auto vector = Vector(-3, 4, 5);

		auto same_vector = transform * vector;

		EXPECT_TRUE(vector == same_vector);

	}

	TEST(MatrixTest, ScalingMatrixTimesPoint) {

		auto transform = ScalingMatrix(2, 3, 4);

		auto point = Point(-4, 6, 8);

		auto scaled_point = transform * point;

		auto expected = Point(-8, 18, 32);

		EXPECT_TRUE(scaled_point == expected);

	}

	TEST(MatrixTest, ScalingMatrixTimesVector) {

		auto transform = ScalingMatrix(2, 3, 4);

		auto vector = Vector(-4, 6, 8);

		auto scaled_vector = transform * vector;

		auto expected = Vector(-8, 18, 32);

		EXPECT_TRUE(scaled_vector == expected);

	}

	TEST(MatrixTest, InverseScalingMatrixTimesVector) {

		auto transform = ScalingMatrix(2, 3, 4).inverse();

		auto vector = Vector(-4, 6, 8);

		auto scaled_vector = transform * vector;

		auto expected = Vector(-2, 2, 2);

		EXPECT_TRUE(scaled_vector == expected);

	}

	TEST(MatrixTest, RotatePointXAxis) {

		// eighth X rotation
		auto point = Point(0, 1, 0);
		
		auto eighth = RotateX(M_PI / 4);
		
		auto rotated_point = eighth * point;

		auto expected = Point(0, sqrt(2)/2, sqrt(2) / 2);

		EXPECT_TRUE(rotated_point == expected);

		// quarter X rotation
		auto quarter = RotateX(M_PI / 2);
		
		rotated_point = quarter * point;

		expected = Point(0, 0, 1);

		EXPECT_TRUE(rotated_point == expected);

		// inverse X rotation
		auto inverse_eighth = eighth.inverse();
		
		rotated_point = inverse_eighth * point;

		expected = Point(0, sqrt(2) / 2, -sqrt(2) / 2);

		EXPECT_TRUE(rotated_point == expected);

	}

	TEST(MatrixTest, RotatePointYAxis) {

		// eighth Y rotation
		auto point = Point(0, 0, 1);

		auto eighth = RotateY(M_PI / 4);

		auto rotated_point = eighth * point;

		auto expected = Point(sqrt(2) / 2, 0, sqrt(2) / 2);

		EXPECT_TRUE(rotated_point == expected);

		// quarter Y rotation
		auto quarter = RotateY(M_PI / 2);

		rotated_point = quarter * point;

		expected = Point(1, 0, 0);

		EXPECT_TRUE(rotated_point == expected);

	}

	TEST(MatrixTest, RotatePointZAxis) {

		// eighth Z rotation
		auto point = Point(0, 1, 0);

		auto eighth = RotateZ(M_PI / 4);

		auto rotated_point = eighth * point;

		auto expected = Point(-sqrt(2) / 2, sqrt(2) / 2, 0);

		EXPECT_TRUE(rotated_point == expected);

		// quarter Z rotation
		auto quarter = RotateZ(M_PI / 2);

		rotated_point = quarter * point;

		expected = Point(-1, 0, 0);

		EXPECT_TRUE(rotated_point == expected);

	}

	TEST(MatrixTest, ShearingPointXY) {

		auto point = Point(2, 3, 4);

		auto transform = ShearingMatrix(1, 0, 0, 0, 0, 0);

		auto sheared_point = transform * point;

		auto expected = Point(5, 3, 4);

		EXPECT_TRUE(sheared_point == expected);

	}

	TEST(MatrixTest, ShearingPointXZ) {

		auto point = Point(2, 3, 4);

		auto transform = ShearingMatrix(0, 1, 0, 0, 0, 0);

		auto sheared_point = transform * point;

		auto expected = Point(6, 3, 4);

		EXPECT_TRUE(sheared_point == expected);

	}

	TEST(MatrixTest, ShearingPointYX) {

		auto point = Point(2, 3, 4);

		auto transform = ShearingMatrix(0, 0, 1, 0, 0, 0);

		auto sheared_point = transform * point;

		auto expected = Point(2, 5, 4);

		EXPECT_TRUE(sheared_point == expected);

	}

	TEST(MatrixTest, ShearingPointYZ) {

		auto point = Point(2, 3, 4);

		auto transform = ShearingMatrix(0, 0, 0, 1, 0, 0);

		auto sheared_point = transform * point;

		auto expected = Point(2, 7, 4);

		EXPECT_TRUE(sheared_point == expected);

	}

	TEST(MatrixTest, ShearingPointZX) {

		auto point = Point(2, 3, 4);

		auto transform = ShearingMatrix(0, 0, 0, 0, 1, 0);

		auto sheared_point = transform * point;

		auto expected = Point(2, 3, 6);

		EXPECT_TRUE(sheared_point == expected);

	}

	TEST(MatrixTest, ShearingPointZY) {

		auto point = Point(2, 3, 4);

		auto transform = ShearingMatrix(0, 0, 0, 0, 0, 1);

		auto sheared_point = transform * point;

		auto expected = Point(2, 3, 7);

		EXPECT_TRUE(sheared_point == expected);

	}
	
}
