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

namespace neur
{

/// Class representing single neuron object from neural network - from any layer
class BaseNeuron
{
public:
	BaseNeuron() : value_(0), learningValue_(0) {}
	virtual ~BaseNeuron() {}

	virtual void propagateSignal() const {} /// propagates signals to every connected neuron
	virtual void propagateLearningResponse() const {} /// back propagates learning response every connected neuron
	
	virtual void processInput(float value); /// processes input signal through neuron activation function changing it's value

	double getValue() const throw() { return value_; } /// returns neuron's value

	virtual BaseNeuron* clone() const { return new BaseNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone

protected:
	double value_; /// current state of neuron after stimulation from inputs
	double learningValue_; /// current neuron state of backpropagated learning info
};

}; //namespace

#endif