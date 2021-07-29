#include <gtest/gtest.h>
#include "../primitives/tuple.h"

namespace {
	TEST(TupleTest, PointInit) {

		auto tuple = Tuple(4.3, -4.2, 3.1, 1.0);

		EXPECT_DOUBLE_EQ(tuple.x(), 4.3);
		EXPECT_DOUBLE_EQ(tuple.y(), -4.2);
		EXPECT_DOUBLE_EQ(tuple.z(), 3.1);
		EXPECT_DOUBLE_EQ(tuple.w(), 1.0);

		EXPECT_TRUE(tuple.is_point());
		EXPECT_FALSE(tuple.is_vector());
	}

	TEST(TupleTest, VectorInit) {

		auto tuple = Tuple(4.3, -4.2, 3.1, 0.0);

		EXPECT_DOUBLE_EQ(tuple.x(), 4.3);
		EXPECT_DOUBLE_EQ(tuple.y(), -4.2);
		EXPECT_DOUBLE_EQ(tuple.z(), 3.1);
		EXPECT_DOUBLE_EQ(tuple.w(), 0.0);

		EXPECT_TRUE(tuple.is_vector());
		EXPECT_FALSE(tuple.is_point());
	}

	TEST(TupleTest, PointFunc) {

		auto point = Point(4.3, -4.2, 3.1);

		EXPECT_DOUBLE_EQ(point.x(), 4.3);
		EXPECT_DOUBLE_EQ(point.y(), -4.2);
		EXPECT_DOUBLE_EQ(point.z(), 3.1);
		EXPECT_DOUBLE_EQ(point.w(), 1.0);

		EXPECT_TRUE(point.is_point());
		EXPECT_FALSE(point.is_vector());
		
	}

	TEST(TupleTest, VectorFunc) {

		auto vector = Vector(4.3, -4.2, 3.1);

		EXPECT_DOUBLE_EQ(vector.x(), 4.3);
		EXPECT_DOUBLE_EQ(vector.y(), -4.2);
		EXPECT_DOUBLE_EQ(vector.z(), 3.1);
		EXPECT_DOUBLE_EQ(vector.w(), 0.0);

		EXPECT_TRUE(vector.is_vector());
		EXPECT_FALSE(vector.is_point());
	}

	TEST(TupleTest, Addition) {

		auto a = Tuple(3, -2, 5, 1);
		auto b = Tuple(-2, 3, 1, 0);

		// test overload on "+" operator
		auto c = a + b;
		
		EXPECT_DOUBLE_EQ(c.x(), 1);
		EXPECT_DOUBLE_EQ(c.y(), 1);
		EXPECT_DOUBLE_EQ(c.z(), 6);
		EXPECT_DOUBLE_EQ(c.w(), 1);
	}

	TEST(TupleTest, PointSubtraction) {

		auto a = Point(3, 2, 1);
		auto b = Point(5, 6, 7);

		// test overload on "-" operator
		auto c = a - b;

		EXPECT_DOUBLE_EQ(c.x(), -2);
		EXPECT_DOUBLE_EQ(c.y(), -4);
		EXPECT_DOUBLE_EQ(c.z(), -6);
		EXPECT_DOUBLE_EQ(c.w(), 0);

		EXPECT_TRUE(c.is_vector());
	}

	TEST(TupleTest, VectorPointSubtraction) {

		auto a = Point(3, 2, 1);
		auto b = Vector(5, 6, 7);

		// test overload on "-" operator
		auto c = a - b;

		EXPECT_DOUBLE_EQ(c.x(), -2);
		EXPECT_DOUBLE_EQ(c.y(), -4);
		EXPECT_DOUBLE_EQ(c.z(), -6);
		EXPECT_DOUBLE_EQ(c.w(), 1);

		EXPECT_TRUE(c.is_point());
	}

	TEST(TupleTest, VectorSubtraction) {

		auto a = Vector(3, 2, 1);
		auto b = Vector(5, 6, 7);

		// test overload on "-" operator
		auto c = a - b;

		EXPECT_DOUBLE_EQ(c.x(), -2);
		EXPECT_DOUBLE_EQ(c.y(), -4);
		EXPECT_DOUBLE_EQ(c.z(), -6);
		EXPECT_DOUBLE_EQ(c.w(), 0);

		EXPECT_TRUE(c.is_vector());
	}

	TEST(TupleTest, VectorNegation) {

		auto a = Vector(1, -2, 3);

		auto b = -a;

		EXPECT_DOUBLE_EQ(b.x(), -1);
		EXPECT_DOUBLE_EQ(b.y(), 2);
		EXPECT_DOUBLE_EQ(b.z(), -3);
		EXPECT_DOUBLE_EQ(b.w(), 0);

		EXPECT_TRUE(b.is_vector());
	}

	TEST(TupleTest, VectorScalarScaling) {

		auto a = Vector(1, -2, 3);

		auto b = a*3.5;

		EXPECT_DOUBLE_EQ(b.x(), 3.5);
		EXPECT_DOUBLE_EQ(b.y(), -7);
		EXPECT_DOUBLE_EQ(b.z(), 10.5);
		EXPECT_DOUBLE_EQ(b.w(), 0);

		EXPECT_TRUE(b.is_vector());
	}

	TEST(TupleTest, VectorFractionScaling) {

		auto a = Vector(1, -2, 3);

		auto b = a * 0.5;

		EXPECT_DOUBLE_EQ(b.x(), 0.5);
		EXPECT_DOUBLE_EQ(b.y(), -1);
		EXPECT_DOUBLE_EQ(b.z(), 1.5);
		EXPECT_DOUBLE_EQ(b.w(), 0);

		EXPECT_TRUE(b.is_vector());
	}

	TEST(TupleTest, VectorDivision) {

		auto a = Vector(1, -2, 3);

		auto b = a / 2;

		EXPECT_DOUBLE_EQ(b.x(), 0.5);
		EXPECT_DOUBLE_EQ(b.y(), -1);
		EXPECT_DOUBLE_EQ(b.z(), 1.5);
		EXPECT_DOUBLE_EQ(b.w(), 0);

		EXPECT_TRUE(b.is_vector());
	}

	TEST(TupleTest, VectorMagnitude) {

		auto a = Vector(1, 0, 0);
		auto b = Vector(0, 1, 0);
		auto c = Vector(0, 0, 1);
		auto d = Vector(1, 2, 3);
		auto e = Vector(-1, -2, -3);

		auto magnitude = Magnitude(a);
		EXPECT_DOUBLE_EQ(magnitude, 1);

		magnitude = Magnitude(b);
		EXPECT_DOUBLE_EQ(magnitude, 1);

		magnitude = Magnitude(c);
		EXPECT_DOUBLE_EQ(magnitude, 1);

		magnitude = Magnitude(d);
		EXPECT_DOUBLE_EQ(magnitude, std::sqrt(14));

		magnitude = Magnitude(e);
		EXPECT_DOUBLE_EQ(magnitude, std::sqrt(14));
	}

	TEST(TupleTest, VectorNormalization) {
		
		auto a = Vector(4, 0, 0);

		auto b = Normalize(a);

		EXPECT_DOUBLE_EQ(b.x(), 1);
		EXPECT_DOUBLE_EQ(b.y(), 0);
		EXPECT_DOUBLE_EQ(b.z(), 0);

		EXPECT_DOUBLE_EQ(Magnitude(b), 1);

		EXPECT_TRUE(b.is_vector());

		a = Vector(1, 2, 3);

		b = Normalize(a);

		EXPECT_DOUBLE_EQ(b.x(), 1 / std::sqrt(14));
		EXPECT_DOUBLE_EQ(b.y(), 2 / std::sqrt(14));
		EXPECT_DOUBLE_EQ(b.z(), 3 / std::sqrt(14));

		EXPECT_DOUBLE_EQ(Magnitude(b), 1);

		EXPECT_TRUE(b.is_vector());
		
	}

	TEST(TupleTest, DotProduct) {
		
		const auto a = Vector(1, 2, 3);

		const auto b = Vector(2, 3, 4);

		const auto dot_product = DotProduct(a, b);
		
		EXPECT_DOUBLE_EQ(dot_product, 20);
	}

	TEST(TupleTest, CrossProduct) {

		const auto a = Vector(1, 2, 3);

		const auto b = Vector(2, 3, 4);

		// a x b
		auto cross_product = CrossProduct(a, b);
		EXPECT_TRUE(cross_product==Vector(-1, 2, -1));

		// b x a
		cross_product = CrossProduct(b, a);
		EXPECT_TRUE(cross_product == Vector(1, -2, 1));
	}
	
	
	
}

