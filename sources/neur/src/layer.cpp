/** 
* @file
* Implementation of BaseNeuron class
* 
* It represents single neuron object from neural network - from any layer
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include <boost/bind.hpp>
#include "layer.h"

using namespace neur;
using namespace std;


void Layer::propagateSignal() const
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::propagateSignal, _1));
}

void Layer::propagateLearningResponse() const
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::propagateLearningResponse, _1));
}