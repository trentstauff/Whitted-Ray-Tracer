#include "./colour.h"

Colour::Colour(double red, double green, double blue)
{
	_r = red;
	_g = green;
	_b = blue;
}

double Colour::r() const
{
	return _r;
}

double Colour::g() const
{
	return _g;
}

double Colour::b() const
{
	return _b;
}
