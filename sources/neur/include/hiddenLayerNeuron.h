/** 
* @file
* Declaration of HiddenLayerNeuron class
*
* Class representing a neuron in "hidden" layer of neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __HIDDEN_LAYER_NEURON_H__
#define __HIDDEN_LAYER_NEURON_H__

#include "baseNeuron.h"

namespace neur
{

/// Class representing a neuron in "hidden" layer of neural network
class HiddenLayerNeuron : public BaseNeuron
{
public:
	virtual ~HiddenLayerNeuron() /// destructor releases connections to another neurons
	{
		std::list< boost::shared_ptr<NeuronConnection> >::iterator iter;
		for (iter=backConnection_.begin(); iter!=backConnection_.end(); ++iter)
		{
			if (iter->get())
				iter->get()->right_ = NULL;
		}

		for (iter=frontConnection_.begin(); iter!=frontConnection_.end(); ++iter)
		{
			if (iter->get())
				iter->get()->left_ = NULL;
		}
	}

	virtual void propagateSignal() /// propagates signals to every connected neuron
	{
		std::list< boost::shared_ptr<NeuronConnection> >::iterator iter;
		for (iter=frontConnection_.begin(); iter!=frontConnection_.end();)
		{
			NeuronConnection* connPtr = iter->get();

			if (!connPtr || !connPtr->right_)
			{
				iter = frontConnection_.erase(iter);
				continue;
			}

			connPtr->right_->processInput((float)(getOutputValue() * connPtr->weight_));

			++iter;
		}
	}

	virtual void propagateLearningResponse(float learningFactor=0.1f) /// backpropagates learning signal to every connected neuron
	{
		std::list< boost::shared_ptr<NeuronConnection> >::iterator iter;
		for (iter=backConnection_.begin(); iter!=backConnection_.end();)
		{
			NeuronConnection* connPtr = iter->get();

			if (!connPtr || !connPtr->right_)
			{
				iter = backConnection_.erase(iter);
				continue;
			}

			double backpropagationOutput = getBackpropagationOutputValue();
			connPtr->right_->processLearningInput((float)(backpropagationOutput * connPtr->weight_));
			connPtr->weight_ += backpropagationOutput * learningFactor;

			++iter;
		}
	}

	virtual BaseNeuron* clone() const { return new HiddenLayerNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone
};

}; //namespace

#endif