#include <gtest/gtest.h>
#include "../canvas/canvas.h"

#include <iostream>

namespace {

	TEST(CanvasTest, Init) {

		auto canvas = Canvas(10, 20);

		EXPECT_EQ(canvas.width(), 10);
		EXPECT_EQ(canvas.height(), 20);

		// ensures entire canvas is initialized to black
		for(int i = 0; i < canvas.width(); i++)
		{
			for(int j = 0; j < canvas.height(); j++)
			{
				EXPECT_TRUE(canvas.pixel(i,j) == Colour(0,0,0));
			}
		}
	}

	TEST(CanvasTest, WritePixel) {

		auto canvas = Canvas(10, 20);

		const auto red = Colour(1, 0, 0);

		canvas.write_pixel(2, 3, red);

		EXPECT_TRUE(canvas.pixel(2, 3) == red);
	}

	TEST(CanvasTest, ToPPM) {

		auto canvas = Canvas(5, 3);

		canvas.write_pixel(0, 0, Colour(1.5, 0, 0));
		canvas.write_pixel(2, 1, Colour(0, 0.5, 0));
		canvas.write_pixel(4, 2, Colour(-0.5, 0, 1));

		const auto ppm = canvas.canvas_to_ppm();
		
		const std::string expected = "P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
		
		EXPECT_EQ(ppm.compare(expected), 0);
	}

	TEST(CanvasTest, PPM70LineLimit) {

		auto canvas = Canvas(10, 2);

		canvas.fill(Colour(1, 0.8, 0.6));
		
		const auto ppm = canvas.canvas_to_ppm();

		const std::string expected = "P3\n10 2\n255\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153\n";

		EXPECT_EQ(ppm.compare(expected), 0);
	}
	
}
