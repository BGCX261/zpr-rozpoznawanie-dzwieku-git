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
	void propagateSignal() const; /// propagates signals from each neuron from this layer to every neuron connected to it
	void propagateLearningResponse() const; /// back propagates learning response from each neuron from this layer to every neuron connected to its input

protected:
	std::list<std::auto_ptr<BaseNeuron> >	neurons_; ///< list of pointers to neurons from this layer
};

}; //namespace

#endif
