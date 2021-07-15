#include "helpers.h"

bool fequals(const double a, const double b)
{
	if (std::abs(a - b) < EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}
}
