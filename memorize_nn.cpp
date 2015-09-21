#include <iostream>
#include <cstdio>
#include <cmath>

double sigmoid (double x)
{
	return 1. / (1+std::exp(-x));
}

double dsigmoid (double x)
{
	return (1 - x) * x;
}

void crateSigmoidTable (double *table, int n, int MAX_EXP)
{
	for (int i=0; i<n; ++i)
	{
		table[i] = sigmoid((i / n * 2 - 1) * MAX_EXP);
	}
}

int main (int argc, char* argv[])
{
	float f = 1.;
	double d = 1.;

	printf("f(%f): %x\n", f, f, f);
	printf("d(%lf): %x\n", d, d, d);
	return 0;
}
