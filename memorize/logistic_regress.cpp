#include <cmath>
#include "logistic_regress.hpp"

LogisticRegress::LogisticRegress()
{
	// default parameters
	lr = 0.05;
	regularization_rate = 0.001;

	// init SIGMOID TABLE
	SIGMOID_TABLE_SIZE = 1000;
	SIGMOID_MAX = 6.;
	SIGMOID_TABLE = new double[SIGMOID_TABLE_SIZE];
	initSigmoidTable();

}


LogisticRegress::LogisticRegress(const LogisticRegress &obj)
{
	this->lr = obj.lr;
	this->regularization_rate = obj.regularization_rate;

	this->SIGMOID_TABLE_SIZE = obj.SIGMOID_TABLE_SIZE;
}

LogisticRegress::~LogisticRegress()
{
	delete[] SIGMOID_TABLE;
	delete[] weight;
}


// pre-computing sigmoid finction
void LogisticRegress::initSigmoidTable()
{
	for (int i=0; i<SIGMOID_TABLE_SIZE; ++i)
	{
		SIGMOID_TABLE[i] = sigmoid((i / (double)SIGMOID_TABLE_SIZE * 2 - 1) * SIGMOID_MAX);		
	}
}


double LogisticRegress::sigmoid(double x)
{
	return 1. / (1. + std::exp(-x));
}


double LogisticRegress::dsigmoid(double fx)
{
	return (1 - fx) * fx;
}
