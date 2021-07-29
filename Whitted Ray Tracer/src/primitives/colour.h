#ifndef COLOUR
#define COLOUR

#include <cmath>

class Colour
{
private:
	double _r;
	double _g;
	double _b;

public:
	Colour(double red, double green, double blue);
	~Colour() = default;

	double r() const;
	double g() const;
	double b() const;
};

#endif