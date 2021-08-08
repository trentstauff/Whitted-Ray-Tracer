#include "ray.h"

Ray::Ray(Tuple origin, Tuple direction)
{
	assert(origin.w() == 1.0);
	assert(direction.w() == 0.0);
	
	_origin = origin;
	_direction = direction;
}

// where the ray starts
Tuple Ray::origin()
{
	return _origin;
}

// the direction vector of the ray
Tuple Ray::direction()
{
	return _direction;
}

// the location of the ray after t seconds
Tuple Ray::position(double t)
{
	return _origin + (_direction * t);
}