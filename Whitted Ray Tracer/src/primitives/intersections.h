#ifndef INTERSECTIONS
#define INTERSECTIONS

#include <vector>
#include <optional>
#include "./intersection.h"

class Intersections
{
private:
	std::vector<Intersection> _intersections;

public:

	Intersections(std::vector<Intersection> intersections);

	std::vector<Intersection> intersections();
	std::optional<Intersection> hit();

	int size();
	Intersection operator[](int x);
	
};
#endif
