#ifndef INTERSECTION
#define INTERSECTION

#include <iostream>
#include "../helpers.h"

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

bool operator==(Intersection a, Intersection b);


#endif
