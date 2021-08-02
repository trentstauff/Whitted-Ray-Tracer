#ifndef MATRIX
#define MATRIX

#include <cassert>
#include "../helpers.h"
#include <iostream>
#include "./tuple.h"

class Matrix
{
private:
	int _rows;
	int _columns;
	double* _matrix;

public:
	Matrix();
	Matrix(int rows, int columns);

	// copy constructor
	Matrix(const Matrix& a);
	
	~Matrix();

	int rows() const;
	int columns() const;

	double get(int row, int column) const;

	// three sets: one for individual indices,
	// one for copying of passed array,
	// one for initializing entire matrix to 0
	void set(int row, int column, double val) const;
	void set(const double arr[]) const;
	void set() const;

	int idx(int row, int column) const;

	void print() const;

	double operator()(int row, int column) const;
};

bool operator==(Matrix& a, Matrix& b);
Matrix operator*(Matrix& a, Matrix& b);
Tuple operator*(Matrix& a, Tuple& b);

#endif
