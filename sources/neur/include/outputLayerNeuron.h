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
	OutputLayerNeuron() {};
	OutputLayerNeuron(const LABEL& category) { setCategory(category); }

	void	setCategory(const LABEL& category) throw() { category_ = category; }
	LABEL	getCategory() const throw() { return category_; }

	virtual BaseNeuron* clone() const { return new OutputLayerNeuron(*this); } /// clones neuron. Caller is responsible for destruction of the clone

protected:
	LABEL category_;
};

}; //namespace

#endif