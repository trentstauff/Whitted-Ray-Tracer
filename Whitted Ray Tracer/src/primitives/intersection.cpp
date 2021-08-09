#include "./intersection.h"

Intersection::Intersection(double t, void* object)
{
	_t = t;
	_object = object;
}

void Intersection::print()
{
	std::cout << "Intersection(" << _t << ", " << _object << ")" << std::endl;
}

double Intersection::t()
{
	return _t;
}

void* Intersection::object()
{
	return _object;
}
