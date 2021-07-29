#ifndef MATRIX
#define MATRIX

class Matrix
{
private:
	int _rows;
	int _columns;
	double* _matrix{};

public:
	Matrix();
	Matrix(int rows, int columns);
	~Matrix();
	
};
#endif
