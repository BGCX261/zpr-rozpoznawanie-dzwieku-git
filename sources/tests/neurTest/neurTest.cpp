// generating main function
#define BOOST_TEST_MAIN

#ifndef _WIN32
// enabling dynamic linking
#define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>
#include <string>
#include <stdexcept>
#include "neuralNetwork.h"

using namespace neur;
using namespace boost::unit_test;
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_SUITE(neural_network_test)

BOOST_AUTO_TEST_CASE(test_default_initialization)
{
	NeuralNetwork<std::string> neur;
	float expected = 0.1f;
	BOOST_CHECK_EQUAL(neur.getLearningFactor(), expected);
}

BOOST_AUTO_TEST_CASE(test_set_factor)
{
	NeuralNetwork<std::string> neur;
    float default_val = 0.1f;
	float previous = neur.getLearningFactor();
    BOOST_CHECK_EQUAL(previous, default_val);
	float next = 2.5f;
	neur.setLearningFactor(next);
	BOOST_CHECK_EQUAL(neur.getLearningFactor(), next);
}

BOOST_AUTO_TEST_CASE(test_initialize_network)
{
	NeuralNetwork<std::string> neur;
	unsigned long inputNeuronsNum = 3;
	std::vector<unsigned long> hiddenLayersNeuronNums;
	for (unsigned long i = 5; i < 11; ++i)
		hiddenLayersNeuronNums.push_back(i);

	const std::auto_ptr< std::set<std::string> > outputCategories(new std::set<std::string>);
	outputCategories->insert("ABC");
	outputCategories->insert("NBA");
	outputCategories->insert("ZPR");
	outputCategories->insert("FBI");
	BOOST_CHECK_NO_THROW(neur.initializeNetwork(inputNeuronsNum, hiddenLayersNeuronNums, outputCategories));
}

// to easily run test from exe file
#ifdef _WIN32
BOOST_AUTO_TEST_CASE(wait)
{
	std::cout << std::endl;
	system("PAUSE");
}
#endif

BOOST_AUTO_TEST_SUITE_END()
