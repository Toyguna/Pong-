#include "Include.h"

// funcs
bool int_range(int value, int min, int max)
{
	if (value >= min && value <= max)
	{
		return true;
	}

	return false;
}

bool float_range(float value, float min, float max)
{
	if (value >= min && value <= max)
	{
		return true;
	}

	return false;
}
