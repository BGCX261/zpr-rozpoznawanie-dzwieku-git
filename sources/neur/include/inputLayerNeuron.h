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
	virtual BaseNeuron* clone() const { return new InputLayerNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone
};

}; //namespace

#endif