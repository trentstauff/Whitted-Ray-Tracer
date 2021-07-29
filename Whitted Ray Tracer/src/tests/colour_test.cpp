#include <gtest/gtest.h>
#include "../primitives/colour.h"

namespace {
	
	TEST(ColourTest, Init) {

		auto colour = Colour(-0.5, 0.4, 1.7);

		EXPECT_DOUBLE_EQ(colour.r(), -0.5);
		EXPECT_DOUBLE_EQ(colour.g(), 0.4);
		EXPECT_DOUBLE_EQ(colour.b(), 1.7);
	}

	TEST(ColourTest, Addition) {
		
		const auto a = Colour(0.9, 0.6, 0.75);
		const auto b = Colour(0.7, 0.1, 0.25);

		const auto c = a + b;
		
		EXPECT_DOUBLE_EQ(c.r(), 1.6);
		EXPECT_DOUBLE_EQ(c.g(), 0.7);
		EXPECT_DOUBLE_EQ(c.b(), 1.0);
	}

	TEST(ColourTest, Subtraction) {
		
		const auto a = Colour(0.9, 0.6, 0.75);
		const auto b = Colour(0.7, 0.1, 0.25);

		const auto c = a - b;

		EXPECT_DOUBLE_EQ(c.r(), 0.2);
		EXPECT_DOUBLE_EQ(c.g(), 0.5);
		EXPECT_DOUBLE_EQ(c.b(), 0.5);
	}

	TEST(ColourTest, ScalarMultiplication) {
		
		const auto a = Colour(0.2, 0.3, 0.4);

		const auto b = a * 2;

		EXPECT_DOUBLE_EQ(b.r(), 0.4);
		EXPECT_DOUBLE_EQ(b.g(), 0.6);
		EXPECT_DOUBLE_EQ(b.b(), 0.8);
	}

	TEST(ColourTest, ColourMultiplication) {

		const auto a = Colour(1, 0.2, 0.4);
		const auto b = Colour(0.9, 1, 0.1);

		const auto c = a * b;

		EXPECT_DOUBLE_EQ(c.r(), 0.9);
		EXPECT_DOUBLE_EQ(c.g(), 0.2);
		EXPECT_DOUBLE_EQ(c.b(), 0.04);
	}
}

