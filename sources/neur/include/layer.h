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
#include <memory> // for auto_ptr
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

	void connectWithNextLayer(Layer&); /// makes connections between layers

	void propagateSignal() const; /// propagates signals from each neuron from this layer to every neuron connected to it
	void propagateLearningResponse() const; /// back propagates learning response from each neuron from this layer to every neuron connected to its input

	unsigned long getNeuronsNum() const throw() { return neurons_.size(); }

protected:
	std::list<std::auto_ptr<BaseNeuron> > neurons_; ///< list of pointers to neurons from this layer

template <typename LABEL>
friend class NeuralNetwork; /// giving direct access to members for the friend class
};

}; //namespace

#endif
