#ifndef COLOUR
#define COLOUR

class Colour
{
private:
	double _r;
	double _g;
	double _b;

public:
	Colour();
	Colour(double red, double green, double blue);
	~Colour() = default;

	double r() const;
	double g() const;
	double b() const;
};

Colour operator+(Colour a, Colour b);
Colour operator-(Colour a, Colour b);
Colour operator*(Colour a, double factor);
Colour operator*(Colour a, Colour b);
bool operator==(Colour a, Colour b);

#endif