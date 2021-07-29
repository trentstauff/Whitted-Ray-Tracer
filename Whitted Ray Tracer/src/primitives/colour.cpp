#include "./colour.h"

#include "../helpers.h"

Colour::Colour()
{
	_r = 0;
	_g = 0;
	_b = 0;
}

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

Colour operator*(Colour a, Colour b)
{
	return Colour(a.r() * b.r(), a.g() * b.g(), a.b() * b.b());
}

bool operator==(Colour a, Colour b)
{
	return fequals(a.r(), b.r()) && fequals(a.g(), b.g()) && fequals(a.b(), b.b());
}
