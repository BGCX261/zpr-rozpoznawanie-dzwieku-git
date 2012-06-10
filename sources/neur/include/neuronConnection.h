/** 
* @file
* Declaration of NeuronConnection class
*
* It represents shared connection between two neurons
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __NEURON_CONNECTION_H__
#define __NEURON_CONNECTION_H__

#include "baseNeuron.h"

namespace neur
{
	class BaseNeuron;
	
/// Class representing shared connection between two neurons
class NeuronConnection
{
public:
	NeuronConnection() : left_(NULL), right_(NULL), weight_(0.0) {}

	BaseNeuron* left_; /// pointer to the neuron on the left of the connecton
	BaseNeuron* right_; /// pointer to the neuron on the right of the connecton

	double weight_; /// weight assigned to connection
};

}; //namespace

#endif
