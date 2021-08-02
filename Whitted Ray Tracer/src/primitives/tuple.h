#ifndef TUPLE
#define TUPLE

#include <cmath>
#include <iostream>

class Tuple
{
private:
	double _x;
	double _y;
	double _z;
	double _w;
	
public:
	Tuple(double x, double y, double z, double w);
	~Tuple() = default;

	double x() const;
	double y() const;
	double z() const;
	double w() const;

	bool is_vector() const;
	bool is_point() const;

	void print();
	
};

Tuple Point(double x, double y, double z);
Tuple Vector(double x, double y, double z);

double Magnitude(Tuple a);
Tuple Normalize(Tuple a);
double DotProduct(Tuple a, Tuple b);
Tuple CrossProduct(Tuple a, Tuple b);

// operator overloading
Tuple operator+(Tuple a, Tuple b);
Tuple operator-(Tuple a, Tuple b);
Tuple operator-(Tuple a);
Tuple operator*(Tuple a, double factor);
Tuple operator/(Tuple a, double factor);
bool operator==(Tuple a, Tuple b);

#endif