#include "intersections.h"

Intersections::Intersections(std::vector<Intersection> intersections)
{
	_intersections = intersections;
}

std::vector<Intersection> Intersections::intersections()
{
	return _intersections;
}

// utilizing std::optional, this function can return either the first ray hit, or, effectively nullptr.
std::optional<Intersection> Intersections::hit()
{
	
	std::optional<Intersection> hit = std::nullopt;
	
	for(auto& intersection : _intersections)
	{
		
		if ((intersection.t() < 0)) continue;
		else if(hit == std::nullopt || intersection.t() < hit.value().t())
		{
			hit = std::optional<Intersection>(intersection);
		}
	}
	
	return hit;
}

int Intersections::size()
{
	return _intersections.size();
}

Intersection Intersections::operator[](int x)
{
	return _intersections[x];
}
