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
#include <stdexcept>
#include "layer.h"

using namespace neur;
using namespace std;


void Layer::initialize(const BaseNeuron& neuronModel, unsigned long neuronsNum)
{
	neurons_.clear();

	for (unsigned long i=0; i<neuronsNum; ++i)
		neurons_.push_back(boost::shared_ptr<BaseNeuron>(neuronModel.clone()));
}


void Layer::connectWithNextLayer(Layer& nextLayer)
{
	std::list< boost::shared_ptr<BaseNeuron> >::iterator left_layer_iter;
	for (left_layer_iter=neurons_.begin(); left_layer_iter!=neurons_.end(); ++left_layer_iter)
	{
		BaseNeuron* leftLayerNeuron = left_layer_iter->get();
		if (!leftLayerNeuron)
			throw std::runtime_error("Missing neuron");

		leftLayerNeuron->frontConnection_.clear();

		std::list< boost::shared_ptr<BaseNeuron> >::iterator right_layer_iter;
		for (right_layer_iter=nextLayer.neurons_.begin(); right_layer_iter!=nextLayer.neurons_.end(); ++right_layer_iter)
		{
			BaseNeuron* rightLayerNeuron = right_layer_iter->get();
			if (!rightLayerNeuron)
				throw std::runtime_error("Missing neuron");
	
			boost::shared_ptr<NeuronConnection> newConnection(new NeuronConnection);
			newConnection->left_ = leftLayerNeuron;
			newConnection->right_ = rightLayerNeuron;
			
			leftLayerNeuron->frontConnection_.push_back(newConnection);
			rightLayerNeuron->backConnection_.push_back(newConnection);
		}
	}
}


void Layer::resetNeuronsValue() throw()
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::resetValue, _1));
}


void Layer::propagateSignal() const
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::propagateSignal, _1));
}


void Layer::propagateLearningResponse(float learningFactor) const
{
	for_each(neurons_.begin(), neurons_.end(), boost::bind(&BaseNeuron::propagateLearningResponse, _1, learningFactor));
}
