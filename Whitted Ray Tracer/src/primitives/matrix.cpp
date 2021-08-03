#include "matrix.h"

#include <string>

Matrix::Matrix()
{
	_rows = 4;
	_columns = 4;
	_matrix = new double[_rows * _columns];
	set();
}

Matrix::Matrix(int rows, int columns)
{
	_rows = rows;
	_columns = columns;
	_matrix = new double[_rows * _columns];
	set();
}

// copy constructor used to assign Matrix objects being returned to desired variable,
// meaning that we don't double delete the object as it goes out of function scope,
// and then execution scope where it is returned
Matrix::Matrix(const Matrix& a)
{
	_rows = a.rows();
	_columns = a.columns();
	_matrix = new double[_rows * _columns];
	
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matrix[idx(i, j)] = a(i, j);
		}
	}
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

double Matrix::get(const int row, const int column) const
{
	assert(column < _columns);
	assert(column >= 0);
	assert(row >= 0);
	assert(row < _rows);
	
	return _matrix[idx(row, column)];
}

void Matrix::set(const int row, const int column, const double val) const
{
	assert(column < _columns);
	assert(column >= 0);
	assert(row >= 0);
	assert(row < _rows);
	
	_matrix[idx(row, column)] = val;
}

// passed array must be same size
void Matrix::set(const double arr[]) const
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matrix[idx(i, j)] = arr[idx(i, j)];
		}
	}
}

void Matrix::set() const
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matrix[idx(i,j)] = 0;
		}
	}
}

int Matrix::idx(const int row, const int column) const
{
	return column + _columns * row;
}

void Matrix::print() const
{
	for (int i = 0; i < _rows; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < _columns; j++)
		{
			std::cout << _matrix[idx(i, j)] << " ";
		}
		std::cout << "|" << std::endl;
	}
}

double Matrix::determinant()
{
	assert(_rows == _columns);
	
	if(_rows == 2)
	{
		return _matrix[idx(0, 0)] * _matrix[idx(1, 1)] - _matrix[idx(0, 1)] * _matrix[idx(1, 0)];
	}
	else
	{
		auto determinant = 0.0;

		// https://people.richland.edu/james/lecture/m116/matrices/determinant.html
		// Here are the steps to go through to find the determinant.
		// Pick any row or column in the matrix.It does not matter which row or which column you use, the answer will be the same for any row.
		// There are some rows or columns that are easier than others, but we'll get to that later.
		// Multiply every element in that row or column by its cofactor and add.The result is the determinant.
		
		for(int j = 0; j < _columns; j++)
		{
			determinant += _matrix[idx(0, j)] * cofactor(0, j);
		}

		return determinant;
	}
}

Matrix Matrix::submatrix(int row, int column)
{
	assert(_rows > 1 && _columns > 1);
	assert(row < _rows && column < _columns);
	assert(row >= 0 && column >= 0);

	Matrix result = Matrix(_rows - 1, _columns - 1);

	int roffset = 0;
	int coffset = 0;
	
	for (int i = 0; i < _rows; i++)
	{
		// reset column offset at the beginning of each row
		coffset = 0;
		
		if(i != row)
		{
			for (int j = 0; j < _columns; j++)
			{
				if(j != column)
				{
					result.set(i - roffset, j - coffset, _matrix[idx(i, j)]);
				}
				else
				{
					coffset = 1;
				}
			}
		} else
		{
			roffset = 1;
		}
	}
	
	return result;
}

double Matrix::minor(int row, int column)
{
	assert(_rows == _columns);
	
	auto sub = submatrix(row, column);
	auto det = sub.determinant();
	return det;
	
}

double Matrix::cofactor(int row, int column)
{
	double cofactor = minor(row, column);

	// if row + column is odd, we negate the sign of the cofactor
	if(row + column % 2 != 0)
	{
		cofactor *= -1;
	}

	return cofactor;
}

Matrix Matrix::inverse()
{
	assert(fequals(determinant(), 0));

	
	
}

Matrix Matrix::transpose()
{
	Matrix result = Matrix(_columns, _rows);

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			result.set(j, i, _matrix[idx(i, j)]);
		}
	}
	return result;
}

Matrix IdentityMatrix(const int dim)
{
	auto identity = Matrix(dim, dim);

	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			if (i == j) identity.set(i, j, 1);
		}
	}

	return identity;
}

double Matrix::operator()(const int row, const int column) const
{
	return _matrix[idx(row, column)];
}

bool operator==(Matrix& a, Matrix& b)
{
	if(a.rows() != b.rows() && a.columns() != b.columns())
	{
		return false;
	}
	else
	{
		for (auto i = 0; i < a.rows(); i++)
		{
			for (auto j = 0; j < b.columns(); j++)
			{
				
				if(!fequals(a(i,j), b(i,j)))
				{
					return false;
				}
			}
		}
		
		return true;
	}
}

Matrix operator*(Matrix& a, Matrix& b)
{
	assert(a.columns() == b.rows());

	Matrix result = Matrix(a.rows(), b.columns());

	for (auto row = 0; row < a.rows(); row++)
	{
		for (auto col = 0; col < b.columns(); col++)
		{
			auto entry = 0.0;
			
			for(auto x = 0; x < a.columns(); x++)
			{
				entry += a(row, x) * b(x, col);
			}
			result.set(row, col, entry);
		}
	}

	return result;
}

Tuple operator*(Matrix& a, Tuple& b)
{
	assert(a.columns() == 4);

	Matrix tuple = Matrix(4, 1);

	tuple.set(0, 0, b.x());
	tuple.set(1, 0, b.y());
	tuple.set(2, 0, b.z());
	tuple.set(3, 0, b.w());

	auto result = a * tuple;

	assert(result.columns() == 1);
	assert(result.rows() == 4);

	auto temp = Tuple(result(0, 0), result(1, 0), result(2, 0), result(3, 0));

	return temp;
	
}
