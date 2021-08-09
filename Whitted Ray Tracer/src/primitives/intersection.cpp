#include "./intersection.h"

Intersection::Intersection(double t, const void* object)
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

const void* Intersection::object()
{
	return _object;
}
