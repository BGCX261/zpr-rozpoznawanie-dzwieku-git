/** 
* @file
* Declaration of NeuralNetwork class
*
* It represents whole neural network structure \n
* Provides interface to control the whole neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include <set>
#include <list>
#include <memory> // for auto_ptr
#include "layer.h"
#include "resultSet.h"

namespace neur /// neural network namespace
{

/// Class representing whole neural network structure
template <typename LABEL=std::string>
class NeuralNetwork
{
public:
	void initializeNetwork(unsigned long inputNeuronsNum, const std::auto_ptr< std::set<LABEL> >& outputCategories);	/// initializes neural network with given number of inputs and outputs as given categories

protected:
	std::list<std::auto_ptr<Layer> > layers_; ///< list of pointers to layers of the neural network
};

#include "neuralNetworkImpl.h"

} //namespace

#endif
