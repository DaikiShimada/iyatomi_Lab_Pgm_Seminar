#ifndef KANTOKU_LOGISTIC_REGRESS
#define KANTOKU_LOGISTIC_REGRESS

class LogisticRegress
{
	public:
		LogisticRegress();
		LogisticRegress(const LogisticRegress &obj);
		~LogisticRegress();
		
		double lr;	// learning rate
		double regularization_rate;	// regularization rate

		double predict();
	private:
		int SIGMOID_TABLE_SIZE;
		double SIGMOID_MAX;
		double *SIGMOID_TABLE;
		double *weight;

		void initSigmoidTable();
		double sigmoid(double x);
		double dsigmoid(double fx);
};

#endif
