#include <gtest/gtest.h>
#include "../primitives/tuple.h"

namespace {
	TEST(TupleTest, PointInit) {

		auto tuple = Tuple(4.3, -4.2, 3.1, 1.0);

		EXPECT_DOUBLE_EQ(tuple.x(), 4.3);
		EXPECT_DOUBLE_EQ(tuple.y(), -4.2);
		EXPECT_DOUBLE_EQ(tuple.z(), 3.1);
		EXPECT_DOUBLE_EQ(tuple.w(), 1.0);

		EXPECT_TRUE(tuple.IsPoint());
		EXPECT_FALSE(tuple.IsVector());
	}

	TEST(TupleTest, VectorInit) {

		auto tuple = Tuple(4.3, -4.2, 3.1, 0.0);

		EXPECT_DOUBLE_EQ(tuple.x(), 4.3);
		EXPECT_DOUBLE_EQ(tuple.y(), -4.2);
		EXPECT_DOUBLE_EQ(tuple.z(), 3.1);
		EXPECT_DOUBLE_EQ(tuple.w(), 0.0);

		EXPECT_TRUE(tuple.IsVector());
		EXPECT_FALSE(tuple.IsPoint());
	}

	TEST(TupleTest, PointFunc) {

		auto point = Point(4.3, -4.2, 3.1);

		EXPECT_DOUBLE_EQ(point.x(), 4.3);
		EXPECT_DOUBLE_EQ(point.y(), -4.2);
		EXPECT_DOUBLE_EQ(point.z(), 3.1);
		EXPECT_DOUBLE_EQ(point.w(), 1.0);

		EXPECT_TRUE(point.IsPoint());
		EXPECT_FALSE(point.IsVector());
		
	}

	TEST(TupleTest, VectorFunc) {

		auto vector = Vector(4.3, -4.2, 3.1);

		EXPECT_DOUBLE_EQ(vector.x(), 4.3);
		EXPECT_DOUBLE_EQ(vector.y(), -4.2);
		EXPECT_DOUBLE_EQ(vector.z(), 3.1);
		EXPECT_DOUBLE_EQ(vector.w(), 0.0);

		EXPECT_TRUE(vector.IsVector());
		EXPECT_FALSE(vector.IsPoint());
	}

	TEST(TupleTest, Addition) {

		auto a = Tuple(3, -2, 5, 1);
		auto b = Tuple(-2, 3, 1, 0);

		// test overload on "+" operator
		auto c = a + b;
		
		EXPECT_DOUBLE_EQ(c.x(), 5);
		EXPECT_DOUBLE_EQ(c.y(), -1);
		EXPECT_DOUBLE_EQ(c.z(), 6);
		EXPECT_DOUBLE_EQ(c.w(), 1);
	}

	TEST(TupleTest, PointSubtraction) {

		auto a = Tuple(3, 2, 1, 1);
		auto b = Tuple(5, 6, 7, 1);

		// test overload on "-" operator
		auto c = a - b;

		EXPECT_DOUBLE_EQ(c.x(), -2);
		EXPECT_DOUBLE_EQ(c.y(), -4);
		EXPECT_DOUBLE_EQ(c.z(), -6);
		EXPECT_DOUBLE_EQ(c.w(), 0);

		EXPECT_TRUE(c.IsVector());
	}

	TEST(TupleTest, VectorPointSubtraction) {

		auto a = Tuple(3, 2, 1, 1);
		auto b = Tuple(5, 6, 7, 0);

		// test overload on "-" operator
		auto c = a - b;

		EXPECT_DOUBLE_EQ(c.x(), -2);
		EXPECT_DOUBLE_EQ(c.y(), -4);
		EXPECT_DOUBLE_EQ(c.z(), -6);
		EXPECT_DOUBLE_EQ(c.w(), 1);

		EXPECT_TRUE(c.IsPoint());
	}

	TEST(TupleTest, VectorSubtraction) {

		auto a = Tuple(3, 2, 1, 0);
		auto b = Tuple(5, 6, 7, 0);

		// test overload on "-" operator
		auto c = a - b;

		EXPECT_DOUBLE_EQ(c.x(), -2);
		EXPECT_DOUBLE_EQ(c.y(), -4);
		EXPECT_DOUBLE_EQ(c.z(), -6);
		EXPECT_DOUBLE_EQ(c.w(), 0);

		EXPECT_TRUE(c.IsVector());
	}
	
	
	
}

