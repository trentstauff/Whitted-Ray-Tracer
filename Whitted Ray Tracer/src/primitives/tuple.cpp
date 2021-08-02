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

bool Tuple::is_point() const
{
	return _w == 1.0;
}

void Tuple::print()
{
	std::cout << "(" << _x << " " << _y << " " << _z << " " << _w << ")" << std::endl;
}

bool Tuple::is_vector() const
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

double Magnitude(Tuple a)
{
	return std::sqrt(a.x() * a.x() + a.y() * a.y() + a.z() * a.z());
}

Tuple Normalize(Tuple a)
{
	const auto factor = 1 / Magnitude(a);

	const auto normalized = a * factor;

	return normalized;
}

double DotProduct(Tuple a, Tuple b)
{
	return a.x() * b.x() + a.y() * b.y() + a.z() * b.z() + a.w() * b.w();
}

Tuple CrossProduct(Tuple a, Tuple b)
{
	auto x = a.y() * b.z() - a.z() * b.y();
	auto y = a.z() * b.x() - a.x() * b.z();
	auto z = a.x() * b.y() - a.y() * b.x();

	return Tuple(x, y, z, 0);
}

// operator overloads
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

Tuple operator-(Tuple a)
{
	return Tuple(-1*a.x(), -1*a.y(), -1*a.z(), a.w());
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



