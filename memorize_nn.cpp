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

void initSigmoidTable (double *table, int n, double MAX_SIGMOID)
{
	// x = [-MAX_SIGMOID, +MAX_SIGMOID]のsigmoid(x)をn個計算
	for (int i=0; i<n; ++i)
	{
		table[i] = sigmoid((i / (double)n * 2 - 1) * MAX_SIGMOID);
	}
}

int main (int argc, char* argv[])
{
	// pre-computing sigmoid finction
	int SIGMOID_TABLE_SIZE = 1000;
	double MAX_SIGMOID = 6.;
	double *SIGMOID_TABLE;
	SIGMOID_TABLE = new double[SIGMOID_TABLE_SIZE];
	initSigmoidTable(SIGMOID_TABLE, SIGMOID_TABLE_SIZE, MAX_SIGMOID);
	
	/* OUTPUT SIGMOID_TABLE
	for (int i=0; i<SIGMOID_TABLE_SIZE; ++i)
	{
		std::cout << SIGMOID_TABLE[i] << std::endl;
	}
	*/
	delete[] SIGMOID_TABLE;
	return 0;
}
