/** 
* @file
* Declaration of InputLayerNeuron class
*
* Class representing a neuron in input layer of neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __INPUT_LAYER_NEURON_H__
#define __INPUT_LAYER_NEURON_H__

#include "baseNeuron.h"

namespace neur
{

/// Class representing a neuron in input layer of neural network
class InputLayerNeuron : public BaseNeuron
{
public:
	virtual ~InputLayerNeuron() /// destructor releases connections to another neurons
	{
		std::list< boost::shared_ptr<NeuronConnection> >::iterator iter;
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
	
	virtual BaseNeuron* clone() const { return new InputLayerNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone
};

}; //namespace

#endif