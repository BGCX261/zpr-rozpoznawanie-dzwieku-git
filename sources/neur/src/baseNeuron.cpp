/** 
* @file
* Implementation of Layer class
* 
* It represents layer in a neural network
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "baseNeuron.h"
#include <math.h>

using namespace neur;


void BaseNeuron::processInput(float inputValue)
{
	value_ += inputValue;
}


void BaseNeuron::processLearningInput(float inputValue)
{
	learningValue_ += inputValue;
}


double BaseNeuron::getOutputValue() const throw()
{
	/// sigmoidal function
	return 2 / (1 + exp(-value_)) - 1;
}


double BaseNeuron::getBackpropagationOutputValue() const throw()
{
	/// derivative sigmoidal function
	double y = 1 / (1 + exp(-learningValue_));
	return 2 * y * (1-y);
}
