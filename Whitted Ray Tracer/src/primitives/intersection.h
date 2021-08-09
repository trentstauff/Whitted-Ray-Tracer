#ifndef INTERSECTION
#define INTERSECTION

#include <iostream>

class Intersection
{
private:
	double _t;
	void* _object;

public:

	Intersection(double t, void* object);

	void print();
	
	double t();
	void* object();

};

#endif
