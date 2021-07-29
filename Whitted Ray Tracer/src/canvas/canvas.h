#ifndef CANVAS
#define CANVAS

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "../primitives/colour.h"

class Canvas
{
private:
	int _width;
	int _height;
	Colour* _canvas;

public:
	Canvas(int width, int height);
	~Canvas();

	int width() const;
	int height() const;

	Colour pixel(int x, int y);
	void write_pixel(int x, int y, Colour colour);
	std::string canvas_to_ppm();
	void fill(Colour colour);
	void save();
	
};
#endif
