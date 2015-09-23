#include <vector>
#include <string>
#include <logistic_regress.hpp>
#include <kadare/kadare.hpp>
#include <randompp/randompp.h>

std::vector<double> strVec2dVec(std::vector<std::string> &string_vector)
{
	std::vector<double> v(string_vector.size());
	for (int i=0; i<v.size(); ++i)
	{
		v[i] = std::stof(string_vector[i]);
	}
	return v;
}

int main (int argc, char* argv[])
{
	// data reader by kadare
	std::string data_dir = "example/data";
	std::string data_file = "arcene_train.data";
	kadare::DataManager data(data_dir, data_file);
	std::vector<double> target(data.getRecords());

	// define classifier
	int input_size = data.getKey_dim();
	double lr = 0.05;
	bool L2 = true;
	double regularization_rate = 0.001;
	rpp::Uniform<double> weight_initializer(-1., 1.);
	LogisticRegress classifier (input_size,
								 lr,
								 weight_initializer,
								 L2,
								 regularization_rate);

	// train
	for (int i=0; i<data.getRecords(); ++i)
	{
		double prob = classifier.predict();
	}
	return 0;
}
