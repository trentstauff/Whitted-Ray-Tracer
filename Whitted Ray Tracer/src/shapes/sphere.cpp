#include "sphere.h"

// utilizes the discriminant calculation to determine if Line-Sphere intersection occurs
// Possible TODO:
// Tuple sphere_to_ray = ray.origin() - Point(0, 0, 0); ---> Change the second value to the center of the sphere
// double c = DotProduct(sphere_to_ray, sphere_to_ray) - 1; ---> - 1 may need to be radius of sphere squared
// https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
// see link above for calculations and formulas
std::vector<double> Sphere::intersection(Ray ray)
{
	// vector from sphere's center to the ray's origin
	Tuple sphere_to_ray = ray.origin() - Point(0, 0, 0);

	double a = DotProduct(ray.direction(), ray.direction());
	double b = 2 * DotProduct(ray.direction(), sphere_to_ray);
	double c = DotProduct(sphere_to_ray, sphere_to_ray) - 1;

	double discriminant = pow(b, 2) - (4 * a * c);

	std::vector<double> vector;
	
	if(discriminant < 0)
	{
		return vector;
	}
	else
	{
		double t1 = (-b - sqrt(discriminant)) / (2 * a);
		double t2 = (-b + sqrt(discriminant)) / (2 * a);
		
		vector.push_back(t1);
		vector.push_back(t2);

		return vector;
	}
}
