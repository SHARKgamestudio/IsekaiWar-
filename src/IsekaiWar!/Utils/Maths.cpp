#include "Maths.h"

#pragma region External Dependencies

#include <corecrt_math.h>

#pragma endregion

float Maths::Round(float value, int decimals) {
	float factor = pow(10, decimals);
	return roundf(value * factor) / factor;
}