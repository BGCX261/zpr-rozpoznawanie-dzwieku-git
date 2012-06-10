/** 
* @file
* Declaration of BaseNeuron class
*
* It represents single neuron object from neural network - from any layer
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __BASE_NEURON_H__
#define __BASE_NEURON_H__

#include <boost/smart_ptr/shared_ptr.hpp>
#include <list>
#include "neuronConnection.h"

namespace neur
{

/// Class representing single neuron object from neural network - from any layer
class BaseNeuron
{
public:
	BaseNeuron() : value_(0), learningValue_(0) {}
	virtual ~BaseNeuron() {}

	virtual void propagateSignal() {} /// propagates signals to every connected neuron
	virtual void propagateLearningResponse(float learningFactor=0.1f) {} /// back propagates learning response every connected neuron
	
	virtual void processInput(float inputValue); /// processes input signal changing neuron's internal value
	virtual void processLearningInput(float inputValue); /// processes backpropagated learning input signal changing neuron's internal value

	void	resetValue() throw() { value_ = 0; } /// zeroes neuron's value, so next iteration of signal propagation may be done
	double	getValue() const throw() { return value_; } /// returns neuron's value

	virtual double getOutputValue() const throw(); /// returns output value, based on output activation function
	virtual double getBackpropagationOutputValue() const throw(); /// returns output value for learning process, based on reverse output activation function

	virtual BaseNeuron* clone() const { return new BaseNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone

protected:
	double value_; /// current state of neuron after stimulation from inputs
	double learningValue_; /// current neuron state of backpropagated learning info

	std::list< boost::shared_ptr<NeuronConnection> > backConnection_; /// shared connection to the neurouns from layer closer to the input
	std::list< boost::shared_ptr<NeuronConnection> > frontConnection_; /// shared connection to the neurouns from layer closer to the output

friend class Layer;
};

}; //namespace

#endif