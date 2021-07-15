#include "./tuple.h"
#include "../helpers.h"

Tuple::Tuple(const double x, const double y, const double z, const double w)
{
	_x = x;
	_y = y;
	_z = z;
	_w = w;
}

double Tuple::x() const
{
	return _x;
}

double Tuple::y() const
{
	return _y;
}

double Tuple::z() const
{
	return _z;
}

double Tuple::w() const
{
	return _w;
}

bool Tuple::IsPoint() const
{
	return _w == 1.0;
}

bool Tuple::IsVector() const
{
	return _w == 0.0;
}

Tuple Point(const double x, const double y, const double z)
{
	return Tuple(x, y, z, 1.0);
}

Tuple Vector(const double x, const double y, const double z)
{
	return Tuple(x, y, z, 0.0);
}

Tuple operator+(Tuple a, Tuple b)
{
	const auto x = a.x() + b.x();
	const auto y = a.y() + b.y();
	const auto z = a.z() + b.z();
	const auto w = a.w() + b.w();

	return Tuple(x, y, z, w);
}

Tuple operator-(Tuple a, Tuple b)
{
	const auto x = a.x() - b.x();
	const auto y = a.y() - b.y();
	const auto z = a.z() - b.z();
	const auto w = a.w() - b.w();

	return Tuple(x, y, z, w);
}

Tuple operator*(Tuple a, double factor)
{
	const auto x = a.x() * factor;
	const auto y = a.y() * factor;
	const auto z = a.z() * factor;
	const auto w = a.w() * factor;

	return Tuple(x, y, z, w);
}

Tuple operator/(Tuple a, double factor)
{

	const auto x = a.x() / factor;
	const auto y = a.y() / factor;
	const auto z = a.z() / factor;
	const auto w = a.w() / factor;

	return Tuple(x, y, z, w);
}

bool operator==(Tuple a, Tuple b)
{
	return fequals(a.x(), b.x()) && fequals(a.y(), b.y()) && fequals(a.z(), b.z()) && fequals(a.w(), b.w());
}



