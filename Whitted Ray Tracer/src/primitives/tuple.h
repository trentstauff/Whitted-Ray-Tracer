#ifndef TUPLE
#define TUPLE

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

	bool IsVector() const;
	bool IsPoint() const;
	
};

Tuple Point(double x, double y, double z);
Tuple Vector(double x, double y, double z);

// operator overloading
Tuple operator+(Tuple a, Tuple b);
Tuple operator-(Tuple a, Tuple b);
Tuple operator*(Tuple a, double factor);
Tuple operator/(Tuple a, double factor);
bool operator==(Tuple a, Tuple b);


#endif