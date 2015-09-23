#ifndef KANTOKU_LOGISTIC_REGRESS
#define KANTOKU_LOGISTIC_REGRESS

#include <vector>
#include <randompp/randompp.h>

class LogisticRegress
{
	public:
		LogisticRegress();
		LogisticRegress(int input_size, 
						double lr, 
						rpp::Random<double> &initializer,
						bool L2=true, 
						double regularization_rate=0.001,
						int SIGMOID_TABLE_SIZE=1000,
						double SIGMOID_MAX=6.);
		LogisticRegress(const LogisticRegress &obj);
		~LogisticRegress();
		
		double lr;	// learning rate
		double regularization_rate;	// regularization rate

		double predict(std::vector<double> &input);
		double update(std::vector<double> &input, double target);

	private:
		int SIGMOID_TABLE_SIZE;
		double SIGMOID_MAX;
		double *SIGMOID_TABLE;
		int input_size;
		double *weight;
		double output;
		bool L2;

		void initSigmoidTable();
		double sigmoid(double x);
};

#endif
