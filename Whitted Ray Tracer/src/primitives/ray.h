#ifndef RAY
#define RAY

#include "./tuple.h"
#include <cassert>

class Ray
{
private:
	Tuple _origin = Tuple(0,0,0,0);
	Tuple _direction = Tuple(0, 0, 0, 0);

public:
	Ray(Tuple origin, Tuple direction);
	~Ray() = default;

	Tuple origin();
	Tuple direction();

	Tuple position(double t);
	
};
#endif
