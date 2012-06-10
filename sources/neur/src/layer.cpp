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


void Layer::initialize(const BaseNeuron& neuronModel, unsigned long neuronsNum)
{
	neurons_.clear();

	for (unsigned long i=0; i<neuronsNum; ++i)
		neurons_.push_back(std::auto_ptr<BaseNeuron>(neuronModel.clone()));
}


void Layer::connectWithNextLayer(Layer&)
{

}


void Layer::propagateSignal() const
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::propagateSignal, _1));
}


void Layer::propagateLearningResponse() const
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::propagateLearningResponse, _1));
}