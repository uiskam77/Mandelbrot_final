#pragma once

#include <stdexcept>
/**
przeskalowuje wartoœci
*/

inline double map(double value, double in_min, double in_max, double out_min, double out_max)
{
	if (in_max - in_min == 0)
	{
		throw std::runtime_error("Unexpected error: Dividing by 0.");
	}
	return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}