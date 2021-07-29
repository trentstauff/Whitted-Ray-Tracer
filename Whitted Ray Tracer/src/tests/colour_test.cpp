#include <gtest/gtest.h>
#include "../primitives/colour.h"

namespace {
	TEST(ColourTest, Init) {

		auto colour = Colour(-0.5, 0.4, 1.7);

		EXPECT_DOUBLE_EQ(colour.r(), -0.5);
		EXPECT_DOUBLE_EQ(colour.g(), 0.4);
		EXPECT_DOUBLE_EQ(colour.b(), 1.7);
	}
}

