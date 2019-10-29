#include <stdio.h>
#include <float.h>

int main() {
	double dbl = DBL_MAX;
	dbl += dbl;

	printf("%f\n", dbl);

	return 0;
}
