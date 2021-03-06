#ifndef MATRIX
#define MATRIX
#define _USE_MATH_DEFINES

#include <cassert>
#include <iostream>
#include <math.h>
#include "../helpers.h"
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

	// inversion functions
	double determinant();
	Matrix submatrix(int row, int column);
	double minor(int row, int column);
	double cofactor(int row, int column);
	Matrix inverse();

	Matrix transpose();

	double operator()(int row, int column) const;
};

Matrix IdentityMatrix(int dim);
Matrix TranslationMatrix(double x, double y, double z);
Matrix ScalingMatrix(double x, double y, double z);
Matrix RotateX(double rad);
Matrix RotateY(double rad);
Matrix RotateZ(double rad);
Matrix ShearingMatrix(double xy, double xx, double yx, double yz, double zx, double zy);

bool operator==(Matrix& a, Matrix& b);
Matrix operator*(Matrix& a, Matrix& b);
Tuple operator*(Matrix& a, Tuple& b);
Matrix operator/(Matrix& a, double scalar);

#endif
