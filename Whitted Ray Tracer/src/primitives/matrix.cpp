#include "matrix.h"

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
			_matrix[j + _rows * i] = a(i, j);
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
	
	return _matrix[column + _columns * row];
}

void Matrix::set(const int row, const int column, const double val) const
{
	assert(column < _columns);
	assert(column >= 0);
	assert(row >= 0);
	assert(row < _rows);
	
	_matrix[column + _columns * row] = val;
}

// passed array must be same size
void Matrix::set(const double arr[]) const
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matrix[j + _rows*i] = arr[j + _rows * i];
		}
	}
}

void Matrix::set() const
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			_matrix[j + _rows * i] = 0;
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
			std::cout << _matrix[j + _rows * i] << " ";
		}
		std::cout << "|" << std::endl;
	}
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
				// double comparison
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
