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
	virtual BaseNeuron* clone() const { return new HiddenLayerNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone
};

}; //namespace

#endif