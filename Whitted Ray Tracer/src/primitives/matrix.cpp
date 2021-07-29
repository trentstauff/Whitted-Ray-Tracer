#include "matrix.h"

Matrix::Matrix()
{
	_rows = 4;
	_columns = 4;
	_matrix = new double[_rows * _columns];
}

Matrix::Matrix(int rows, int columns)
{
	_rows = rows;
	_columns = columns;
	_matrix = new double[_rows * _columns];
}

Matrix::~Matrix()
{
	delete[] _matrix;
}

int Matrix::rows() const
{
	return _rows;
}

int Matrix::columns() const
{
	return _columns;
}

double Matrix::get(int row, int column)
{
	assert(column < _columns);
	assert(column >= 0);
	assert(row >= 0);
	assert(row < _rows);
	
	return _matrix[column + _columns * row];
}

void Matrix::set(int row, int column, double val)
{
	assert(column < _columns);
	assert(column >= 0);
	assert(row >= 0);
	assert(row < _rows);
	
	_matrix[column + _columns * row] = val;
}

// passed array must be same size
void Matrix::set(double arr[]) const
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matrix[j + _rows*i] = arr[j + _rows * i];
		}
	}
}

int Matrix::idx(int row, int column) const
{
	return column + _columns * row;
}

double Matrix::operator()(int row, int column) const
{
	return _matrix[idx(row, column)];
}
