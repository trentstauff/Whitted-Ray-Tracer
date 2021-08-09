#ifndef INTERSECTION
#define INTERSECTION

#include <iostream>

class Intersection
{
private:
	double _t;
	const void* _object;

public:

	Intersection(double t, const void* object);

	void print();
	
	double t();
	const void* object();

};

#endif
