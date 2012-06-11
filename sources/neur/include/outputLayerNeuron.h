/** 
* @file
* Declaration of OutputLayerNeuron class
*
* Class representing a neuron in output layer of neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __OUTPUT_LAYER_NEURON_H__
#define __OUTPUT_LAYER_NEURON_H__

#include "baseNeuron.h"

namespace neur
{

/// Class representing a neuron in output layer of neural network
template <typename LABEL=std::string>
class OutputLayerNeuron : public BaseNeuron
{
public:
	OutputLayerNeuron() : desiredValue_(0) {};
	OutputLayerNeuron(const LABEL& category) : desiredValue_(0) { setCategory(category); }

	virtual ~OutputLayerNeuron() /// destructor releases connections to another neurons
	{
		std::list< boost::shared_ptr<NeuronConnection> >::iterator iter;
		for (iter=backConnection_.begin(); iter!=backConnection_.end(); ++iter)
		{
			if (iter->get())
				iter->get()->right_ = NULL;
		}
	}

	void	setCategory(const LABEL& category) throw() { category_ = category; } /// sets category assigned to the output
	LABEL	getCategory() const throw() { return category_; } /// returns category assigned to the output

	void	setDesiredValue(double desiredValue) throw() { desiredValue_ = desiredValue; } /// sets desired value for learning process
	double	getDesiredValue() const throw() { return desiredValue_; } /// returns desired value for learning process

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

			double backpropagationOutput = (desiredValue_ - value_)*(desiredValue_ - value_)/1000.0; /// output error value
			if (desiredValue_ < value_)
				backpropagationOutput *= -1;
			connPtr->right_->processLearningInput((float)(backpropagationOutput * connPtr->weight_));
			connPtr->weight_ += backpropagationOutput * learningFactor;

			++iter;
		}
	}

	virtual BaseNeuron* clone() const { return new OutputLayerNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone

protected:
	LABEL	category_; /// category assigned to the output
	double	desiredValue_; /// assigned desired value for learning process
};

}; //namespace

#endif