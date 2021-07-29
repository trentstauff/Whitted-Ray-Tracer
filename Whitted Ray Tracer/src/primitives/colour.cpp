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

Colour operator+(Colour a, Colour b)
{
	return Colour(a.r() + b.r(), a.g() + b.g(), a.b() + b.b());
}

Colour operator-(Colour a, Colour b)
{
	return Colour(a.r() - b.r(), a.g() - b.g(), a.b() - b.b());
}

Colour operator*(Colour a, double factor)
{
	return Colour(a.r() * factor, a.g() * factor, a.b() * factor);
}
