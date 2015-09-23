#include <iostream>
#include <cmath>
#include <cblas.h>
#include "logistic_regress.hpp"

LogisticRegress::LogisticRegress()
{
	// default parameters
	lr = 0.05;
	regularization_rate = 0.001;
	input_size = 1;
	weight = new double[input_size];
	output = 0.;
	L2 = true;

	// init SIGMOID TABLE
	SIGMOID_TABLE_SIZE = 1000;
	SIGMOID_MAX = 6.;
	SIGMOID_TABLE = new double[SIGMOID_TABLE_SIZE];
	initSigmoidTable();
}


LogisticRegress::LogisticRegress(int input_size,
								 double lr,
								 rpp::Random<double> &initializer,
								 bool L2,
								 double regularization_rate,
								 int SIGMOID_TABLE_SIZE,
								 double SIGMOID_MAX)
{
	this->input_size = input_size;
	this->lr = lr;
	this->L2 = L2;
	this->regularization_rate = regularization_rate;
	this->SIGMOID_TABLE_SIZE = SIGMOID_TABLE_SIZE;
	this->SIGMOID_MAX = SIGMOID_MAX;
	this->SIGMOID_TABLE = new double[SIGMOID_TABLE_SIZE];
	initSigmoidTable();

	this->output = 0.;
	this->weight = new double[input_size];
	for (int i=0; i<input_size; ++i)
	{
		this->weight[i] = initializer.random();
	}
}


LogisticRegress::LogisticRegress(const LogisticRegress &obj)
{
	this->lr = obj.lr;
	this->regularization_rate = obj.regularization_rate;
	this->input_size = obj.input_size;
	this->weight = new double[this->input_size];
	for (int i=0; i<this->input_size; ++i)
	{
		this->weight[i] = obj.weight[i];
	}
	this->output = obj.output;
	this->L2 = obj.L2;

	this->SIGMOID_TABLE_SIZE = obj.SIGMOID_TABLE_SIZE;
	this->SIGMOID_MAX = obj.SIGMOID_MAX;
	this->SIGMOID_TABLE = new double[this->SIGMOID_TABLE_SIZE];
	this->initSigmoidTable();
}


LogisticRegress::~LogisticRegress()
{
	delete[] SIGMOID_TABLE;
	delete[] weight;
}


double LogisticRegress::predict(std::vector<double>& input)
{
	output = cblas_ddot(input_size,
					   weight,
					   1,
					   input.data(),
					   1);
	output = SIGMOID_TABLE[(int)((output + SIGMOID_MAX) * (SIGMOID_TABLE_SIZE / SIGMOID_MAX / 2))];
	return output;
}


double LogisticRegress::update(std::vector<double>& input, double target)
{
	double *weight_diff = new double[input_size];
	double weight_old_norm = cblas_dnrm2(input_size, weight, 1);
	for (int i=0; i<input_size; i++)
	{
		weight_diff[i] = weight[i];

		// calc update weight
		weight[i] = L2 ? weight[i] - regularization_rate * weight[i] : weight[i];
		weight[i] += lr * (target - output) * input[i];

		weight_diff[i] -= weight[i];
	}
	
	double diff = cblas_dnrm2(input_size, weight_diff, 1) / weight_old_norm;

	delete[] weight_diff;
	return diff;
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
