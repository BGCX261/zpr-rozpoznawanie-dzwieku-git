/** 
* @file
* Declaration of Layer class
*
* Class representing layer in a neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __LAYER_H__
#define __LAYER_H__

#include <list>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "baseNeuron.h"

namespace neur
{
/// Class representing layer in a neural network
class Layer
{
public:
	Layer() {}
	Layer(const BaseNeuron& neuronModel, unsigned long neuronsNum) { initialize(neuronModel, neuronsNum); } 

	void initialize(const BaseNeuron& neuronModel, unsigned long neuronsNum); /// creates layer with neuronsNum neurons same as neuronModel (copies)

	void connectWithNextLayer(Layer& nextLayer); /// makes connections between layers

	void resetNeuronsValue() throw(); /// zeroes neuron's value, so next iteration of signal propagation may be done

	void propagateSignal() const; /// propagates signals from each neuron from this layer to every neuron connected to it
	void propagateLearningResponse(float learningFactor=0.1f) const; /// back propagates learning response from each neuron from this layer to every neuron connected to its input

	unsigned long getNeuronsNum() const throw() { return neurons_.size(); }

protected:
	std::list< boost::shared_ptr<BaseNeuron> > neurons_; ///< list of pointers to neurons from this layer

template <typename LABEL>
friend class NeuralNetwork; /// giving direct access to members for the friend class
};

}; //namespace

#endif
