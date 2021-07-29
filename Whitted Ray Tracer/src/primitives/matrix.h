#ifndef MATRIX
#define MATRIX

#include <cassert>

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

	int rows() const;
	int columns() const;

	double get(int row, int column);
	void set(int row, int column, double val);
	void set(const double arr[]) const;

	int idx(int row, int column) const;

	double operator()(int row, int col) const;
};


#endif
