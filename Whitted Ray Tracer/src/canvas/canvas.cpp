#include "canvas.h"

Canvas::Canvas(const int width, const int height)
{
	_width = width;
	_height = height;

	// array of colour objects
	_canvas = new Colour[width * height];
}

Canvas::~Canvas()
{
	delete[] _canvas;
}

int Canvas::width() const
{
	return _width;
}

int Canvas::height() const
{
	return _height;
}

Colour Canvas::pixel(int x, int y)
{
	assert(x < _width);
	assert(x >= 0);
	assert(y >= 0);
	assert(y < _height);

	int index = x + _width * y;
	
	return _canvas[index];
}

void Canvas::write_pixel(int x, int y, Colour colour)
{
	const int index = x + _width * y;
	
	_canvas[index] = colour;
}

std::string Canvas::canvas_to_ppm()
{
	const std::string WHITESPACE = " \n\r\t\f\v";
	
	std::string ppm = "P3\n" + std::to_string(_width) + " " + std::to_string(_height) + "\n" + "255\n";

	for(int i = 0; i < _height; i++)
	{
		std::string row;
		int extra_lines = 0;
		
		for(int j = 0; j < _width; j++)
		{
			Colour x = pixel(j, i);
			std::string entry;

			// ensure values are inside range [0.0, 1.0]
			// multiplied by 255 as the max value a colour can be
			double r = std::min(x.r(), 1.0);
			int r_int = (int) std::round((std::max(r, 0.0) * 255));

			double g = std::min(x.g(), 1.0);
			int g_int = (int)std::round((std::max(g, 0.0) * 255));

			double b = std::min(x.b(), 1.0);
			int b_int = (int)std::round((std::max(b, 0.0) * 255));

			if(j == _width-1)
			{
				entry = std::to_string(r_int) + " " + std::to_string(g_int) + " " + std::to_string(b_int) + "\n";
			}
			else
			{
				entry = std::to_string(r_int) + " " + std::to_string(g_int) + " " + std::to_string(b_int) + " ";
			}

			// ensures that max length of a line in the PPM string is 70 characters long
			if((row.length() + entry.length()) - (70*extra_lines) > 70)
			{
				// trim any trailing whitespaces
				boost::algorithm::trim(row);
				row += "\n";
				row += entry;
				extra_lines += 1;
			}
			else
			{
				row += entry;
			}
		}
		
		ppm += row;
	}

	return ppm;
	
}

void Canvas::fill(Colour colour)
{
	for(int i = 0; i <_width*_height; i++)
	{
		_canvas[i] = colour;
	}
}
