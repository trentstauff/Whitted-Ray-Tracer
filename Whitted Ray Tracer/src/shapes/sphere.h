#ifndef SPHERE
#define  SPHERE
#include "../primitives/tuple.h"
#include <vector>

#include "../primitives/ray.h"
#include "../primitives/intersections.h"

class Sphere
{

private:
	
	Tuple _origin = Point(0, 0, 0);
	double _radius = 1.0;

public:
	
	Sphere() = default;
	~Sphere() = default;
	
};

Intersections intersection(Sphere* s, Ray ray);

#endif