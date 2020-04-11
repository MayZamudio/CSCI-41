#include "imagine.h"
#include <cmath>

Imagine::Imagine() {
	real = 3;
	imaginate = 4;
}

int Imagine::distance() {
	return hypot(real, imaginate);
}
